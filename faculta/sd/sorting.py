from math import log
from random import randint as r
import time


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
    for _ in range(1):
        l = getRandomList(5, 0, 10**1)
        base = r(2, 1000)
        # start = getms()
        # radix(l, 256)
        # stop = getms()
        # print("Radix: ", stop - start)
        # start = getms()
        # l.sort()
        # stop = getms()
        # print("Nativ: ", stop - start)
        print(countSort(l))
