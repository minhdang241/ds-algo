#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(5);
    vector<int> B(5);
    REP(i,1,n) {
        A[i%5]++;
    }
    REP(i,1,m) {
        //cout << i << " " << i%5 << endl;
        B[i%5]++;
    }

    //for (const auto&p : B) {
    //    cout << p << endl;
    //}

    ll ans = 0;
    REP(i,0,4) {
        REP(j,0,4) {
            if ((i + j) % 5 == 0) {
                ans += (A[i] * B[j]);
            }
        }
    }
    cout << ans;
    return 0;
}
