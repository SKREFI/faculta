# https://codeforces.com/problemset/problem/52/C

if __name__ == "__main__":
    n = int(input())
    arr = [int(x.strip()) for x in input().split()]
    m = int(input())

    while m:
        # operation
        o = [int(x.strip()) for x in input().split()]
        i = o[0]
        j = o[1]