def largest_concat_number(numbers):
    longest = max([len(s) for s in numbers])

    even = []
    for i in range(len(numbers)):
        tple = (numbers[i] + '0' * (longest - len(numbers[i])), i)
        even.append(tple)
    even.sort(key=lambda x: x[0], reverse=True)

    ret = ''
    for e in even:
        ret += numbers[e[1]]
    return ret


###
n = int(input())
numbers = []
for i in range(n):
    numbers.append(input())


answer = largest_concat_number(numbers)
print(answer)
