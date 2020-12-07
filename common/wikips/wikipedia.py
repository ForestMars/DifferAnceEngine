# wikipedia app

import importlib

import requests as req
from bs4 import BeautifulSoup as bs
import os

import warnings
warnings.filterwarnings("ignore", category=UserWarning, module='bs4')

import requests.packages.urllib3
requests.packages.urllib3.disable_warnings()

import sys
importlib.reload(sys)
#sys.setdefaultencoding('utf-8')

def query(key, direc = None, download_image = False):

    cwd = os.getcwd()

    if direc != None:
        if not os.path.isdir(direc):
            os.mkdir(direc)

        os.chdir(direc)

    #if not os.path.isdir(key):
    #    os.mkdir(key)
    #os.chdir(key)

    base_url = 'https://en.wikipedia.org'
    url = base_url + '/wiki/'+key

    r = req.get(url)
    #soup = bs(r.text)
    soup = bs(r.text, features="html.parser")

    string = ''

    #p = soup.find('p')
    #input(type(p))
    #string += p.text

    pa = soup.find_all('p')
    #input(type(pa))
    for r in pa:
        string += r.text

    with open(key+'.txt', 'w') as f:
        f.write(string)

    if download_image:
        a = soup.find('a', attrs = {'class':'image'})
        newlink = base_url + a.attrs['href']

        newsoup = bs(req.get(newlink).text)

        div = newsoup.find('div', attrs = {'class':'fullImageLink'})
        a = div.find('a')

        image = 'https:'+ a.attrs['href']

        with open(os.path.basename(image), 'wb') as f:
            f.write(req.get(image).content)

    os.chdir(cwd)
