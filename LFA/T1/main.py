from MyUtils import *

if __name__ == "__main__":
    C = COL()           # Initializare clasa culori
    d = {}              # Dictionar in care pun NOD -> {Matrici -> Rezultat}
    valid_comands = []  # Storez toate "literele" limabjului
    with open("input.in", "r") as f:
        inp = f.readline().split()
        while inp:
            valid_comands.append(inp[1])
            if inp[0] in d.keys():
                c = CommandDest(inp[1], inp[2])
                d[inp[0]].append(c)
            else:
                d[inp[0]] = []
                c = CommandDest(inp[1], inp[2])
                d[inp[0]].append(c)
            inp = f.readline().split()

    vcs = set(valid_comands)                        # Valid Commands Set
    # Keyurile dictionarului reprezinta noduri neterminale
    print(C.blue("Nodes:"), *d.keys())
    # multimea de litere disponibile
    print(C.blue("Valid commands:"), *vcs)
    current = input(C.blue("Starting node: "))
    commands = input(C.blue("Instructions: "))
    commands = [x for x in commands]
    target = input(C.blue("Target(s): ")).split()  # Intrucerea mai multor noduri ca "finale" este acceptata
    if invalidCommands(commands, valid_comands) != None:
        print(C.fail("Invalids commands found:"), *
              invalidCommands(commands, valid_comands))

    # Pentru vizualizarea optiunilor fiecarui nod (nodurile terminale sunt excluse logic)
    # for c in d.keys():
    #     print(C.blue("Optiuni pentru nodul "), c, sep="", end=":\n")
    #     for obj in d[c]:
    #         print(obj.command, obj.destination, sep=" -> ")

    path = []                           # traseu, optional, dar imi place sa-l vad daca vreau
    for c in commands:                  # pentru fiecare comanda
        commandFound = False            # tinem conta daca gasim pentru afisarea erori
        # pentru fiecare obiect in lista de obiecte in care se poate ajunge din current
        for o in d[current]:
            if c == o.command:          # daca comanda convine
                commandFound = True     #
                current = o.destination       # current devine destinatia comenzii
        if commandFound == False:
            print(C.fail("Command not found"))
        path.append(current)
    if current in target:
        print(C.green("Cuvantul satisface limbajul recunoscut de automat."))
    else:
        print(C.warning("Cuvantul nu satisface limbajul."))
    print(C.blue("Path:"), *path)
