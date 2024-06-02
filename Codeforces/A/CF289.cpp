#include <bits/stdc++.h>
// #define LOCAL
// #include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int l, r;
    int cnt = 0;
    REP(i,0,n-1) {
        cin >> l >> r;
        cnt += (r-l+1);
    }
    int res = cnt % k;

    if (res == 0) cout << 0;
    else cout << (k-res);
    return 0;
}
