from Sorters import *
import sys
sys.setrecursionlimit(10**9)

if __name__ == "__main__":
    sorters = {
        'Radix': radix,
        'Count': count,
        'Bubble': bubble,
        'Quick': quick,
        'System': systemSort,
        'Merge': merge
    }

    test_one = True

    #                  0        1        2         3         4        5
    names = ['System', 'Count', 'Quick', 'Bubble', 'Radix', 'Merge']

    if test_one:
        print('Choose one using index from:')
        print('  0     1      2      3     4     5')
        print(*names, sep=' ')
        i = int(input())
        test(sorters[names[i]], names[i], debugger=False, no_tests=100,
             lists_length=10**3, min_num=0, max_num=10**10)
