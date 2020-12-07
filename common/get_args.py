#!/usr/bin/python3
# get_args.py - DifferAnce Engine arg parger
"""
    -h  show this help text
    -l  learn best params
    -m  save best model
    -p  run predict api
    -s  score model estimator
    -v  show param slopes
"""
import argparse


DSCRIPTION="DifferAnce Engine arg parser"

def get_args():

    parser = argparse.ArgumentParser(
        description=DESCRIPTION,
        epilog = """ Given a thing, tells you what kind of thing it is. """
        )

    parser.add_argument('-l', '--learn', action="store", dest='learn', default=None, help='learn best params', metavar='')
    parser.add_argument('-m', '--save_model', action="store", dest='save', default=None, help='save best model', metavar='')
    parser.add_argument('-p', '--predict', action="store", dest='predict', default=None, help='run predict module only', metavar='')
    parser.add_argument('-s', '--score', action="score", dest='score', default=None, help='score this estimator', metavar='')

    args = parser.parse_args()

    return args

# ???
if __name__ == '__main__':
    get_args()
