def sumOfOdd(n, k):
    # cu k numere impare se pote genera maxim k^2 (adica suma de la 1 la 2k+1)
    if n >= k ** 2 and n % 2 == k % 2:
        print('YES')
        return
    print('NO')


# for the resubmission :D
if __name__ == "__main__":
    t = int(input())
    while t:
        inp = [int(x) for x in input().split()]
        i, j = inp[0], inp[1]
        sumOfOdd(i, j)
        t -= 1
