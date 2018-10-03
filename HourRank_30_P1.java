// code_report Solution
// https://youtu.be/uOG3QyxIjso

public static List<String> solve(List<String> names) {
    HashSet<String>          s = new HashSet<>();
    HashMap<String, Integer> m = new HashMap<>();
    List<String>             l = new ArrayList<>();
    for (String name : names) {
        if (m.containsKey(name)) {
            int n = m.get(name);
            m.put(name, n+1);
            l.add(name + " " + Integer.toString(n+1));
        } else {
            m.put(name, 1);
            String t = "";
            boolean inserted = false;
            for (char c : name.toCharArray()) {
                t += c;
                if (!inserted && !s.contains(t) ) {
                    inserted = true;
                    l.add(t);
                }
                s.add(t);
            }
            if (!inserted) l.add(t);
        }
    }
    return l;
}
