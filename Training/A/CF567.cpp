#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ox;
    int v;
    REP(i,1,n) {
        cin >> v;
        ox.push_back(v);
    }
    REP(i,0,n-1) {
        if (i == 0) {
            cout << ox[i+1]-ox[i] << " " << ox.back()-ox[i] << "\n";
        } else if (i==n-1) {
            cout << ox[i]-ox[i-1] << " " << ox[i]-ox.front() << "\n";
        } else {
            cout << min(ox[i]-ox[i-1],ox[i+1]-ox[i]) << " " << max(ox.back()-ox[i],ox[i]-ox.front()) << "\n";
        }
    }



    return 0;
}
