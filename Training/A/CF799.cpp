#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t,k,d;
    cin >> n >> t >> k >> d;
    int totalT = ceil(n*1.0/k) * t;
    int totalT2 = d; 
    int left = n - floor(d*1.0/t)*k;
    totalT2 += ceil(left/(2.0*k))*t;
    
    //cout << totalT << " " << totalT2 << "\n";
    if (totalT > totalT2) {
        cout << "YES";
    } else cout << "NO";

    return 0;
}
