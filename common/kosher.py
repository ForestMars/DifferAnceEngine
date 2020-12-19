# kosher.py - Provides mixin for encrypting pickles.

import os
import base64
import pickle

from cryptography.fernet import Fernet
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC


SALT_SIZE = 22

# Are pickles kosher?
if 'DILL' in os.environ:
    MOT = os.environ['DILL']


class KosherPickleMixin(object):
    """ Mixin for encrypting pickles. """

    def __getstate__(self):
        if 'MOT' in globals():
            return encrypt(self.__dict__, MOT)
        else:
            return self.__dict__

    def __setstate__(self, obj):
        if isinstance(obj, bytes) and 'MOT' in globals():
            try:
                self.__dict__ = decrypt(obj, MOT)
            except Exception as e:
                input(e)
        else:
            return obj.__dict__


def derive_key(pw, salt):
    pw = pw.encode()
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        length=32,
        salt=salt,
        iterations=100_000,
        backend=default_backend(),
        )

    return base64.urlsafe_b64encode(kdf.derive(pw))


def encrypt(raw_data, pw, protocol=None, fix_imports=True):
    salt = os.urandom(SALT_SIZE)
    key = derive_key(pw, salt)
    fernet = Fernet(key)
    pickled_data = pickle.dumps(
        raw_data,
        protocol=protocol,
        fix_imports=fix_imports
        )
    encrypted_data = fernet.encrypt(pickled_data)

    return salt + encrypted_data


def decrypt(input_data, pw, fix_imports=True, encoding="ASCII", errors="strict"):
    salt = input_data[:SALT_SIZE]
    encrypted_data = input_data[SALT_SIZE:]
    key = derive_key(pw, salt)
    fernet = Fernet(key)
    pickled_data = fernet.decrypt(encrypted_data)

    return pickle.loads(
        pickled_data,
        fix_imports=fix_imports,
        encoding=encoding,
        errors=errors
        )
