#include "common.hpp"

struct Nums {
  int num;
  int pos_begin;
  int pos_end;
};

struct Symbol {
  int pos;
};

#if 0
int main() {
  int sum_parts = 0;
  vector<vector<Nums>> q_nums;
  vector<vector<Symbol>> q_symbols;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    vector<Nums> nums;
    vector<Symbol> symbols;
    int num = 0;
    int pos_begin = 0;
    for (int i = 0; i < line.size(); ++i) {
      const char c = line[i];
      if ('0' <= c && c <= '9') {
        num = 10 * num + (c - '0');
      } else {
        if (num > 0) {
          // cout << num << ' ' << pos_begin << ' ' << i - 1 << '\n';
          nums.push_back({num, pos_begin, i - 1});
          num = 0;
        }
        if (c != '.') {
          // print_elem(i);
          symbols.push_back({i});
        }
        pos_begin = i + 1;
      }
    }
    if (num > 0) {
      // cout << num << ' ' << pos_begin << ' ' << line.size() - 1 << '\n';
      nums.push_back({num, pos_begin, int(line.size() - 1)});
    }
    q_nums.push_back(nums);
    q_symbols.push_back(symbols);
  }

  // print_elem(q_nums.size());
  // print_elem(q_symbols.size());

  for (int l = 0; l < q_nums.size(); ++l) {
    for (auto num : q_nums[l]) {
      // cout << "num: " << l << ' ' << num.num << ' ' << num.pos_begin << ' '
      //  << num.pos_end << '\n';
      for (int s = max(0, l - 1); s < min(int(q_symbols.size()), l + 2); ++s) {
        for (auto symbol : q_symbols[s]) {
          // cout << "symbol: " << s << ' ' << symbol.pos << '\n';
          if (num.pos_begin - 1 <= symbol.pos &&
              symbol.pos <= num.pos_end + 1) {
            // print_elem(num.num);
            sum_parts += num.num;
            s = l + 2;
            break;
          }
        }
      }
    }
  }
  print_elem(sum_parts);
  return 0;
}
#else
int main() {
  int sum_parts = 0;
  vector<vector<Nums>> q_nums;
  vector<vector<Symbol>> q_symbols;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    vector<Nums> nums;
    vector<Symbol> symbols;
    int num = 0;
    int pos_begin = 0;
    for (int i = 0; i < line.size(); ++i) {
      const char c = line[i];
      if ('0' <= c && c <= '9') {
        num = 10 * num + (c - '0');
      } else {
        if (num > 0) {
          // cout << num << ' ' << pos_begin << ' ' << i - 1 << '\n';
          nums.push_back({num, pos_begin, i - 1});
          num = 0;
        }
        if (c == '*') {
          // print_elem(i);
          symbols.push_back({i});
        }
        pos_begin = i + 1;
      }
    }
    if (num > 0) {
      // cout << num << ' ' << pos_begin << ' ' << line.size() - 1 << '\n';
      nums.push_back({num, pos_begin, int(line.size() - 1)});
    }
    q_nums.push_back(nums);
    q_symbols.push_back(symbols);
  }

  // print_elem(q_nums.size());
  // print_elem(q_symbols.size());

  for (int s = 0; s < q_symbols.size(); ++s) {
    for (auto symbol : q_symbols[s]) {
      vector<int> adjacent_nums;
      for (int l = max(0, s - 1); l < min(int(q_nums.size()), s + 2); ++l) {
        for (auto num : q_nums[l]) {
          if (num.pos_begin - 1 <= symbol.pos &&
              symbol.pos <= num.pos_end + 1) {
            // print_elem(num.num);
            adjacent_nums.push_back(num.num);
          }
        }
      }
      if (adjacent_nums.size() == 2) {
        sum_parts += adjacent_nums[0] * adjacent_nums[1];
      }
    }
  }
  print_elem(sum_parts);
  return 0;
}
#endif