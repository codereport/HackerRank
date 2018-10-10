# code_report Solution
# https://youtu.be/uOG3QyxIjso

# Solution 1:

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

#Solution 2: 

def solve(names):
    trie = {}
    res = []
    for name in names:
        node = trie
        printed = False
        for i, x in enumerate(name, start=1):
            if x not in node:
                if not printed: 
                    res.append(name[:i])
                    printed = True
                node[x] = defaultdict(int)

            node = node[x]

        node['count'] += 1

        if not printed: 
            res.append (name + (' '+str(node['count']) if node['count']!=1 else ''))
    return res
