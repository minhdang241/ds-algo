#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    REP(i,1,9) {
        REP(j,1,9) {
            REP(m,1,9) {
                REP(n,1,9) {
                    unordered_set<int> s{i,j,m,n};
                    if (s.size() != 4) continue;

                    //cout << i << " " << j  << " " << m << " " << n << endl;
                    //cout << "--------\n";
                    if ((i+j == r1) && (n+m == r2) && (i+n == c1) && (j+m == c2) && (i+m == d1) && (j+n == d2)) {
                        cout << i << " " << j << endl;
                        cout << n << " " << m << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;



    return 0;
}
