#include <bits/stdc++.h>
#define LOCAL
// #include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
#define IREP(i,a,b) for(int i=a; i >= b; i--)
using namespace std;

typedef long long ll;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Solution: try to find the longest increasing order
    int n;
    cin >> n;

    int x;
    int ans = 0;
    vector<int> v;
    REP(i,0,n-1) {
        cin >> x;
        v.push_back(x);
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    REP(i,0,n-1) {
        int w=1, l=i-1,r = i+1;
        while(l >= 0 && v[l] <= v[l+1]) {
            // cout << w << endl;
            w++;
            l--; 
        }
        while(r < n && v[r] <= v[r-1]) {
            w++;
            r++; 
        }
        ans = max(ans, w);
    }

    cout << ans;
    return 0;
}
