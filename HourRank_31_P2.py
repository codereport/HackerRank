# code_report Solution
# 

def avg(a, b):
    return (sum(a)+sum(b))/len(a)

def solve(n, a):
    a   = sorted(a, reverse = True)
    on  = a[0:n]
    off = a[n:]
    while len(on) > 0 and avg(on, off) < max(on): on.pop(0)
    print("%.5f"% (avg(on, off)))
