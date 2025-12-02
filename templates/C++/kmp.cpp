#include <string>
#include <vector>
#include <cassert>
auto build_lps(std::string& s) -> std::vector<int> {
	auto N = s.size();
	auto lps = std::vector<int>(N, 0);
	auto j = 0, i = 1;
	while (i < N) {
		if (s[i] == s[j]) {
			j++;
			lps[i] = j;
			i++;
		} else {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				lps[i] = 0;
				i++;				
			}
		}
	}
	return lps;
}

auto kmp(std::string& s, std::string& p) -> int {
	auto N = s.size();
	auto M = p.size();
	auto lps = build_lps(p);
	auto j = 0, i = 0;
	auto cnt = 0;
	while (i < N) {
		if (s[i] == p[j]) {
			i++;
			j++;
		} else {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
		if (j == M) {
			cnt++;
			j = lps[j - 1];
		}
	}
	return cnt;
}
int main(void) {
    auto s = std::string("abcabcalsdkfj;lab");
    auto p = std::string("ab");
    auto ret = kmp(s, p);
    assert(ret == 3);
}