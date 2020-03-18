
'''
Complexity: O(n)
Not a lot to talk about, liniar time, itereting thorugh each element
'''


def stone_soup_3():

    def function(inp):
        i = sum = 0
        while i < len(inp) - 1:
            # find the smallest price
            while i < len(inp) - 1 and inp[i + 1] <= inp[i]:
                i += 1
            smallest = i
            i += 1

            # find the biggest
            while i < len(inp) and inp[i] >= inp[i - 1]:
                i += 1
            biggest = i - 1

            # this would modify the list so instead of price, when
            inp[smallest] = inp[smallest], 'B'  # B, S = Buy, Sell
            inp[biggest] = inp[biggest], 'S'
            sum = sum - inp[smallest][0] + inp[biggest][0]

        return inp, sum

    prices = [100, 180, 260, 310, 40, 535, 695]
    prices, sum = function(prices)

    print(f'Profit is: {sum}', '\n\n')

    print(*prices, sep='\n')


def intervale(inp, add):
    l = []
    for t in inp:
        l.extend(range(t[0], t[1]+1))
    l.extend(range(add[0], add[1]+1))
    return(set(l))


if __name__ == '__main__':
    inp = [(1, 5), (10, 15), (25, 27)]
    inp = list(intervale(inp, (13, 17)))
    print(inp)
    intervals = []
    start = 0
    i = 0
    while i < len(inp)-1:
        if inp[i] + 1 == inp[i+1]:
            i += 1
        else:
            inter = inp[start], inp[i]
            intervals.append(inter)
            start = i + 1
            i += 1
    inter = inp[start], inp[-1]
    intervals.append(inter)

    print(intervals)
