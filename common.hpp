#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> void print_num(const T &num) { cout << num << '\n'; }

template <typename T> void print_seq(const T &seq) {
  for (const auto &s : seq) {
    cout << s << '\n';
  }
}
