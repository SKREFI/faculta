# # # # # # L2 P1
# # # # # # str = "Problemele cu șiruri de caractedf nu sunt gdfle!"
# # # # # # tbr, replace = input(), input() # tbr = to be replaced
# # # # # #
# # # # # # print(str.replace(tbr, replace))
# # # # # #
# # # # #
# # # # # # L2 P2
# # # # # str = input()
# # # # # l = [x[0].upper() + x[1:] for x in str.split()]
# # # # #
# # # # # print(" ".join(l))
# # # #
# # # # # L2 P3 bullshit, foloseste replace si gata
# # # #
# # # # # L2 P4
# # # # str1 = "abcdefghh"
# # # # str2 = "hhgfedcba"
# # # # l = list(str2)
# # # # for i in list(str1):
# # # #     for j in range(len(str2)):
# # # #         if str2[j] == i:
# # # #             l[j] = '*'
# # # #
# # # # print(" ".join(l))
# # # # for i in l:
# # # #     if i is not'*':
# # # #         print("not anagram")
# # # #         break
# # #
# # #
# # # # L2 P5
# # #
# # # def cript(x, k):
# # #     return chr((((ord(x) - 97) + k) % 26) + 97)
# # # def decript(x, k):
# # #     return chr((((ord(x) - 97) - k) % 26) + 97)
# # #
# # # print(cript('a', 1))
# # # print(cript('b', 2))
# # # print(cript('z', 1))
# # # print(decript('a', 1))
# #
# #
# # # L2 P6
# #
# # str = "Astăzi am cumpărat pâine de 5 RON, pe lapte am dat 10 RON, iar de 15 RON am cumpărat niște cașcaval. De asemenea, mi-am cumpărat și niște papuci cu 50 RON!"
# # l = str.replace('!','').replace(',','').split()
# # print(l)
# # sum = 0
# # i = 0
# # for s in l:
# #     if s == "RON":
# #         sum += int(l[i-1])
# #     i += 1
# # print(sum)
# #
#
# # L2 P12
#
# str = "baa <op> ab"
# str2 = str.split(" <op> ")
# if len(str) != len(str2):
#     str, str2 = str2[0], str2[1]
#     ultima = str[len(str)-1:]   # ultima litera din primul cuvant
#     prima = str2[:len(str2)-1]  # prima litera din al doilea cuvant
#     if prima == ultima:
#         while str2[:1] == prima:
#             str2 = str2[len(str2)-1:]
#         # print(str[len(str)-1:])
#         while str[len(str)-1:] == prima:
#             str = str[:1]
#
# print(str + str2) # gata fmm de exercitiu, sper macar ca asta era, sper ca nu sunt mai multi operatori intr-un sir, daca sunt, se face functie si se apeleaza recursiv
#


