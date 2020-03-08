# from pathlib import
from os import getcwd as pwd
from os import path

from ImportEngine.Importer import Import

csv_path = pwd() + '/data/cats.csv'

print(Import.parse(csv_path))
