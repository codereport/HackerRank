# code_report Solution
# https://youtu.be/uOG3QyxIjso

import defaultdict from collections

def solve(names):
    s = set()
    d = defaultdict(int)
    l = list()
    for name in names:
        if name in d:
            d[name] += 1
            l.append(name+" "+str(d[name]))
        else:
            d[name] = 1
            t = ""
            inserted = False;
            for i in range(len(name)):
                t += name[i:i+1]
                if t not in s and not inserted:
                    inserted = True
                    l.append(t)
                s.add(t)
            if not inserted: 
                l.append(name)
    return l
