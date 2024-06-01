#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
bool is_prime(int m) {
    REP(i,2,sqrt(m)) {
        if (m % i == 0) return false;
    }
    return true;
}
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i,n+1,50) {
        //cout << i << endl;
        if (is_prime(i)) { 
            if(i == m) {
                cout << "YES";
                return 0;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
