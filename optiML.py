# optiML.py - search space for best estimator and features.

import pandas as pd
from sklearn.model_selection import train_test_split

from common import cli, utils
from dae import *
from lib.ext.estimators import Estimator
from lib.ext.pipes import Pipe, ClassifierPipes
from lib.ext.scoring import Score, score_predict, save_score, load_report


SEED=42
TEST_SIZE=0.2
cv=3

DATA = 'data/'
DOMAIN='hackles'
DATA_DIR = DATA + DOMAIN
TRAIN_TEST = '/train_test'
TRAIN_TEST_SET = DATA_DIR + TRAIN_TEST


DAE_MODE = 'predict_score'


def dae_score_predict(model, params, report, dataset, testset):
    """ Score and predict full test set """
    target_names = utils.get_dir_list(TRAIN_TEST_SET)
    score = score_predict(model, testset)
    save_score(report, params['model_id'], params['est'], len(dataset), len(testset), params['num_feats'], cv, score, 'predict_score')


# @TODO: Make this a class. (Also, clean up dae.py.)
def search_space(avail_feats, dataset, testset):
    params = {}

    # Please don't run preprocessors on test or validation sets. Thanks.
    X_train, X_test, y_train, y_test = train_test_split(dataset, dataset['target'], test_size=TEST_SIZE, random_state=SEED)

    # reduce dev time
    dataset=dataset.head(100)
    testset=testset.head(100)

    for ffs in feature_space_generator(avail_feats):
        Est = Estimator()

        estimator = (next(Est))

        while estimator is not None:
            try:
                est = estimator
                estimator = (next(Est))
            except Exception as e:
                print('StopIteration caught', e)

            pipe = Pipe()

            params['num_feats'] = tuple(ffs)
            norm_pipes = normalize_feat_pipe(ffs)
            union = pipeline(params['num_feats'], norm_pipes)

            # Add final estimator and learn fit.
            cls = ClassifierPipes()
            clf = pipe.chain_pipes([union, cls.clf(est)])
            clf.fit(X_train, y_train)

            model = clf
            params['model_id'] = save_model(clf)

            # move this into function
            scor = Score()

            report = load_report()

            train_score = clf.score(X_train, y_train)
            test_score = clf.score(X_test, y_test)
            #scores = scor.store(model_id, est, len(dataset), len(testset), num_feats, cv, train_score, 'train_score')
            #scores = scor.store(model_id, est, len(dataset), len(testset), num_feats, cv, test_score, 'test_score')

            params['est'] = est

            if DAE_MODE == 'predict_score':
                dae_score_predict(model, params, report, dataset, testset)
