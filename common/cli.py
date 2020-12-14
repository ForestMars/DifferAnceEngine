#!/usr/bin/python3
# cli.py - DifferAnce Engine arg parger
# Optional cli arguments: in most cases they will be set in an API call.
"""
    -l  learn best params
    -p  run predict api
    -s  score model estimator
    -y  show param slopes
    -d  dockerize best model
    -H  docker host
    -U  docker user
    -K  docker host key
    -D  domain
    -P  port (to serve model)
    -h  show this help text
"""
import argparse


DESCRIPTION="DifferAnce Engine arg parser"


def get_args(argv):

    parser = argparse.ArgumentParser(
        description=DESCRIPTION,
        epilog = """ Given a thing, tells you what kind of thing it is. """
        )

    parser.add_argument('-l', '--learn',  default=None, help='learn best params', metavar='')
    parser.add_argument('-p', '--predict', default=None, help='run predict module only', metavar='')
    parser.add_argument('-s', '--score', default=None, help='score this estimator', metavar='')
    parser.add_argument('-d', '--dockerize', default=None, help='dockerize best model', metavar='')
    parser.add_argument('-H', '--docker-host', default=None, help='Docker host IP address', metavar='HOST')
    parser.add_argument('-U', '--docker-user', default=None, help='Docker user', metavar='USER')
    parser.add_argument('-K', '--host-key', default=None, help='Host key', metavar='KEY')
    parser.add_argument('-D', '--domain', default=None, help='Docker user', metavar='DOMAIN')
    parser.add_argument('-P', '--port', default=None, help='Docker user', metavar='DOMAIN')
    #parser.add_argument('-a', '--action', action="store", dest='action', default=None, help='', metavar='')

    #args = parser.parse_args()
    args = parser.parse_args(argv[1:])

    return args

# ???
if __name__ == '__main__':
    get_args()
