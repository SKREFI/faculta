'''
Test DB File
'''

from os import getcwd as wd

from db.Importer import CSVImporter
from db.Database import ProductDatabase
from db.Database import ClientDatabase as client_db
from db.Models import Client
path = wd() + '/db/Products.csv'

# IDs: prime, pro, vpn, pass, opt, speed
products = ProductDatabase(path).products


client = Client('asd@gmail.com')
client_db.add_client(client)


