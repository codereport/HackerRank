# code_report Solution

# Solution 1:
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

# Solution 2:
# https://youtu.be/ViILdd8495M

def abbreviation(a, b):
    n, m = len(a), len(b)
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    dp[0][0] = 1
    
    for i in range(n):
        for j in range(m+1):
            if not dp[i][j]: continue;
            if j < m and a[i].upper() == b[j]: dp[i+1][j+1] = 1;
            if not a[i].isupper():             dp[i+1][j  ] = 1;
    
    return 'YES' if dp[n][m] else 'NO'
