#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<char, int> m;
    int x;
    REP(i,0,3) {
        cin >> x;
        m[i+1] = x;
    }
    string s;
    cin >> s;
    int ans = 0;
    REP(i,0,s.size()-1) {
        ans += m[s[i]-'0'];
    }
    cout << ans;

    return 0;
}
