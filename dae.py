#!/usr/bin/env python
# dae.py - Generators for optimisation space and related functions for main execution.
__version__ = '0.2'
__all__ = ['_avail_feats', 'feature_space_generator', 'normalize_feat_pipe', 'pipeline', 'save_model', 'x_val']

import itertools
import os
import pickle
import time

import numpy as np
import pandas as pd
from nltk.corpus import stopwords

import common.etl
from common.memo import memo
from common import utils
from common.utils import fopen
from lib.ext import features
from lib.ext.pipes import Pipe

from api.domain import Domain, get_domains


#logger = logging.getLogger()
#STOPS=stopwords.words('english')
os.environ['SEED'] = '42'

N_EST=3000
MAX_DEPTH=None
MIN_FEATS=1
MAX_FEATS=-1
min_feats=MIN_FEATS
max_feats=MAX_FEATS

# Kill all of this. Domain is dynamic, not an environmental constant.
DATA = 'data/'
DOMAIN='hackles'
DATA_DIR = DATA + DOMAIN
PREDICT = DATA_DIR +'/predict'
RESULTS = DATA_DIR +'/results'
MODELS = 'models'
domain = Domain('hackles')
DOMAIN = 'hackles'


pipe = Pipe() # Pipe should not be instantiated on both sides.

### PREPROCESSING


### FEATURES
## Explore features based on your amazing intuition - Define feature pipes.
## @DEBATE: Refactor feature pipes to add each feature, not add UP each feature (rather than cumulative tubes.)

def _avail_feats():
    """ Read in features from dataset or generate them at runtime with measurements. """

    def _get_extant_feats():
        """ Load features from dataset """
        pass

    def _apply_feats():
        """ Enumerate available features which may be extracted from the dataset data """

        for pipe in avail_feat_pipes: # pipes can be feature pipes, for introducing gaussian derivatives.
            for feat in pipe:
                pass

    return features.available


def feature_space_generator(avail_feats):
    """ Feature subspace generator.
    """
    #feature_space = []
    for n in range(min_feats, len(avail_feats)+1):
        for subset in itertools.combinations(avail_feats, n):
            yield subset

def normalize_feat_pipe(feat_set):
    """ Returns pipe to normalize a given set of measurements. """
    norm_pipes = []
    norm_feats = [q + '_norm' for q in feat_set]

    for n, f in enumerate(feat_set):
        nom = feat_set[n] + '_norm_pipe'
        nom = pipe.make_normie(f)
        norm_pipes.append(nom)

    return norm_pipes


def pipeline(num_feats, norm_pipes):
    """ pipeline is more of a verb here than usual. """
    feature_space = []
    #for p in range(0,len(numeric[0])):
    #    numeric[0][p][0].set_params(col='raw') # we don't pass arg so we don't use a selector.

    # We build the last pipe first bc Python is pass by (obj) ref.
    norm_feat_pipe = pipe.chain_fu_pipes('norm_feat_pipe', norm_pipes)
    num_feat_pipe = pipe.chain_pipes(list(num_feats))

    numeric = pipe.chain_pipes([
        num_feat_pipe,
        norm_feat_pipe,
        ])

    for p in range(0,len(numeric[0])):
        numeric[0][p][0].set_params(col='raw') # we don't pass arg and so we don't use a selector.

    # Vectorize and reduce matrix
    vector = pipe.chain_pipes(['tfidf_col'])
    union = pipe.chain_fu_pipes('union_pipe', [numeric, vector])

    return union


# Save trained model with gnerated ID.
def save_model(model):
    dir = domain.path
    domain_model_path = MODELS + '/' + DOMAIN + '/'
    current_model = DOMAIN +  '.pkl'
    timestamped_model = DOMAIN + '_' + str(int(time.time())) + '.pkl'

    #if utils.path_exists(domain_model_path + best_model):
    #    utils.rename_file(domain_model_path, update_model, timestamped_model) # This is mainly for running models.
    #utils.rename_file(domain_model_path, timestamped_model, saved_model)


    
    filepath = domain_model_path + current_model
    with fopen(filepath, 'wb') as file:
        pickle.dump(model, file)

    filepath = domain_model_path + timestamped_model
    with fopen(filepath, 'wb') as file:
        pickle.dump(model, file)


    # Confirm model was saved.
    with open(filepath, 'rb') as file:
        saved_model = pickle.load(file)
    return current_model


def x_val():
    # Cross-validation to confirm scores using full data set.
    from sklearn.model_selection import cross_val_score
    print("Running Cross-vaidation")
    #cv_set = num_feats_pipe.transform(data)
    #cv_set = combine_feats_pipe.fit_transform(cv_set)
    #vector_data = tfidf_pipe.transform(dataset)
    #scores = cross_val_score(vector_data, vector_data, dataset['target'], cv=5, n_jobs=5, scoring='accuracy')
    print(scores)
    print(scores.mean())




if __name__ == '__main__':
    print("This is probably not what you want to do. \nThis module only provides gnerators and related helper functions. \nPlease use main module, `run.py`.\n꧁꧅ͮͤ꧂\n")
