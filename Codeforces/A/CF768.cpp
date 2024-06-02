#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, _min = pow(10,9)+1, _max=-1;
    unordered_map<int, int> s;
    cin >> n;
    REP(i,1,n) {
        cin >> x;
        _max = max(_max, x);
        _min = min(_min, x);
        s[x] += 1;
    }
    if (s.size() <= 2) cout << 0;
    else {
        int ans = 0;
        for (const auto& p: s) {
            if (p.first != _max && p.first != _min) {
                ans += p.second;
            }
        }
        cout << ans;
    }
    return 0;
}
