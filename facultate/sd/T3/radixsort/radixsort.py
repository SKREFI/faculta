from math import log


def radix(inp, BASE=1000):
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


if __name__ == "__main__":
    with open('radixsort.in', 'r') as f:
        inp = [int(x.strip()) for x in f.readline().split()]
        n = inp[0]
        a = inp[1]
        b = inp[2]
        c = inp[3]
    arr = [0] * n
    arr[0] = b
    for i in range(1, n):
        arr[i] = (a * arr[i-1] + b) % c

    # arr = radix(arr, int(log(c, 2)))
    arr.sort()

    with open('radixsort.out', 'w') as f:
        for x in arr[0::10]:
            f.write(str(x) + ' ')
