from math import log
from random import randint as r
import time


def swap(a, b):
    a, b = b, a


def quick(inp, low=0, high=-1):
    def partition(inp, low, high):
        i = low-1
        pivot = inp[high]

        for j in range(low, high):
            if inp[j] < pivot:
                i = i+1
                # swap(inp[i], inp[j])
                inp[i], inp[j] = inp[j], inp[i]

        # swap(inp[i+1], inp[high])
        inp[i+1], inp[high] = inp[high], inp[i+1]
        return i+1

    if high == -1:
        high += len(inp)
    if low < high:
        pi = partition(inp, low, high)
        quick(inp, low, pi-1)
        quick(inp, pi+1, high)
    return inp


def bubble(inp):
    n = len(inp)
    for i in range(n):
        for j in range(n - i - 1):
            if inp[j] > inp[j+1]:
                inp[j], inp[j+1] = inp[j+1], inp[j]
    return inp


def radix(inp, BASE=256):
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


def count(inp):
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


class Log():
    end = '\033[0m'

    @classmethod
    def warning(cls, inp):
        print('\033[93m' + inp + cls.end)

    @classmethod
    def fail(cls, inp):
        print('\033[91m' + inp + cls.end)

    @classmethod
    def succes(cls, inp):
        print('\033[92m' + inp + cls.end)

    @classmethod
    def debug(cls, inp):
        print('\033[94m' + inp + cls.end)

    @classmethod
    def getAllStyles(cls):
        for i in range(100):
            print(f'\033[{i}mNumber{i}\033[0m')
