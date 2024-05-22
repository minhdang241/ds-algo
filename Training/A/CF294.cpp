#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, lv;
    vector<int> ls{-1};
    cin >> n;
    REP(i,1,n) {
        cin >> lv;
        ls.push_back(lv);
    }

    cin >> m;
    int  y, x, l, r;
    REP(i,1,m) {
        cin >> x >> y;
        l = max(y - 1, 0);
        r = max(ls[x] - y, 0);
        ls[x] = 0;
        if (x - 1 >= 1) {
            ls[x-1] += l;
        }
        if (x + 1 <= n) {
            ls[x+1] += r;
        }
        //cout << "left: " << l << " right: " << r << endl;
    }
    REP(i,1,n) {
        cout << ls[i] << "\n";
    }

    return 0;
}
