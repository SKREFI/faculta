if __name__ == "__main__":
    n = int(input())
    ret = ''
    inp = input()
    while inp:
        ret += min(inp)
        inp = input()
    print(''.join(sorted([x for x in ret])))
