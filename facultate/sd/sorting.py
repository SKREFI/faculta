from math import log
from random import randint as r
import time

from abc import ABC


class SortingInterface(ABC):

    def Radix(self, inp, BASE = 256):
        if len(inp) == 0:
            return []

        digits = (int(log(max(inp), BASE)) + 1)

        def setup():
            d = {}
            for i in range(BASE):
                d[i] = []
            return d

        def dicToList(d):
            l = []
            for values in d.values():
                for value in values:
                    l.append(value)
            return l

        key = 1  # adica cifra unitatilor (abcd // key = d)
        for _ in range(digits):
            d = setup()
            for i in inp:
                d[(i//key) % BASE].append(i)
            inp = dicToList(d)
            key *= BASE
        return inp

    Functions = {
        'radix' : Radix 
    }

    @staticmethod
    def get_efficiency(cls, sorting_function):
        f = Functions.[sorting_function]
        
        
        return int(round(time.time() * 1000))


class Sorters(SortingInterface):
    def __init__(self, sorting_function):
        print(super().get_efficiency(self, sorting_function))


def radix(inp, BASE):
    if len(inp) == 0:
        return []
    digits = (int(log(max(inp), BASE)) + 1)

    def setup():
        d = {}
        for i in range(BASE):
            d[i] = []
        return d

    def dicToList(d):
        l = []
        for values in d.values():
            for value in values:
                l.append(value)
        return l

    key = 1  # adica cifra unitatilor (abcd // key = d)
    for _ in range(digits):
        d = setup()
        for i in inp:
            d[(i//key) % BASE].append(i)
        inp = dicToList(d)
        key *= BASE
    return inp


# def bubble(inp):
# def merge(inp):
# def quick(inp):

def countSort(inp):
    l = [0 for _ in range(max(inp) + 1)]
    for i in inp:
        l[i] += 1
    ret = []
    index = 0
    for i in l:
        for _ in range(i):
            ret.append(index)
        index += 1
    return ret


def getRandomList(length, min, max):
    l = []
    for _ in range(length):
        l.append(r(min, max))
    return l


def getms():
    return int(round(time.time() * 1000))


if __name__ == "__main__":
    s = Sorters("bubble")
