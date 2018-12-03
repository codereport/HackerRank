# code_report Solution
# https://youtu.be/XKQQYCScP0U

def solve(h, w, l):
    p = max(a - b//4 for a, b in zip(w, l))
    return max(0, p - h)
