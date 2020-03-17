from math import log
from random import randint as r
import random
import time


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


class SorterDetails():
    def __init__(self, name: str, time: str):
        self.name = name
        self.time = time

    def __repr__(self):
        return f'{self.name} -> {self.time} ms'


def quick(inp, low=0, high=-1):
    try:
        def partition(inp, low, high):
            i = low-1
            pivot = inp[high]

            for j in range(low, high):
                if inp[j] < pivot:
                    i = i+1
                    inp[i], inp[j] = inp[j], inp[i]

            inp[i+1], inp[high] = inp[high], inp[i+1]
            return i+1

        if high == -1:
            high += len(inp)
        if low < high:
            pi = partition(inp, low, high)
            quick(inp, low, pi-1)
            quick(inp, pi+1, high)
        return inp
    except:
        pass


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


def systemSort(inp):
    return sorted(inp)


def merge(inp):
    def merge_helper(arr):
        if len(arr) > 1:
            mid = len(arr)//2
            L, R = arr[:mid], arr[mid:]
            merge_helper(L)
            merge_helper(R)

            i = j = k = 0

            while i < len(L) and j < len(R):
                if L[i] < R[j]:
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
                k += 1

            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1

            while j < len(R):
                arr[k] = R[j]
                j += 1
                k += 1
    merge_helper(inp)
    return inp


def test(**args):
    function = args.get('function', systemSort)
    name = args.get('name', 'System')
    debugger = args.get('debugger', False)
    no_tests = args.get('no_tests', 10)
    lists_length = args.get('lists_length', 1000)
    min_num = args.get('min_num', 0)
    max_num = args.get('max_num', 10**3)

    def getms():
        return int(round(time.time() * 1000))

    def getRandomList(length, min, max):
        l = []
        for _ in range(length):
            l.append(r(min, max))
        return l

    times = []
    for i in range(no_tests):
        inp = getRandomList(lists_length, min_num, max_num)
        start = getms()
        result = function(inp)
        stop = getms()
        if result != sorted(inp):
            # raise Exception(Log.fail('Function did a bad job!'))
            Log.fail('Function did a bad job!')
        if debugger:
            Log.debug(f'Test {i+1}/{no_tests} time: {stop-start}')
            Log.debug(f'List: {result}')
        times.append(stop - start)
    Log.succes(f'{name} function\'s time: {sum(times)/len(times)} ms')
    return sum(times)/len(times)


def bogo(inp):
    if len(inp) > 9:
        Log.fail('LIST TO BIG FOR BOGO! This is not supposed to be used lmao')
    while not inp == sorted(inp):
        random.shuffle(inp)
    return inp


def gnomepp(inp):
    def _gnome(inp, limit):
        pos = limit
        while pos > 0 and inp[pos - 1] > inp[pos]:
            inp[pos - 1], inp[pos] = inp[pos], inp[pos - 1]
            pos -= 1

    for pos in range(1, len(inp)):
        _gnome(inp, pos)
    return inp


def gnome(inp):
    i = 0
    while i < len(inp):
        if i == 0 or inp[i] >= inp[i-1]:
            i += 1
        else:
            inp[i], inp[i-1] = inp[i-1], inp[i]
            i -= 1


if __name__ == '__main__':

    pass
