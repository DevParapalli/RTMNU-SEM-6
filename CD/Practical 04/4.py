INPUT = "E:E+E|E.E|id"


GRAMMAR = {}

inp, rules = INPUT.split(':')
rules = rules.split('|')
GRAMMAR[inp] = rules

print(GRAMMAR)

def check_left_recursion(inp, grammer):
    for rule in grammer[inp]:
        if rule.startswith(inp):
            return True
    return False

def remove_left_recursion(inp, grammar):
    pass

print(check_left_recursion('E', GRAMMAR))