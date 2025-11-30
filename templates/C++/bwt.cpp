#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

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

auto bwt_decode2(std::string s) -> std::string {
    auto N = s.size();
    auto first_column = s;
    std::sort(first_column.begin(), first_column.end());

    auto cTable = std::map<char, int>();
    for (const auto& c: first_column) {
        cTable[c]++;
    }

    auto cumulative_count = 0;
    for (auto& [c, count]: cTable) {
        auto current_count = count;
        count = cumulative_count;
        cumulative_count += current_count;
    }

    auto current_index = 0;
    for (auto i = 0; i < N; i++) {
        const auto c = s[i];
        if (c == '#') {
            current_index = i;
            break;
        }
    }

    auto rankTable = std::vector<std::unordered_map<char, int>>(N + 1);
    for (auto i = 0; i < N; i++) {
        rankTable[i + 1] = rankTable[i];
        rankTable[i + 1][s[i]]++;
    }

    auto decoded_string = std::string();
    decoded_string.reserve(N);
    for (auto i = 0; i < N; i++) {
        const auto c = s[current_index];
        decoded_string += c;
        auto rank = rankTable[current_index][c];
        current_index = cTable[c] + rank;
    }
    std::reverse(decoded_string.begin(), decoded_string.end());
    return decoded_string;
}

auto print(std::vector<char> vec) {
    for (const auto& c: vec) {
        std::cout << c << "";
    }
    std::cout << "\n";

}

int main() {
    auto s = "BABANAS#";
    std::cout << "Original: " << s << "\n";
    auto enc = bwt_encode(s);
    std::cout << "Encode: " << enc << "\n";
    auto dec = bwt_decode(enc);
    assert(dec == s);
    std::cout << "Decode: " << dec << "\n";
    auto dec2 = bwt_decode2(enc);
    std::cout << "Decode2: " << dec2 << "\n";
    assert(dec == dec2);
}