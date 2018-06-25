# code_report Solution
# https://youtu.be/HEizjKb7LjY

def minuteToWinIt(a, k):
    j = 0
    m = dict()
    for e in a:
        m[e-j] = m.get(e-j, 0) + 1
        j += k
    return len(a) - max(m.values())
