#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, es, os;
    cin >> n;
    if (n % 2 == 0) {
        es = ((n + 2) / 2) * ((n-2)/2 + 1);
        os = ((n-1 + 1) / 2) * ((n-1-1)/2 + 1);
    } else {
        es = ((n-1 + 2) / 2) * ((n-1-2)/2 + 1);
        os = ((n + 1) / 2) * ((n-1)/2 + 1);
    }

    cout << (es-os);

    return 0;
}
