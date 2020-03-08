# from abc import ABC, abstractmethod
import re


class Product():
    def __init__(self, name, price):
        ''' 
        May add featres in the future if needed
        '''
        self.name = name
        self.price = price

    def __repr__(self):
        return f'{self.name}, {self.price}'


class Client():

    def __init__(self, email):
        self.email = email
        self.products_owned = []

    @classmethod
    def check_mail(cls, mail):
        regex = '^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$'
        if not re.search(regex, mail):
            raise Exception('Email not valid')
        return True

    @classmethod
    def getMail(self):
        return self.mail


    def __repr__(self):
        return '{}'.format(self.email)
