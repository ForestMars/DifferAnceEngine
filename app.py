#!/usr/bin/env python
# run.py (smsbot) - SMS message dispatcher and handler. (In a more perfect world, this would be app.py.)
__version__ = '0.0.2'
CONDA_ENV = 'chatbot1'

#import inspect
import json
import os
import shlex
import subprocess

from flask import Flask, Response, request, redirect, session
from flask_session import Session
from twilio.twiml.messaging_response import MessagingResponse
from twilio.rest import Client
#import redis
import requests

#import contacts
from common.utils import HaltException as HX

"""
from common.logger import Log
log = Log()
try:
    app.config('config.py')
except Exception as e:
    log("Error finding or loading DevelopmentConfig object. You probably need to specify package since Python 3 dropped support for relative import. (See PEP 8)", e)
    try:
        app.config.from_pyfile('config/config.py')
        log("Loaded configuration from file")
    except IOError:
        log("Error finding config.py", IOError)
    except EOFError:
        log("Error reading config.py (lint file)", EOFError)
    except Exception as e:
        log("Ignoring unknown exception when loading config.py", e)
    except:
        handle_unhandled_error() # warn("an additional exception was thrown", throwable)
        log("no idea.")
"""

session_=Session()
nassau='+15166982705'
upstate="+18458680258"
belvedere="+14157122019"

#r = redis.StrictRedis(host=redis_host, port=redis_port, password=redis_password, decode_responses=True)
#r.set('counter', 1)

## app.py (not run.py)
command = shlex.split("env -i bash -c 'source env/env.sh && env'")
proc = subprocess.Popen(command,
    stdout=subprocess.PIPE,
    encoding='utf8',
    universal_newlines=True
    )
for line in proc.stdout:
  (key, _, value) = line.partition("=")
  os.environ[key] = value.strip()
proc.communicate()

try:
    account_sid = os.environ['TW_ACCT_SID']
except HX as ha:
    print("Sorry, no SID found.")
try:
    auth_token = os.environ['TW_AUTH_TOKEN']
except HX as ha:
    print("Sorry, no authentication token found.")
try:
    client = Client(account_sid, auth_token)
except HX as ha:
    print("Um...")


# @TODO: replace with custom logging module.
def logthis(filenom, txt):
    f = open(filenom, "w")
    f.write(txt)
    f.close()

# back-to-front
app = Flask(__name__)

@app.route('/test')
def helloIndex():
    return 'If you can see this...'

@app.route('/xml')
def xmlTest():
    xml = '<result>xml</result>'
    return Response(xml, mimetype='text/xml')

import api.predict

# @TODO: Auth, obvi.
@app.route('/run',methods = ['GET'])
def run_model(domain):
    try:
        api.predict.run()
    except Exception as e:
        print("A bad thing happened: ", e)
        


@app.route('/predict',methods = ['POST', 'GET'])
def predict(domain, doc):

    return Response(xml, mimetype='text/xml')

@app.route('/sms',methods = ['GET', 'POST'])
def sms():
    msg = request.form.to_dict() # Not currently used, but cast as dict so we can add additional keys. (@FIXME: Shouldn't this be in handler?)
    msg['From'] = msg['From'].replace(' ','') # ('+' handling)
    resp = handle_msg(msg)

    replies = json.loads(resp.content.decode('UTF-8'))

    if len(replies) > 0:
        for r in replies:
            print(r)
            who = r['recipient_id']
            reply = r['text']
            try:
                send_msg(who, reply)
            except Exception as e:
                print(e)

    return Response(resp, mimetype='text/xml')



if __name__ == "__main__":
    #logthis('calbot.log', 'zbot inititalized')
    app.secret_key = 'SECRET' # If I told you, it wouldn't be.
    #session_.init_app(app)
    #app.config['SESSION_TYPE'] = 'filesystem'
    #app.run(host='0.0.0.0', port= 80, debug=False)
    app.run(host='0.0.0.0', port= 5531, debug=True) # This is legacy flask and should source env.
