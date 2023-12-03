#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> void print_elem(const T &elem) { cout << elem << '\n'; }

template <typename T> void print_elems(const T &elems) {
  for (const auto &elem : elems) {
    print_elem(elem);
  }
}
