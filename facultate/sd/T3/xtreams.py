def four_xtremes(a, b, c, d):
    return abs(min([a, b, c, d]) - max([a, b, c, d]))
    

if __name__ == "__main__":
    a, b, c, d = map(int, input().split())
    print(four_xtremes(a, b, c, d))
