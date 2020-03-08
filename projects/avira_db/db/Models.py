# from abc import ABC, abstractmethod
import re


class Product():
    def __init__(self, name, price, stoc):
        ''' 
        May add featres in the future if needed
        '''
        self.name = name
        self.price = price
        self.stoc = stoc

    def __repr__(self):
        return f'{self.name}, ${self.price}, {self.stoc}'
