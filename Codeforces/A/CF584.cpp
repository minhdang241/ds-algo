#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    //if (n==1 && t != 10) {
    //    cout << t;
    //    return 0;
    //}

    //string v = "-1";
    //if (t == 2 && ((n-1) >= 0)) {
    //    v = string(n-1, '1') + "2";

    //} else if (t == 3 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2, '0') + "2";

    //} else if (t == 4 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2, '0') + "4";

    //} else if (t == 5 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2, '0') + "5";

    //} else if (t == 6 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2, '0') + "2";
    //    
    //} else if (t == 7 && ((n-2) >= 0)) {
    //    v = string(n, '7') ;

    //} else if (t == 8 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2, '0') + "8";

    //} else if (t == 9 && ((n-2) >= 0)) {
    //    v = "1" + string(n-2,'0') + "8";

    //} else if (t == 10 && ((n-1) > 0)) {
    //    v = "1" + string(n-1,'0');

    //} else {
    //    v = "-1";
    //}
    string v;
    if (t != 10) {
        v = string(n, '0' + t);
    } else {
        if (n < 2) {
            v = "-1"; 
        } else v = "1" + string(n-1, '0');
    }
    cout << v;

    return 0;
}
