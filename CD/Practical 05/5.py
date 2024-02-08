INPUT = "+-a-aa+ab"

def E():
    global INPUT
    if INPUT[0] == '+':
        print(f"{INPUT:16s} E -> +EE")
        INPUT = INPUT[1:]
        E()
        E()
    elif INPUT[0] == '-':
        print(f"{INPUT:16s} E -> -EE")
        INPUT = INPUT[1:]
        E()
        E()
    elif INPUT[0] == 'a':
        print(f"{INPUT:16s} E -> a")
        INPUT = INPUT[1:]
    elif INPUT[0] == 'b':
        print(f"{INPUT:16s} E -> b")
        INPUT = INPUT[1:]
    if INPUT == "":
        return True
    else:
        return False

print(E())

