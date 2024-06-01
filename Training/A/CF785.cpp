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
    unordered_map<string, int> m{
        {"Icosahedron" , 20},
        {"Dodecahedron" , 12},
        {"Octahedron" , 8},
        {"Cube" , 6},
        {"Tetrahedron" , 4}
    };
    int ans = 0;
    string t;
    REP(i,0,n-1) {
        cin >> t;
        ans += m[t];
    }
    cout << ans;


    return 0;
}
