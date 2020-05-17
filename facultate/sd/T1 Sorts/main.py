from Sorters import *
import sys
sys.setrecursionlimit(10**9)

if __name__ == "__main__":
    sorters = {
        # cand zic stabil/instabil nu ma refer la terminologia standard, algoritm 'stabil', ci ca nu da erori
        'Radix': radix,
        'Count': count,
        # 'Bubble': bubble,
        # Segmentation fault error, este instabila, idk why, recursion limit este 10**9 (linia 3)
        # 'Quick': quick,
        'System': systemSort,
        'Merge': merge,
        # normal nu este stabil, again, nu stiu de ce, unele liste nu le sorteaza bine.
        # gnome,     # 'Gnome': gnome,
        'GnomePlus': gnomepp  # gnome optimizat
    }

    # Log.enable = False
    compare_only_one = False
    names = list(sorters.keys())

    if compare_only_one:
        user_have_to_choose_sorter = False
        if user_have_to_choose_sorter:
            print('Choose one using index from:')
            for i in range(len(names)):
                s = (' ' * (len(names[i])//2)) + \
                    str(i) + (' ' * (len(names[i])//2 + 1))
                print(s, end='')
            print()
            print(*names, sep=' ')
            i = int(input())
        else:
            i = 0

        test(**{
            'function': sorters[names[i]],
            'name': names[i],
            'debugger': True,
            'no_tests': 1,
            'lists_length': 10**5,
            'min_num': 0,
            'max_num': 10**10
        })
    else:
        times = []

        for sorter in names:
            args = {
                'function': sorters[sorter],
                'name': sorter
            }
            times.append(SorterDetails(sorter, test(**args)))
        times.sort(key=lambda x: x.time)
        print('\n', *times, sep='\n')
