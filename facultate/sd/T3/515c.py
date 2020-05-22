from math import factorial


def f(x):
    sum = 1
    for e in x:
        sum *= factorial(e)
    return sum


if __name__ == "__main__":
    n = int(input().strip())
    x = int(input().strip())
    digits = [int(x) for x in str(x)]
    value = f(digits)

    ans = [2] * 15  # limit

    print(ans)
