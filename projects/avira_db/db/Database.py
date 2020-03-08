import re
import pandas

from db.Importer import CSVImporter
from db.Models import Client


class ProductDatabase(CSVImporter):
    def __init__(self, path):
        self.products = super().parse(path)

    def __getattr__(self, id):
        return self.products[id]


class ClientDatabase():
    def __init__(self, path):
        self.clients = []
        if path.split('.')[-1] != 'csv':
            raise Exception('Path not pointing to a csv file')
        
        file = pandas.read_csv(path, header=0)

        for i, row in file.iterrows():
            self.clients.append(Client(row['email']))

    def add_client(self, client: Client):
        if client in self.clients:
            # maybe this is not required and I could simply log a warning and do nothing else, choose this method for the moment
            raise Exception('Client already in database')
        

