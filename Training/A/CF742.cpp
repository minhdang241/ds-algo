#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v{8,4,2,6};
    long long n;
    cin >> n;
    int i = n % 4;
    if (n == 0) cout << 1;
    else if (i == 0) cout << 6;
    else if (i == 1) cout << 8;
    else if (i == 2) cout << 4;
    else if (i == 3) cout << 2;
    return 0;
}
