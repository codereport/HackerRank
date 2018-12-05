# code_report Solution
# https://youtu.be/E6_-mvn8xIw

def avg(a, b):
    return (sum(a)+b)/len(a)

def solve(n, a):
    a = sorted(a, reverse = True)
    on, off = a[0:n], sum(a[n:])
    while on and avg(on, off) < max(on): on.pop(0)
    print("%.5f"% (avg(on, off)))
