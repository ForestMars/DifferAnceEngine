#!/usr/bin/env python
# api/estimators - API calls related to estimators.
__version__ = '0.1'

import json
import redis

from config.redis import *


def select_estimators(ests: list):
    """ API call to set active estimators for the current session. """
    try:
        r.set("estimators:active", json.dumps(ests))
    except Exception as e:
        print(e)


def load_estimators():
    """ If estimators are not in redis and not loaded from config,
     we load a one-shot list. This runs on app cold startup. """
    est_config_path = 'config/estimators.pkl'
    with open('est_config_path', 'rb') as file:
        ests = pickle.load(file)
