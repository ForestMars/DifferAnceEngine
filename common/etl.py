# etl.py - Cleanup text blobs/documents prior to featurization.
__all__ = ['clean_dox']

import re
from nltk.stem import WordNetLemmatizer


stemmer = WordNetLemmatizer()

def byte_str_to_str(blobs):
    " Returns list of strings when given a list of byte strings. "
    docs = []
    for blob in blobs:
        doc = blob.decode('utf-8')
        docs.append(doc)

    return docs


def clean_dox(blobs: list) ->list:
    " Given a list of text blobs, returns a cleaned version"
    docs = []
    for blob in range(0, len(blobs)):
        # Remove all the special characters
        doc = re.sub(r'\W', ' ', str(blobs[blob]))
        # remove all single characters
        doc = re.sub(r'\s+[a-zA-Z]\s+', ' ', doc)
        # Remove single characters from the start
        doc = re.sub(r'\^[a-zA-Z]\s+', ' ', doc)
        # Substituting multiple spaces with single space
        doc = re.sub(r'\s+', ' ', doc, flags=re.I)
        # Strip byte string
        doc = re.sub(r'^b\s+', '', doc)
        # Converting to Lowercase
        doc = doc.lower()
        # Lemmatization
        doc = doc.split()
        doc = [stemmer.lemmatize(word) for word in doc]
        doc = ' '.join(doc)
        docs.append(doc)

    return docs
