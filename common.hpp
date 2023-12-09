#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <typename T> vector<T> diff_vec(const vector<T> &v) {
  vector<T> v_diff(v.size() - 1);
  for (size_t i = 1; i < v.size(); ++i) {
    v_diff[i - 1] = v[i] - v[i - 1];
  }
  return v_diff;
}

template <typename T> T lcm_vec(const vector<T> &v) {
  size_t r = 1;
  for (const auto &e : v) {
    r = lcm(r, e);
  }
  return r;
}

template <typename T> void print_elem(const T &elem) { cout << elem << '\n'; }

template <typename T> void print_elems(const T &elems) {
  for (const auto &elem : elems) {
    cout << elem << ' ';
  }
  cout << '\n';
}

template <typename T> void print_pairs(const T &pairs) {
  for (const auto &p : pairs) {
    cout << '(' << p.first << ',' << p.second << ')' << '\n';
  }
}

void string_remove_char(string &s, const char c) {
  s.erase(remove(s.begin(), s.end(), c), s.end());
}

template <typename T> T string_to_num(const string &s) {
  stringstream sm(s);
  T num;
  sm >> num;
  return num;
}

template <typename T> vector<T> string_to_vec(const string &s) {
  vector<T> v;
  stringstream sm(s);
  T num;
  while (sm >> num) {
    v.push_back(num);
  }
  return v;
}

template <typename T> bool vec_all_zero(const vector<T> &v) {
  const size_t sum_v = accumulate(v.begin(), v.end(), 0);
  return sum_v == 0;
}
