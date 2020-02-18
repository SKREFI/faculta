class CommandDest():
    def __init__(self, command, destination):
        self.command = command
        self.destination = destination

    def __repr__(self):
        return "{" + self.command + " -> " + self.destination + "}"


class COL:  # formatare text in python
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

    def blue(self, s):
        return self.OKBLUE+s+self.ENDC

    def green(self, s):
        return self.OKGREEN+s+self.ENDC

    def warning(self, s):
        return self.WARNING+s+self.ENDC

    def fail(self, s):
        return self.FAIL+s+self.ENDC

# Returneaza "litere" al limbajului invalide daca gaseste


def invalidCommands(commands, valid_commands):
    invalid = []
    for c in commands:
        if c not in valid_commands:
            invalid.append(c)
    if len(invalid) == 0:
        return None
    return invalid
