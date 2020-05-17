def read(filename):
    with open(filename) as f:
        n = int(f.readline())
        arr = [int(x) for x in f.readline().split()]
        instructions = int(f.readline())
        instr = []
        inp = [int(x) for x in f.readline().split()]
        while inp:
            instr.append(tuple(inp))
            inp = [int(x) for x in f.readline().split()]
        return arr, instr


# cea mai mare pozitie pe care se afla X sau -1 daca nu exista
def intrebare0(arr, x):
    first, last, m = 0, len(arr) - 1, len(arr) // 2
    while first <= last:
        if arr[m] <= x:
            first = m + 1
        else:
            last = m - 1
        m = (first + last) // 2
    print(first, last)
    m = (first + last) // 2
    if arr[m] > x:
        m -= 1
    if arr[m] == x:
        return m
    return -1


# cea maia mare pozitie pe care se afla un e <= X, garantat ca X nu e minim
def intrebare1(arr, x):
    first, last, m = 0, len(arr) - 1, len(arr) // 2
    while first < last:
        m = (first + last) // 2
        if arr[m] <= x:
            first = m + 1
        else:
            last = m
    m = (first + last) // 2
    if arr[m] > x:
        return m - 1
    return m


# cea mai mica pozitie pe care se afla un e >= X, garantat ca X nu e maxim
def intrebare2(arr, x):
    first, last, m = 0, len(arr) - 1, len(arr) // 2
    if first < last:
        m = (first + last) // 2
        if arr[m] < x:
            first = m + 1
        else:
            last = m

    m = (first + last) // 2
    if arr[m] < x:
        return m + 1
    return m


if __name__ == "__main__":
    # c = comenzi
    arr, c = read('cautbin/cautbin.in')

    switch = {
        0: intrebare0,
        1: intrebare1,
        2: intrebare2
    }
    with open('cautbin/cautbin.out', 'w') as f:
        for element in c:
            f.write(str(switch[element[0]](arr, element[1]) + 1) + '\n')
