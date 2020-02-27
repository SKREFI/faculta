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


def countSort(inp):
    d = {}
    for i in inp:
        if i in d.keys():
            d[i] += 1
        else:
            d[i] = 1
    print(d.keys())
    l = list(d.keys()).sort()
    print("after:  ", l)


def getRandomList(length, min, max):
    l = []
    for _ in range(length):
        l.append(r(min, max))
    return l


def getms():
    return int(round(time.time() * 1000))


if __name__ == "__main__":
    for _ in range(1):
        l = getRandomList(20, 0, 10**1)
        base = r(2, 1000)
        # start = getms()
        # radix(l, 256)
        # stop = getms()
        # print("Radix: ", stop - start)
        # start = getms()
        # l.sort()
        # stop = getms()
        # print("Nativ: ", stop - start)

        countSort(l)
