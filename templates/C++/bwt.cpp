

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

auto bwt_encode(std::string s) -> std::string {
    auto N = s.size();
    auto table = std::vector<std::vector<char>>(N, std::vector<char>(N, '\0'));
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            table[i][j] = s[j];
        }
        auto new_s = std::vector<char>(N, '\0');
        for (auto j = 1; j < N; j++) {
            new_s[j] = s[j - 1];
        }
        new_s[0] = s.back();
        auto oss = std::ostringstream();
        for (auto j = 0; j < N; j++) {
            oss << new_s[j];
        }
        s = oss.str();
    }
    std::sort(table.begin(), table.end());
    auto oss = std::ostringstream();
    for (auto i = 0; i < N; i++) {
        oss << table[i].back();
    }
    return oss.str();

}

auto print(std::vector<char> vec) {
    for (const auto& c: vec) {
        std::cout << c << "";
    }
    std::cout << "\n";

}
auto bwt_decode(std::string s) -> std::string {
    auto N = s.size();
    auto table = std::vector<std::vector<char>>(N, std::vector<char>(N, '\0'));
    for (int j = N; j >= 0; j--) {
        for (auto i = 0; i < N; i++) {
            table[i][j] = s[i];
        }
        std::sort(table.begin(), table.end());
    }
    auto oss = std::ostringstream();
    for (auto i = 0; i < N; i++) {
        if (table[i].back() == '#') {
            for (auto j = 0; j < N; j++) {
                oss << table[i][j];
            }
            return oss.str();
        }
    }
    return "";
}

int main() {
    auto s = "BABANAS#";
    std::cout << "Original: " << s << "\n";
    auto ret = bwt_encode(s);
    std::cout << "Encode: " << ret << "\n";
    auto dec_ret = bwt_decode(ret);
    std::cout << "Decode: " << dec_ret << "\n";
}