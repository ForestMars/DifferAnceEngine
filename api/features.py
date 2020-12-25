# features.py


current_domain = ''


# create domain
class Feature(object):
    def __init__(self):
        pass

    def create(name: str, input_feature: str, trasform: str)->'status':
        """ Declatively define a new feature and add as a pipe. """
        pass

    def delete(cats: list)->'status':
        """ Remove a feature pipe. """
        pass

    def activate(feature: str, domain=current_domain):
        """ Activate an existing feature for the current domain. """
        # domain.chk_feature_exists()
        # domain.activate.feature()
        pass

    def get_active_features() ->list:
        """ Returns list of active features when asked nicely. """
        # return domain.get_active()
        pass

    def get_feature_status(feature: str) ->str:
        """ Returns status for a given feature. Possible statuses are:
        Available: Feature is defined and may be activated for domain.
        Active: Feature is generated when classification dataset is loaded.
        Included: Feature is used in the trained model.
        """
        pass

class FeaturePipe(object):
    """ Creates a pipe from a list of available features """
    def __init__(self):
        pass
    def create(feats: list):
        """ Returns a pipe that removes all features not in feature list. """
        pass


class Model(object):
    def __init__(self):
        pass

    def create(estimator: str, features: list):
        """ Returns a pipe with given features and estimator. """
        pass

    def get_features(model: str) ->list:
        """ Given a valid model id, returns list of its features. """
        pass

    def feature_in_model(feature: str, model: str) ->bool:
        """ True is feature is included in the given model. """
        pass

