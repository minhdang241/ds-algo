#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int x, ans = 0;
    char prev = 'a';
    REP(i,0,s.size()-1) {
        x = abs(s[i] - prev);
        prev = s[i];
        //cout << x << " " << 26-x << endl;
        if ((26-x) > 0) ans += min(x, 26-x);
        else ans += x;

    }
    cout << ans;

    return 0;
}
