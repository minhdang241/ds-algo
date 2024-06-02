#include <bits/stdc++.h>
#define REP(i,a,b) for(ll i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l, r;
    cin >> l >> r;
    //cout << l << " " << r;
    REP(i,l,r) {
        REP(j,i+1,r) {
            if (gcd(i,j) == 1) {
                REP(k,j+1,r) {
                    if (gcd(j,k) == 1) {
                        if (gcd(i,k) != 1) {
                            cout << i << " " << j << " " << k;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1";
    return 0;
}
