from typing import List
import docx
import pandas

from ImportEngine.ImporterInterface import ImportInterface
from Cat import *


class CSVImporter(ImportInterface):
    allowed_extensions = ['csv']

    @classmethod
    def parse(cls, path: str) -> List[Cat]:
        if not cls.can_ingest(path):
            raise Exception('cannot ingest exception')

        cats = []

        df = pandas.read_csv(path, header=0)

        for index, row in df.iterrows():
            cats.append(Cat(row['Name'], row['Age'], row['isIndoor']))

        return cats
