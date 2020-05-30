# https://csacademy.com/contest/interview-archive/task/array-intersection/statement/
# O (n1 + n2) => 100%

def array_intersection(a1, a2):
    from collections import defaultdict
    d = defaultdict(lambda: 0)
    for e in a1:
        d[e] += 1
    ret = []
    for e in a2:
        if d[e] != 0:
            ret.append(e)
            d[e] -= 1
    print(len(ret))
    return ret if len(ret) > 0 else 0


if __name__ == "__main__":
    n, m = map(int, input().split(' '))
    a1 = list(map(int, input().split(' ')))
    a2 = list(map(int, input().split(' ')))
    intersection = array_intersection(a1, a2)
    print(' '.join(map(str, intersection)))
