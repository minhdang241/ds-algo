#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a;
    cin >> n >> m >> a;
    cout << fixed << (ll)(ceil(m*1.0/a) * ceil(n*1.0/a));
    return 0;
}
