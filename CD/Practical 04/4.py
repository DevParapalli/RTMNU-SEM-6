from copy import copy, deepcopy

def parse_grammar(inp: str):
    grammar = {}
    for rule in inp.splitlines():
        key, value = rule.split(':')
        if key in grammar:
            grammar[key].extend(value.split('|'))
        else:
            grammar[key] = value.split('|')
    return grammar

def print_grammar(grammar:dict):
    print('---')
    for key, value in grammar.items():
        print(key, ':', "|".join(value))

def _check_left_recursion_singular(inp, grammar):
    for rule in grammar[inp]:
        if rule.startswith(inp):
            return True
    return False

def _remove_left_recursion_singular(inp, grammar):
    if not _check_left_recursion_singular(inp, grammar):
        return (inp, grammar)
    _grammar = deepcopy(grammar)
    non_recursive_productions = [x for x in grammar[inp] if not x.startswith(inp)]
    recursive_productions = [x for x in grammar[inp] if x.startswith(inp)]
    
    non_recursive_productions = [x + inp + "'" for x in non_recursive_productions]
    recursive_productions = [x[1:] + inp + "'" for x in recursive_productions]
    
    _grammar[inp] = non_recursive_productions
    _grammar[inp + "'"] = recursive_productions
    
    recursive_productions.append('ϵ')
    return (inp, _grammar)

def remove_left_recursion(grammar: dict[str, list[str]]):
    # For each production
    _grammar = deepcopy(grammar)
    
    for A_i in reversed(grammar.keys()):
        while True:
            _to_remove_from_alpha_i = []
            for alpha_i in grammar[A_i]:
                # check if production begins with non term.
                for A_j in grammar.keys() - {A_i}:
                    if alpha_i.startswith(A_j):
                        _to_remove_from_alpha_i.append(alpha_i)
                        beta_i = copy(alpha_i)
                        beta_i = beta_i.replace(A_j, '', 1)
                        grammar[A_i].extend([alpha_j + beta_i for alpha_j in grammar[A_j]])
                        
            for x in _to_remove_from_alpha_i:
                grammar[A_i].remove(x)
            if grammar == _grammar:
                break
            _grammar = deepcopy(grammar)
        grammar = _remove_left_recursion_singular(A_i, grammar)[1]
        
    return grammar


# INPUT = "E:E+E|E.E|id"
# INPUT = "E:E+E|T"
INPUT = "S:(L)|a\nL:L,S|S"

GRAMMAR = parse_grammar(INPUT)
print_grammar(GRAMMAR)
print_grammar(remove_left_recursion(GRAMMAR))