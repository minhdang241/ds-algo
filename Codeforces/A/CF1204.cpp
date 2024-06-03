#include <bits/stdc++.h>
#define LOCAL
// #include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int _max = -1;
    bool has_extra = false;
    REP(i,0,s.size()-1) {
        if (s[i] == '1') {
            if(_max == -1) {
                _max = s.size() - i - 1;
            } else {
                has_extra = true; 
                break;
            }
        } 
    }
    if (_max == -1) {
        cout << 0;
        return 0;
    }

    int ans = 1;
    // debug(_max);
    // debug(has_extra);
    if (has_extra) {
        ans += (_max / 2);

    } else {
        ans += ceil((_max*1.0 / 2)) - 1;
    }
    cout << ans;

    return 0;
}
