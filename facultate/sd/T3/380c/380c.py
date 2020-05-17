# https://codeforces.com/problemset/problem/380/C
# sereja And Brackets


def readData():
    brack = input()
    m = int(input().strip())
    queries = []

    while m:
        inp = [int(x) - 1 for x in input().split()]
        queries.append(inp)
        m -= 1
    return brack, queries


def nrBrakets(inp):
    print(inp, end=' ')
    stack = 0
    total = 0
    for e in inp:
        if e == '(':
            stack += 1
        elif stack > 0:
            stack -= 1
            total += 1
    return total * 2


if __name__ == "__main__":
    b, queries = readData()
    for query in queries:
        print((b[query[0]:query[1] + 1]))


# a
# bc
# ab
# abcdefghijkl
# hijkl
# efghijk
# bcdefghij



# abcdefghijkl
# 7
# 1 1
# 2 3
# 1 2
# 1 12
# 8 12
# 5 11
# 2 10
