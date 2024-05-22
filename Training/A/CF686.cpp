#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, total;
    cin >> n >> total;
    //cout << n << " " << total;
    long long v, ds=0;
    char s;
    REP(i,0,n-1) {
        cin >> s >> v;
        //cout << s << " " << v << endl;
        if (s == '+') total += v;
        else {
            if (v > total) ++ds;
            else total -= v;
        }
    }
    cout << total <<  " " << ds;

    return 0;
}
