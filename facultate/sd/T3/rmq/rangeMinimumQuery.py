def solve(filename):
    with open(filename, 'r') as f:
        with open('rmq.out', 'w') as fw:
            inp = [x for x in f.readline().split()]
            n, m = int(inp[0]), int(inp[1])
            arr = []
            for _ in range(n):
                arr.append(int(f.readline()))
            for _ in range(0, m):
                inp = [x.strip() for x in f.readline().split()]
                a, b = int(inp[0]), int(inp[1])
                fw.write(str(min(arr[a-1:b])) + '\n')


if __name__ == "__main__":
    solve('rmq.in')
