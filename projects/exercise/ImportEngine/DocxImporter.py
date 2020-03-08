from typing import List
import docx

from ImportEngine.ImporterInterface import ImportInterface
from Cat import *


class DocxImporter(ImportInterface):
    allowed_extensions = ['docx']

    @classmethod
    def parse(cls, path: str) -> List[Cat]:
        if not cls.can_ingest(path):
            print()
            raise Exception('cannot ingest exception')

        cats = []
        print('DEBUG', path)
        doc = docx.Document(path)

        for para in doc.paragraphs:
            if para.text != "":
                parse = para.text.split(',')
                new_cat = Cat(parse[0], int(parse[1]), bool(parse[2]))
                cats.append(new_cat)

        return cats
