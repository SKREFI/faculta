
# start = "ab"
# end = "da"
# start = list(start)


# i = len(start) - 1
# results = []
# st = "".join(start)
# while True:
#     if start[i] != 'z':
#         start[i] = alf[alf.find(start[i]) + 1]
#     elif start[i] == 'z':
#         i -= 1
#     if i == -1:
#         break
#     st = "".join(start)
#     if st > end:
#         break

#     results.append(st)

alf = "abcdefghijklmnopqrstuvwxyz"


def find(n, s1, s2, evil):
    s1 = list(s1)
    results = []
    n -= 1
    st = "".join(s1)
    while True:
        if s1[n] != 'z':
            s1[n] = alf[alf.find(s1[n]) + 1]
        elif s1[n] == 'z':
            s1[n] = 'a'
            s1[n-1] = alf[alf.find(s1[n]) + 1]
            
        if n == -1:
            break
        st = "".join(s1)
        if st > s2:
            break
        results.append(st)

    return results


print(find(2, "aa", "da", "b"))
