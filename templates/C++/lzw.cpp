#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


template<typename T>
auto print(std::vector<T> vec) -> void {
    for (const auto& v: vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

auto lzw(std::string& s) -> std::vector<int> {
    auto dict = std::unordered_map<std::string, int>();
    for (auto i = 0; i < 256; i++) {
        dict[std::string(1, i)] = i;
    }
    auto ret = std::vector<int>();
    auto p = std::string();
    auto dict_size = 256;
    for (const auto& c: s) {
        auto pc = p + c;
        if (dict.contains(pc)) {
            p = pc;
        } else {
            ret.push_back(dict[p]);
            dict[pc] = dict_size;
            dict_size++;
            p = std::string(1, c);
        }
    }
    if (!p.empty()) {
        ret.push_back(dict[p]);
    }
    return ret;
}
auto lzw_decode(std::vector<int>& vec) -> std::string {
    auto dict = std::unordered_map<int, std::string>();
    for (auto i = 0; i < 256; i++) {
        dict[i] = std::string(1, i);
    }
    auto dict_size = 256;
    auto oss = std::ostringstream();
    oss << dict[vec[0]];
    auto p = dict[vec[0]];
    for (auto i = 1; i < vec.size(); i++) {
        auto c = vec[i];
        auto entry = std::string();
        if (dict.contains(c)) {
            entry = dict[c];
        } else if (c == dict_size) {
            entry = p + p[0];
        } 
        oss << entry;
        dict[dict_size] = p + entry[0];
        dict_size++;
        p = dict[c];
    }
    return oss.str();
}

int main() {
    auto s = std::string("ABABABA");
    auto ret = lzw(s);
    print(ret);
    auto ss = lzw_decode(ret);
    std::cout << ss << "\n";
    return 0;
}