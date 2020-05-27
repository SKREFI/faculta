f = open('matrice3/matrice3.in', 'r')


def getInt():
    return int(f.readline().strip())


def getArray():
    return [int(x.strip()) for x in f.readline().split()]


if __name__ == "__main__":
    inp = getArray()
    lini = inp[0]
    coloane = inp[1]
    querys = inp[2]

    m = []
    # citire matrice
    while lini > 0:
        linie = [int(x) for x in f.readline().strip()]
        m.append(linie)
        lini -= 1

    puncte = []

    while querys:
        q = getArray()
        p1 = (q[0], q[1])
        p2 = (q[2], q[3])
        querys -= 1

    print()

    print(*m, sep='\n')
