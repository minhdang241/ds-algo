#include <bits/stdc++.h>
#include <string>
#define LOCAL
//#include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int cnt = 0;
    cin >> s;
    while (s.size() > 1) {
        ll sum = 0;
        REP(i,0,s.size()-1) {
            sum += s[i] - '0';
        }
        cnt++;
        s = to_string(sum);
    } 
    cout << cnt;
    
    return 0;
}
