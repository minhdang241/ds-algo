#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s, s2, s3;
    cin >> s1;
    cin >> s3;
    auto it = s1.find('|');
    s = s1.substr(0,it);
    s2 = s1.substr(it+1, s1.size()-it);
    //cout << s << " " << s2 << endl;
    string ans;
    if (s.size() < s2.size()) {
        int diff = s2.size() - s.size();
        if (s3.size() < diff) {
            //cout << diff << endl;
            //cout << "here\n";
            ans = "Impossible";
        } else {
            if ((s3.size() - diff) % 2 != 0) {
                ans = "Impossible";
            } else {
                int half = (s3.size() - diff) / 2;
                ans = s + s3.substr(0,diff+half) + "|" + s2 + s3.substr(diff+half, half);
            }
        }
    } else if (s.size() > s2.size()) {
        int diff = s.size() - s2.size();
        if (s3.size() < diff) {
            ans = "Impossible";
        } else {
            if ((s3.size() - diff) % 2 != 0) {
                ans = "Impossible";
            } else {
                int half = (s3.size() - diff) / 2;
                ans = s + s3.substr(diff+half, half) + "|" + s2 + s3.substr(0,diff+half);

            }
        }
    } else {
        if (s3.size() % 2 != 0) {
            ans = "Impossible";
        } else {
            int half_length = s3.size() / 2;
            ans = s + s3.substr(0, half_length) + "|" + s2 + s3.substr(half_length, half_length);
        }
    }
    cout << ans;


    return 0;
}
