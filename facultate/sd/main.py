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

    compare_only_one = True
    #           0        1        2         3         4        5
    names = ['System', 'Count', 'Quick', 'Bubble', 'Radix', 'Merge']

    if compare_only_one:
        print('Choose one using index from:')
        print('  0     1      2      3     4     5')
        print(*names, sep=' ')
        i = int(input())

        args = {
            'function': sorters[names[i]],
            'name': names[i],
            'debugger': False,
            'no_tests': 100,
            'lists_length': 10**3,
            'min_num': 0,
            'max_num': 10**10
        }

        test(**args)
    else:
        times = []

        for sorter in names:
            args = {
                'function': sorters[sorter],
                'name': sorter,
                'debugger': False,
                'no_tests': 100,
                'lists_length': 10**3,
                'min_num': 0,
                'max_num': 10**10
            }
            times.append(SorterDetails(sorter, test(**args)))
        times.sort(key=lambda x: x.time)
        print('\n', *times, sep='\n')
