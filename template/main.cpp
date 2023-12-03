#include "common.hpp"

int main() {
  for (string line; getline(cin, line);) {
    print_elem(line);
  }
  return 0;
}
