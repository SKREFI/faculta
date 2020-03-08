import re

from database.models import Product, Client
from database.Importer import CSVImporter


class ProductDatabase(CSVImporter):
    def __init__(self, path):
        self.products = super().parse(path)

    def __getattr__(self, id):
        return self.products[id]


class ClientDatabase():
    clients = []

    @classmethod
    def add_client(cls, client: Client):
        if client in cls.clients:
            # maybe this is not required and I could simply log a warning and do nothing else, choose this method for the moment
            raise Exception('Client already in database')
        cls.clients.append(Client)
