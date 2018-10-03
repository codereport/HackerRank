// code_report Solution
// 

using namespace std;

unordered_set<string> memo;
bool possible;

void rec (string A, string B) {
    if (possible || A.size () < B.size ()) return;
    if (B.empty ()) {
        if (all_of(A.begin(), A.end(), [](auto e) { return islower(e); })) 
            possible = true;
        return;
    }
    
    if (memo.count (A+'#'+B)) return;
    memo.insert (A+'#'+B);
    
    if (toupper(A[0]) != B[0]) {
        if (isupper(A[0])) return;
        A.erase (0,1);    
        rec (A, B); 
    } else {
        if (islower(A[0])) {
            A.erase (0,1);
            rec (A, B); 
        } else {
            A.erase (0,1); 
        }
        B.erase (0,1);
        rec (A, B);
    }
    return;
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    possible = false;
    memo.clear ();
    rec (a, b);
    return possible ? "YES" : "NO";
}
