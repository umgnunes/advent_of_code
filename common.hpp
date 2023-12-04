#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

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
