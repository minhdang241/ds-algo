#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s = "";

    char current = 97;
    int ck = 1;

    REP(i,0,n-1) {
        s += current;
        if (current-97+1 < k) {
            current += ck;
        } else {
            current -= k-1;
        }
    }
    cout << s;


    return 0;
}
