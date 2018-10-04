# code_report Solution
# https://youtu.be/DW92IHf8KK8

memo = set()
possible = False

def abbreviation(a, b):
    global possible, memo
    possible = False
    memo.clear()
    rec(a,b)
    return "YES" if possible else "NO"

def rec(a, b):
    global possible, memo
    if (possible or len(a) < len(b)):
        return
    if (len(b) == 0):
        if (a.islower() or len(a) == 0):
            possible = True
        return
    
    t = a+'#'+b
    if (t in memo):
        return
    memo.add(t);
    
    fc = a[0:1] # first char
    a = a[1:]
    if (fc.islower()):
        rec(a,b)
    if (fc.upper() != b[0:1]):
        return
    b = b[1:]
    rec(a,b)
    
    return
