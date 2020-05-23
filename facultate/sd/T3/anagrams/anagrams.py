# https://csacademy.com/contest/archive/task/anagrams

from collections import defaultdict

if __name__ == "__main__":
    n = int(input().strip())
    d = defaultdict(lambda: 0)

    while n:
        d[tuple(sorted(input().strip()))] += 1
        n -= 1
        
    print(max(list((d.values()))))
