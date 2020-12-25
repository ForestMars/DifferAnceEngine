# predict.py - define endpoint for predicting against trained models.

# import os
# inport sys

from run import predict_this

DOMAIN=example

"""
params:
@model - a pickld model to run
@model_loc - path to a pickld model on a local filesystem
Return: a model_id
"""
def add_model(model=None, model_loc: str=None) ->str:
    """ Adds an uploaded model to Tubular and returns the namespace ID for that model. """
    pass

def add_models(models: list=None, model_locs: list=None) ->str:
    """ Adds an uploaded model to Tubular and returns the namespace ID for that model. """
    pass

def get_model(model_name: str, status: bool=None): # This is intentional.
    """ Fetches a model if it's available, or just tells you when status=True
    model_status will be 1 of:
        'available': the model is available in the current domain.
        'active': the model is running a predictive endpoint.
        'deleted': the model has been deleted and is no longer available.
        'unknown': the model is not recognized.
    """
    pass

def get_models(domain=DOMAIN) ->list:
    """ Tells you all available models when asked nicely. """
    pass

def get_targets(model_name=None, model_loc=None) ->list:
    """ Tells you available categories for the active domain. """
    pass

def predict(domain, doc):
    "Given a thing, tells you what kind of thing it is."
    with open(kosher+dill, 'rb') as file:
        model = pickle.load(file)

# This should be its own class.
def run(domain)->str:
    """ Run model against prediction set.
    :param domain: active domain. """

    domain_model_path = MODELS + '/' + DOMAIN + '/'
    update_model = DOMAIN + '__active_model.pkl'
    model = domain_model_path + update_model

    with open(model, 'rb') as file:
        model = pickle.load(file)

    target_names = utils.get_dir_list(TRAIN_TEST_SET) # How to get programmatically, since bunch doesn't know the lables
    keys = list(testset)[0:11]
    for i in keys:
        est  = model.predict([testset[i]])
        p = est.tolist()[0]
        print("The predicted class of " + i + " is " + target_names[p])
        #utils.move_posix_file(i, PREDICT, RESULTS + '/' + target_names[p])
