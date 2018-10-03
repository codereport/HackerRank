// code_report Solution
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
