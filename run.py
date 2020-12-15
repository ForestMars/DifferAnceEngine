#!/usr/bin/env python
# run.py - Main entry point for DAE.
__version__ = '0.3'

import pickle
from pprint import pprint
import sys

import pandas as pd
from sklearn.model_selection import train_test_split
#from autosklearn.experimental.askl2 import AutoSklearn2Classifier

from redis import Redis
from rq import Queue

from common import cli, utils
from dae import *
from lib.ext.estimators import Estimator
from lib.ext.pipes import Pipe, ClassifierPipes
from lib.ext.scoring import Score, score_predict, save_score, load_report
from optiML import search_space

args = cli.get_args(sys.argv)

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)
pd.set_option('display.width', 1000) #YMMV


DATA = 'data/'
DOMAIN='hackles'
DATA_DIR = DATA + DOMAIN


if __name__ == '__main__':

    q = Queue(connection=Redis())

    avail_feats = _avail_feats()

    ## LOAD

    # Upload data or choose from sample datasets: Load a specified dataset (structured or unstructured) into a dataframe.
    import data.examples as examples
    ex = examples.Datasets()
    choices = ['documents', 'hackles', 'oenology']
    dataset, testset = ex.hackles()

    # @TODO: Announce how many candidates the search space contains.

    job = q.enqueue(search_space, avail_feats, dataset, testset)

    # Ask, don't tell principle.
    #get report for domain- don't load here, have it loaded for you.
    #don't tell object what to do-- request something from it.
    report = 'results/' + DOMAIN + '.pkl'
    with open(report, 'rb') as file:
        saved_model = pickle.load(file)
    df = saved_model.sort_values(by=['mean_score'])
    pprint(df)


### DRAGONS ###
