#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    unordered_set<char> st;
    REP(i,0,s.size()-1) {
        st.insert(tolower(s[i]));
    }
    if (st.size() == 26) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}
