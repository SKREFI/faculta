from Automaton import Automaton, Log
from CFG import CFG

if __name__ == "__main__":
    Log.enable = False
    Log.enable_print = False

    automat = Automaton.buildFromFile('data/automat_input.in')
    print(automat.getRegex())


'''
Problema 5 pe steroizi
A B C
a b c
A
A
A a A
A b A
A c A
A b C
C a A
C b B
A a B
B b A
B a B
'''
"""
Problem 2
1 2 3 4 5
a b
1
3 4 5
1 a 2
2 b 4
2 c 3
2 d 5
"""
"""
Problem 4
A B C D
a b
A
A B C
A b A
A a B
B a B
B b C
C b C
C a D
D a D
D b D
"""
"""
Problem 5
A B C
a b
A
A
A a B
A b C
B b A
C a A
C b B
"""
"""
My test
1 2 3 4 5 6 7 8 9
a
1
8
1 a 2
2 a 2
2 a 5
2 a 4
5 a 6
6 a 4
4 a 9
2 a 3
2 a 7
3 a 7
7 a 2
7 a 8
"""
'''
Problem-06
A B C
a b
A
C
A a C
A b B
C a B
B a B
B b B
'''
