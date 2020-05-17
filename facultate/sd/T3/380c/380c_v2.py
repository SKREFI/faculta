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
    v = [0] * len(b)
    for i in range(len(b)):
        v[i] = nrBrakets(b[i:])
    print('\n\n\n', v)
    exit()
    for q in queries:
        try:
            print(v[q[0]] - v[q[1] + 1])
        except:
            print(v[q[0]] - v[q[1]])
