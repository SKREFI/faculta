from ImportEngine.ImporterInterface import ImportInterface
from ImportEngine.DocxImporter import *
from ImportEngine.CsvImporter import *

from Cat import *


class Import(ImportInterface):

    Importers = {
        'docx': DocxImporter,
        'csv': CSVImporter
    }

    @classmethod
    def parse(cls, path: str) -> List[Cat]:
        return cls.Importers.get(path.split('.')[-1]).parse(path)
