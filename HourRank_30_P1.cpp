// code_report Solution

// Solution 1:
// https://youtu.be/uOG3QyxIjso

vector<string> solve (vector<string> names) {
   unordered_set<string> s;
   unordered_map<string, int> m;
   vector<string> ans;
   for (const auto& name : names) {
      auto it = m.find (name);
      if (it != m.end ()) {
         it->second++;
         ans.push_back (name + ' ' + to_string (it->second));
      }
      else {
         m[name] = 1;
         string t;
         bool inserted = false;
         for (auto c : name) {
            t += c;
            auto p = s.insert (t);
            if (!inserted && p.second) {
               inserted = true;
               ans.push_back (t);
            }
         }
         if (!inserted) ans.push_back (t); // very tricky case
      }
   }
   return ans;
}

// Solution 2 (Trie):
// https://youtu.be/VsiP-dTWyG4?t=249

struct trie { 
   unordered_map<char, trie*> m; 
   int count = 0;
};

vector<string> solve(vector<string> names) {
   auto* t = new trie();
   vector<string> res;
   for (const auto& name : names) {
      auto* node = t;
      auto added = false;
      auto p = ""s;
      for (auto c : name) {
         p += c; // prefix
         if (!node->m.count(c)) {
            if (!added) res.push_back(p), added = true;
            node->m[c] = new trie();
         }
         node = node->m[c];
      }
      node->count++;

      if (!added)
         res.push_back(p + (node->count != 1 ? " " + to_string(node->count) : ""));
   }
   return res;
}
