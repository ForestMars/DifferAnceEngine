#!/usr/bin/env python
# examples.py - Load sample datasets
# Choose from:
# 1. Numeric data (oenology)
# 2. Text blobs from csv (spooky authors)
# 3. Raw documents from filesytem (chemistry)
# 4. Tokenized representation
__version__ = '0.0.1'

import os

import pandas as pd
from sklearn.datasets import load_files

from common import etl
from common.utils import get_reg_files, read_file


DOMAIN='documents'
TRAIN_TEST = DOMAIN +'/'+ 'train_test'
PREDICT = DOMAIN +'/'+ 'predict'
RESULTS = DOMAIN +'/'+ 'predict'


class Datasets():
    def __init__(self):
        pass

    def oenology():
        pass

    # Spooky Like Voodoo.
    @staticmethod
    def hackles():
        #test_train = 'datasets/spooky/spooky2k.csv'
        test_train = 'data/hackles/spooky2_tt_1000.csv'
        #test_train = 'datasets/spooky/spooky2_sort_id_13k.csv'
        dataset = pd.read_csv(test_train) # -> id, raw_data, targets
        # X_raw = df['raw']
        # y = df['target']

        # You can't unpredict that.
        predict = 'data/hackles/spooky2_pred_1000.csv'
        df_predict = pd.read_csv(predict)
        raw = df_predict['raw'].tolist()
        targets = df_predict['target'].tolist() # (for scoring)

        # If feature in domain
        # id -> drop feature based on condition: if_exists
        if 'id' in dataset:
            dataset = dataset.drop(['id'], axis=1) # id is redundant.

        return dataset, df_predict # [Z_names, Z_docs]

    # We Are Scientists.
    @staticmethod
    def documents():
        """ Raw text document example for testing. NB. targets are actually names, not categories. """
        Z = {}
        Z_docs = [] # PEP8
        Z_names = [] # PEP8
        train = os.getcwd() + "/data/" + TRAIN_TEST
        bunch = load_files(train) # -> sklearn 'bunch'
        X_raw, y = bunch.data, bunch.target # list, np.arr PEP8
        # bunch.data are byte strings, not objects.
        doc_strings = etl.byte_str_to_str(X_raw) # oh gosh
        df = pd.DataFrame(doc_strings, columns=['raw'])
        df.dropna(axis=0)
        df.columns = ['raw']
        df['target'] = y.tolist() # @TODO: length check skipped, needs to be added.

        # Why do you need an index column if you already have an index? 🤔 @TODO: kill this.
        # if we have an an index col:
            # df.set_index('id', inplace = True)
        #else:
        #df['id'] = df.index

        # Z is our predict axis.
        path = 'data/' + DOMAIN + '/predict/'
        predict_files = get_reg_files(path) # -> list of test docs

        for f in predict_files:
            Z_names.append(f)
            Z_docs.append(read_file(path + f))
            # Z[f] = read_file(path + f) # If items have names, which they generally don't.

        return df, [Z_names, Z_docs]

    def tokenized_docs():
        """ Tokenized documents example for testing. """
        #X = pd.DataFrame(breast_cancer.data, columns=breast_cancer.feature_names)
        #y = pd.Categorical.from_codes(breast_cancer.target, breast_cancer.target_names)
        pass

    # The Birthday Party
    def labeled_docs():
        """ Labeled document example for supervised testing.
        Columns are:
            @raw: raw text before any preprocessing
            @rep: tokenized document represenation
            @labels: post-suprvision document
            """
        pass
