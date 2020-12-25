# app.py - predict module for dockerizing.

import logging

from flask import Flask, Response, flash, request
import nltk
import pandas as pd
from redis import Redis
from rq import Queue
import sklearn
import waitress

from common import utils
from make_prediction import prediction
from common.lumberjack import Log as log # PEP8

nltk.download('stopwords')


FLASK_RUN_PORT = utils.get_env('FLASK_RUN_PORT') or 5555
DOMAIN = 'hackles'
DOMAINPATH = 'models/' + DOMAIN + '/'


app = Flask(__name__)
q = Queue(connection=Redis())
logger = logging.getLogger(__name__)


@app.route('/')
def index():

    return "DifferAnce Engine"


@app.route('/predict', methods = ['GET', 'POST'])
def predict():
    """ Expects a blob and a domain key to predict against. """
    job = q.enqueue(prediction, request.form['text'])
    log(job.get_id())
    
    return Response(resp, mimetype='text/xml')


if __name__ == '__main__':
        # app.run(host='0.0.0.0', port=FLASK_RUN_PORT, url_scheme='https')
        app.run(host='0.0.0.0', port=FLASK_RUN_PORT, debug=True)
        # serve(app, host='0.0.0.0', port=5531) # waitress
