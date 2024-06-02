#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    while (cin >> x) {
        if (x == 0) return 0;
        ll i = sqrt(x);
        //cout << i << " " << i*i<< " "<< x << "\n";
        if (i*i == x) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
