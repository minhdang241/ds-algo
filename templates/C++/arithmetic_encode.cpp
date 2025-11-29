
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>


auto arithmetic_encode(std::string& symbol, std::unordered_map<char, std::pair<double, double>>& ranges) -> double {
  auto low = 0.0;
  auto high = 1.0;

  for (const auto& chr: symbol) {
    auto [sym_low, sym_high] = ranges[chr];
    auto code_range = high - low;
    high = low + code_range * sym_high;
    low = low + code_range * sym_low;
    std::cout << low << " " << high << "\n";
  }
  return low;
}

auto arithmetic_decode(double value, std::unordered_map<char, std::pair<double, double>>& ranges, std::unordered_map<char, int> freq) -> std::string {
  auto oss = std::ostringstream();
  while (!freq.empty()) {
    for (const auto& [chr, p]: ranges) {
      if (freq.contains(chr)) {
        auto [low, high] = p;
        if (low <= value && value <= high) {
          freq[chr]--;
          auto range = high - low;
          value -= low;
          value /= range;
          std::cout << chr << " " << value << " " << freq[chr] << "\n";
          oss << chr;
          if (freq[chr] == 0) {
            freq.erase(chr);
          }
        }
      }
    }
  }
  return oss.str();
}

int main(void) {
  auto s = std::string("BILL GATES");
  auto ranges = std::unordered_map<char, std::pair<double, double>> {
    {' ', std::make_pair(0.0, 0.1)},
    {'A', std::make_pair(0.1, 0.2)},
    {'B', std::make_pair(0.2, 0.3)},
    {'E', std::make_pair(0.3, 0.4)},
    {'G', std::make_pair(0.4, 0.5)},
    {'I', std::make_pair(0.5, 0.6)},
    {'L', std::make_pair(0.6, 0.8)},
    {'S', std::make_pair(0.8, 0.9)},
    {'T', std::make_pair(0.9, 1.0)},
  };
  auto ret = arithmetic_encode(s, ranges);
  std::cout << ret << "\n";
  auto freq = std::unordered_map<char, int> {
    {' ', 1},
    {'A', 1},
    {'B', 1},
    {'E', 1},
    {'G', 1},
    {'I', 1},
    {'L', 2},
    {'S', 1},
    {'T', 1},
  };
  auto ss = arithmetic_decode(ret, ranges, freq);
  std::cout << ss << "\n";
}

