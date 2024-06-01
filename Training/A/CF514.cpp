#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int to_int(char c) {
    return c-'0';
}
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin >> x;
    string s = to_string(x);
    string ans = "";
    REP(i,0,s.size()-1) {
        char c = s[i];
        int v = to_int(c);
        int inv_v = 9-v;
        if (i == 0 && inv_v == 0) {
            ans += c;
            continue;
        } else {
            if (inv_v < v) {
                ans += to_string(inv_v);
            } else ans += c;

        }
    }
    cout << ans;


    return 0;
}
