from Sorters import *

# def bubble(inp):
# def merge(inp):
# def quick(inp):


def test(function, name, debugger=False, no_tests=10, lists_length=1000, min_num=0, max_num=10**10):
    def getms():
        return int(round(time.time() * 1000))

    def getRandomList(length, min, max):
        l = []
        for _ in range(length):
            l.append(r(min, max))
        return l

    times = []
    for i in range(no_tests):
        inp = getRandomList(lists_length, min_num, max_num)
        start = getms()
        result = function(inp)
        stop = getms()
        if result != sorted(inp):
            raise Exception(Log.fail('Function did a bad job!'))
        if debugger:
            Log.debug(f'Test {i+1} out of {no_tests}\'s time: {stop-start}')
            Log.debug(f'List: {result}')
        times.append(stop - start)
    print(Log.succes(f'{name} function\'s tme: {sum(times)/len(times)}'))


if __name__ == "__main__":
    sorters = {
        'Radix': radix,
        'Count': count
    }

    test(quick, 'Name', debugger=True, no_tests=5,
         lists_length=5, min_num=0, max_num=10)
