'''
Test DB File
'''

from os import getcwd as wd

from database.Importer import CSVImporter
from database.database import ProductDatabase
from database.database import ClientDatabase as client_db
from database.models import Client
path = wd() + '/database/products.csv'

# IDs: prime, pro, vpn, pass, opt, speed
products = ProductDatabase(path).products


client = Client('asd@gmail.com')
client_db.add_client(client)

print(client_db.clients)
