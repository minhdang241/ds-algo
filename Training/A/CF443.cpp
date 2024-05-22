#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    if ((s.size() - 2) <= 0) {
        cout << 0;
        return 0;
    }
    s = s.substr(1, s.size()-2);
    unordered_set<char> st;
    REP(i,0,s.size()-1) {
        if (s[i] == ',' or isspace(s[i]) != 0) continue;
        else st.insert(s[i]);
    }
    //for (const auto& c: st) {
    //    cout << c << "\n";
    //}
    cout << st.size();
    return 0;
}
