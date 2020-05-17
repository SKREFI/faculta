# https://codeforces.com/contest/381/problem/A

if __name__ == "__main__":
    n = int(input())
    arr = [int(x.strip()) for x in input().split()]

    p1 = 0
    p2 = 0
    parityOfSereja = n % 2

    while n:
        if n % 2 == parityOfSereja:
            if arr[0] > arr[-1]:
                aux = arr.pop(0)
                p1 += aux
            else:
                aux = arr.pop(-1)
                p1 += aux
        else:
            if arr[0] > arr[-1]:
                aux = arr.pop(0)
                p2 += aux
            else:
                aux = arr.pop(-1)
                p2 += aux
        n -= 1
    print(p1, p2)
