#!/usr/bin/env python
# run.py - Main entry point for DAE.
__version__ = '0.2'

import pickle
from pprint import pprint

import pandas as pd
from sklearn.model_selection import train_test_split
#from autosklearn.experimental.askl2 import AutoSklearn2Classifier

from common import get_args, utils
from dae import *
<<<<<<< HEAD
from lib.ext.estimators import Estimator
from lib.ext.pipes import Pipe, ClassifierPipes
from lib.ext.scoring import Score, score_predict, save_score, load_report
=======
from build.src.estimators import Estimator
from build.src.pipes import Pipe, ClassifierPipes
from build.src.scoring import Score, score_predict, save_score, load_report

>>>>>>> dev

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)
pd.set_option('display.width', 1000) #YMMV


SEED=42
TEST_SIZE=0.2
cv=3

DATA = 'data/'
DOMAIN='hackles'
DATA_DIR = DATA + DOMAIN
TRAIN_TEST = '/train_test'
TRAIN_TEST_SET = DATA_DIR + TRAIN_TEST

DAE_MODE = 'predict_score'


def dae_score_predict():
    """ Score and predict full test set """
    target_names = utils.get_dir_list(TRAIN_TEST_SET)
    score = score_predict(model, testset)
    save_score(report, model_id, est, len(dataset), len(testset), num_feats, cv, score, 'predict_score')


if __name__ == '__main__':

    avail_feats = _avail_feats()

    ## LOAD

    # Upload data or choose from sample datasets: Load a specified dataset (structured or unstructured) into a dataframe.
    import data.examples as examples
    ex = examples.Datasets()
    choices = ['documents', 'hackles', 'oenology']
    dataset, testset = ex.hackles()

    # Please don't run preprocessors on test or validation sets. Thanks.
    X_train, X_test, y_train, y_test = train_test_split(dataset, dataset['target'], test_size=TEST_SIZE, random_state=SEED)

    # reduce dev time
    dataset=dataset.head(100)
    testset=testset.head(100)
    # @TODO: Announce how many candidates the search space contains.

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

            num_feats = tuple(ffs)
            norm_pipes = normalize_feat_pipe(ffs)
            union = pipeline(num_feats, norm_pipes)

            # Add final estimator and learn fit.
            cls = ClassifierPipes()
            clf = pipe.chain_pipes([union, cls.clf(est)])
            clf.fit(X_train, y_train)

            model = clf
            model_id = save_model(clf)

            # move this into function
            scor = Score()

            report = load_report()

            train_score = clf.score(X_train, y_train)
            test_score = clf.score(X_test, y_test)
            #scores = scor.store(model_id, est, len(dataset), len(testset), num_feats, cv, train_score, 'train_score')
            #scores = scor.store(model_id, est, len(dataset), len(testset), num_feats, cv, test_score, 'test_score')

            if DAE_MODE == 'predict_score':
                dae_score_predict()

    # Ask, don't tell principle.
    #get report for domain- don't load here, have it loaded for you.
    #don't tell object what to do-- request something from it.
    report = 'results/' + DOMAIN + '.pkl'
    with open(report, 'rb') as file:
        saved_model = pickle.load(file)
    df = saved_model.sort_values(by=['mean_score'])
    pprint(df)


### DRAGONS ###
