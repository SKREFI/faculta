from collections import namedtuple

Friend = namedtuple('Friend', 'money ff')

if __name__ == "__main__":
    inp = [int(x.strip()) for x in input().split()]
    n = inp[0]
    d = inp[1]

    friends = []
    while n:
        inp = [int(x.strip()) for x in input().split()]
        friends.append(Friend(inp[0], inp[1]))
        n -= 1

    friends.sort(key=lambda x: x.money, reverse=True)

    # print(*friends, sep='\n')

    max_m = friends[0].money  # max money for the current group
    groups = []  # here we store max ff (frined factor) for each grou[]
    group = [friends[0].ff]  # temp list where we store each group
    for f in friends[1:]:
        if f.money + d <= max_m:
            # daca este mai mic nu e ok deci spargem grupul
            groups.append(sum(group))
            max_m = f.money
            group = [f.ff]
        else:
            group.append(f.ff)

    groups.append(sum(group))

    print(max(groups))
