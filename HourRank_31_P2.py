# code_report Solution
# 

def avg(a, b):
    return (sum(a)+sum(b))/len(a)

def solve(n, a):
    a = sorted(a, reverse = True)
    on, off = a[0:n], a[n:]
    while on and avg(on, off) < max(on): on.pop(0)
    print("%.5f"% (avg(on, off)))
