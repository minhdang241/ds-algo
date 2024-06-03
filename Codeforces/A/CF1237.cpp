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
    int n;
    cin >> n;
    int a;
    bool up = true;
    REP(i,0,n-1) {
        cin >> a;
        if (a % 2 == 0) {
            cout << a / 2 << endl;
        } else {
            if (up) {
                cout << (int) ceil(a*1.0/2) << endl;
            } else {
                cout << (int) floor(a*1.0/2) << endl;
            }
            up = !up;
        }
    }


    return 0;
}
