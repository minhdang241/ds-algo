#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a,b;
    int y = 7 - x;
    cin >> a >> b;
    REP(i,1,n-1) {
        cin >> a >> b;
        //cout << y << " " << a << " " << b << endl;
        if (y == a || y == b || y == (7-a) || y == (7-b)) {
            cout << "NO";
            return 0;
        }
        y = 7 - y;
    }
    cout << "YES";
    return 0;
}
