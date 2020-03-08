import pandas
from abc import ABC

from database.models import Product


class CSVImporter(ABC):

    @classmethod
    def parse(cls, path: str):
        if path.split('.')[-1] != 'csv':
            raise Exception('Path not pointing to csv file')

        products = {}

        file = pandas.read_csv(path, header=0)

        for index, row in file.iterrows():
            products[row['id']] = Product(row['full_name'], row['price'])

        return products
