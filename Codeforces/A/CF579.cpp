#include <bits/stdc++.h>
#define LOCAL
//#include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin >> x;
    int ans = 0;
    while (x > 0) {
        double power = floor(log2(x));
        x -= pow(2,power);
        ans++;
        //debug(power);
    }
    cout << ans;

    return 0;
}
