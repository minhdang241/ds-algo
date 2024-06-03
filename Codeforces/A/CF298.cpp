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
    string str;
    cin >> str;
    int s = 0, t = 0;
    if (str.find('R') != string::npos && str.find('L') != string::npos) {
        REP(i,0,n-1) {
            // cout << str[i];
            if (str[i] == 'R' && s == 0) {
                s = i; 
            }
            if ((i + 1 <= n - 1) && (str[i+1] == 'L')) {
                t = i;
                break;
            }
        }
        cout << s+1 << " " << t+1;
    } else if (str.find('R') != string::npos) {
        // cout << "here";
        for (int i = 0; i <= n-1; i++) {
          if (str[i] == 'R' && s == 0) s = i;
          if (str[i] == 'R' && (i + 1 <= n-1) && (str[i + 1] == '.')) {
            t = i;
            break;
          }
        }
        cout << s+1 << " " << t+2;

    } else {
        for(int i=n-1; i >= 0; i--) {
          if (str[i] == 'L' && s == 0)
            s = i;
          if (str[i] == 'L' && (i - 1 >= 0) && (str[i - 1] == '.')) {
            t = i;
            break;
          }
        }
        cout << s+1 << " " << t;
    }
    return 0;
}
