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
    int n;
    cin >> n;
    int x;
    unordered_map<int, int> m;
    REP(i,0,n-1) {
        cin >> x;
        m[x]++;
    }
    int ma = 0;
    int total = 0;
    for (const auto& p: m) {
        if (p.second > 1) {
            ma = max(ma, p.second);
        }
        total += p.second;
    }

//    debug(m);
    if (2*ma - total <= 1) cout << "YES";
    else cout << "NO";
    return 0;
}
