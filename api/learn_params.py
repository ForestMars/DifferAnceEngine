#!/usr/bin/env python
# learn_params.py - Auto-ML search space
__version__ = '0.1'

import pickle
from time import time

import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV, RandomizedSearchCV

from lib.ext.models import Classifiers, HyperSpace
from common.utils import fopen

cv = 1
n_iter = 100
n_jobs =-1
SEED = 42
TEST_SIZE=0.5
verbosity = 2


class RandomGridSearch(object):
    def __init__(self):
        pass

    def est_grid(self, est: str):
        """
        :param est: estimator name """
        space = HyperSpace()
        grid = space.grid(est)
        return grid

    def random_search(self, est, X, y):
        cls = Classifiers()
        model = getattr(cls, est) # (Untrained)
        grid = self.est_grid(est)

        est_search = RandomizedSearchCV(
            estimator=model,
            param_distributions=grid,
            n_iter=n_iter,
            cv=cv,
            verbose=verbosity,
            random_state=SEED,
            n_jobs=n_jobs,
            )

        est_search.fit(X, y)
        self.best_params = est_search.best_params_
        print(est_search.best_params_) #

        filename = 'automl/' + est + '_best_params_' + str(int(time())) + '.py'
        with fopen(filename, 'wb') as f:
            f.write(est_search.best_params_.txt)


""" Using GridSearchCV, not autosk-learn """
class GridSearch(object):
    def __init__(self):
        pass

    def best(self):
        besties = {
            'best_est': self.best_estimator,
            'best_params': self.best_params,
            'best_score': self.best_score,
        }

        return besties

    def est_grid(self, est: str):
        """ Returns current grid values, which may not be what you want.
        :param est: estimator name """
        space = HyperSpace()
        grid = space.grid(est)
        return grid

    def grid_search(self, est, X, y):
        cls = Classifiers()
        model = getattr(cls, est) # (Untrained)
        grid = self.est_grid(est)

        #pipe_params = { 'pipe' +'__'+ p: v for (p, v) in grid }

        gscv = GridSearchCV(estimator=model,
            param_grid=grid,
            cv=cv,
            n_jobs=n_jobs,
            verbose=verbosity
            )

        # @TODO: timeit() and record.
        gscv.fit(X, y)
        self.best_est = est_search.best_estimator_
        self.best_params = est_search.best_params_
        self.best_score = est_search.best_score_
        print(gscv.best_estimator_)
        print(gscv.best_score_)
        print(gscv.best_params_)



### LOAD (Testing)
if __name__ == '__main__':
    import data.examples as examples
    ex = examples.Datasets()
    choices = ['documents', 'hackles', 'oenology']
    dataset, testset = ex.spooky()
    DOMAIN = 'hackles'

    if 'id' in dataset:
        dataset = dataset.drop(['id'], axis=1) # id is redundant.

    from build.src.pipes import Pipe
    pipe = Pipe()
    vector = pipe.chain_pipes(['tfidf_col'])
    vector[0][0].set_params(col='raw')
    dataset_v = vector.fit_transform(dataset)

    X_train, X_test, y_train, y_test = train_test_split(dataset_v, dataset['target'], test_size=TEST_SIZE, random_state=SEED)

    est = 'rfc'
    rs =  RandomGridSearch()
    gs =  GridSearch()
    gs.grid_search(est, X_train, y_train)

    preds = clf.predict(X_test)
    input(preds)
    probs = clf.predict_proba(X_test)
    input(probs)
    input(np.mean(preds == y_test))
