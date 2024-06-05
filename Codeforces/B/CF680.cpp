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
    int n, a;
    cin >> n >> a;
    vector<int> v{-1};
    int x;
    REP(i,0,n-1) {
        cin >> x;
        v.push_back(x);
    }
    int l = a-1, r = a+1;
    int ans = 0;
    if (v[a] == 1) ans++;
    // debug(v);
    // debug(ans);
    while (l > 0 || r <= n) {
        if ((l <= 0 && v[r] == 1) || (v[l] == 1 && r > n )) {
            // cout << l << " " << r << endl;
            ans++;
        }
        if (l > 0 && r <= n && v[l] == 1 && v[r] == 1) {
            ans += 2;
        }
        l--;
        r++;

    }
    cout << ans;
    return 0;
}
