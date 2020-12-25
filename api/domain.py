# domain.py - Controller for active domain.

from common import utils

active_domain = ''

DATA = 'data/'
DOMAIN='hackles'
DATA_DIR = DATA + DOMAIN
TRAIN_TEST = '/train_test'
TRAIN_TEST_SET = DATA_DIR + TRAIN_TEST
PREDICT = DATA_DIR +'/predict'
RESULTS = DATA_DIR +'/results'
MODELS = 'models'


# # DOMAIN

class Domain():
    def __init__(self,  domain):
        self._path = self.val_path(domain)

    @property
    def path(self):
        return self._path

    def val_path(self, domain):
        dirpath = 'models/' + domain
        if utils.isdir(dirpath):
            return(dirpath)
        else:
            utils.mkdir('models/', domain)
            return dirpath

domain = Domain('default')

# @TODO: targets should not be subject to side effects.
def get_targets(domain=DOMAIN):
    """ Targets may be supervised (labeled) or unsupervised (numbered).
    :param domain: (str) the lexical problem space.
    :return:
    """
    tt = DATA + domain + '/train_test'
    return utils.get_dir_list(tt)
targets = get_targets()

# # SETUP & CHECKS
def make_targets(domain=DOMAIN, targets: list=None, set='result_set'):
    """ Check if domain exists in stream. (eg. file system directory, kafka topic, etc.)
    :param domain: (str) the lexical problem space
    :param targets: (list) labels, if supervised
    :param set: (str) may be one of 'train_test_set' or 'result_set'
    :return:
    """
    if set == 'train_set':
        train_test = DATA_DIR + '/train_test'
        if not utils.dir_exists(train_test):
            utils.mkdir(train_test)
        for target in targets:
            if not utils.dir_exists(train_test + '/' + target):
                utils.mkdir(train_test + '/', target)
    elif set == 'result_set':
        results = RESULTS
        if not utils.isdir(results):
            utils.mkdir(results)
        for target in targets:
            if not utils.isdir(results + '/' + target):
                utils.mkdir(results, target)
make_targets(DOMAIN, targets)


# Don't try to give the same name to another domain. Why would you do that.
class Domain_(object):

    # Needs to return object, not list, so it can be properly cached.
    def get(self):
        """ Tells you all available domains. Isn't bothered if you forgot. """
        # self.domains = get_domains()
        pass

    def set(self, domain: str):
        """ Adds a new domain. Basically creating the directory and returning (not saving) the path. (App is stateless.)
        Return: object containing updated domains. """
        pass

    def exists(self, domain):
        """ Tells you whether your domain exists or not. """
        pass

def get_pipes():
    """ Returns list of available pipes when asked nicely. """
    pass

def add_pipe():
    """ Add a new pipe to the pipeyard. Well, that's what it's called. """
    pass

def del_pipe():
    """ This is mostly tricky permissions. """
    pass

def project():
    pass

def create_feat_pipe(feats: list):
    """ Creates a feature pipe when given a post request with a list of features. """
    # Return status
    pass


# create etc domain
class DomainCRUD(object):
    """ Everything you've always wanted to know but were too afraid… """

    def __init__(self):
        pass

    def create(cats: list)->'status':
        """ create a new classification project domain. """
        pass

    def delete(cats: list)->'status':
        """ Delete a domain. This will delete all content irrespective of backups. """
        pass


# define categories

class Categories(object):
    def __init__(self):
        pass

    def create(domain: str=active_domain, cats: list=None) ->'status':
        """ create or add categories to an existing domain. """
        pass

    def delete(domain: str=active_domain, cats: list=None) ->'status':
        """ delete categories from a domain. """
        pass

def get_domains():
    """ Returns a list of active domains when asked nicely. """
    data_dir=DATA_DIR
