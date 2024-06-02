#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v;
    int x;
    REP(i,0,2*n) {
        cin >> x;
        v.push_back(x);
    }

    REP(i,0,2*n) {
        if (i%2 != 0 && k > 0) {
            //cout << "debug: " << v[i] << " " << v[i] - v[i-1] << endl;
            if ((v[i] - v[i-1]) >= 2 && (v[i]-v[i+1]) >= 2) {
                cout << v[i]-1 << " ";
                k--;
            } else {
                cout << v[i] << " ";
            }
        } else {
            cout << v[i] << " ";
        }
    }

    return 0;
}
