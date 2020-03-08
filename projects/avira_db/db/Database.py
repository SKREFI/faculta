import re
import pandas

from db.Importer import CSVImporter


class ProductDatabase(CSVImporter):
    def __init__(self, path):
        self.products = super().parse(path)

    def __getattr__(self, id):
        return self.products[id]
