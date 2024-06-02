#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<int> v;
    getline(cin, s);
    REP(i,0,s.size()-1) {
        if (s[i] == '+') continue;
        v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end());
    REP(i,0,v.size()-1) {
        if (i != 0) cout << "+";
        cout << v[i];
    }
    return 0;
}
