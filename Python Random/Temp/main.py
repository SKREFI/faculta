from math import log
from random import randint as r
import main_two


def radix(inp, BASE):
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


def getRandomList(length, min, max):
    l = []
    base = r(2, 1000)
    for _ in range(length):
        l.append(r(min, max))
    return l, base


if __name__ == "__main__":
    for _ in range(5):
        l, base = getRandomList(5, 0, 10**20)
        print(l, base)
        print(radix(l, base) == sorted(l))
