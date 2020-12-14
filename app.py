# app.py - Stand alone predict module for dockerizing.

import logging

#from flask import Flask, Response, request, redirect, session
from flask import Flask, Response, flash, request
import nltk
import pandas as pd
from redis import Redis
from rq import Queue
import sklearn

from common import utils
from make_prediction import prediction

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
    #predict_req = request.form.to_dict()
    #blob = predict_req['text']
    #resp = prediction(blob)
    #resp = prediction(request.form['text'])

    job = q.enqueue(prediction, request.form['text'])
    print(job.get_id())
    input('back')
    return Response(resp, mimetype='text/xml')






if __name__ == '__main__':
        app.run(host='0.0.0.0', port=FLASK_RUN_PORT, debug=True)
