# kosher.py - Provides mixin for encrypting pickles.

import os
import base64
import pickle
from typing import types

from cryptography.fernet import Fernet
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

from Crypto.Cipher import AES
#from Crypto.Random import get_random_bytes
#from Crypto.Hash import HMAC, SHA, SHA256, SHA384, SHA512


SALT_SIZE = 22
SHA = 'SHA256'
#SHA = 'SHA512'

# Are pickles kosher?
if 'DILL' in os.environ:
    MOT = os.environ['DILL']
else:
    MOT = 'supersecret'


class KosherPickleMixin(object):
    """ Mixin for encrypting pickles. """

    def __getstate__(self):
        if 'MOT' in globals():
            foo = self.encrypt(self.__dict__, MOT)

            return foo
        else:
            return self.__dict__


    def __setstate__(self, obj):
        if isinstance(obj, bytes) and 'MOT' in globals():
            try:
                self.__dict__ = self.decrypt(obj, MOT)
            except Exception as e:
                print(e)
        else:
            return obj.__dict__


    def derive_key(self, pw, salt, sha=SHA):
        pw = pw.encode()
        kdf = PBKDF2HMAC(
            algorithm = getattr(hashes, sha),
            length = 32,
            salt = salt,
            iterations = 100_000,
            backend = default_backend(),
            )

        return base64.urlsafe_b64encode(kdf.derive(pw))


    def aes_iv():
        iv = ''.join([chr(random.randint(0, 0xFF)) for i in range(16)])
        #return 'foo'

    def aes():
        aes = AES.new(self.derive_key, AES.MODE_CBC, self.aes.iv)
        return aes



    def scheme(self, key): # aka scheme
        """ N.B. Currently supports only Fernet (symmetric) encryption. """
        #if self._algo  in globals() and isinstance(globals()[self._algo], types.ClassType):
        if self._algo in globals():
            input('ha')
            input(str(self._algo))

            input(self._algos[self._algo])
            return globals()[self._algo](key, self._algo[0])


    def encrypt(self, raw_data, pw, protocol=None, fix_imports=True):
        salt = os.urandom(SALT_SIZE)
        key = self.derive_key(pw, salt)
        scheme = self.scheme(key)
        pickled_data = pickle.dumps(
            raw_data,
            protocol=protocol,
            fix_imports=fix_imports
            )
        encrypted_data = scheme.encrypt(pickled_data)

        return salt + encrypted_data


    def decrypt(self, input_data, pw, fix_imports=True, encoding="ASCII", errors="strict"):
        salt = input_data[:SALT_SIZE]
        key = self.derive_key(pw, salt)
        scheme = self.scheme(key)
        encrypted_data = input_data[SALT_SIZE:]
        pickled_data = scheme.decrypt(encrypted_data)

        return pickle.loads(
            pickled_data,
            fix_imports=fix_imports,
            encoding=encoding,
            errors=errors
            )


    @property
    def _algo(self):
        """ Currently Kosher only uses Fernet. """
        self.algo = 'AES'
        return self.algo


    @_algo.setter
    def _algo(self, algor: str):
        if algor in self.algos:
            self.algo = algor
        else:
            print("Sorry, " + algor + " is not currently supported.")

    @property
    def algos():
        self.algos = [
            {'AES': [AES.MODE_CBC, self.aes.iv]},
            {'Fernet': ['']},
            ]
        return self.algos
