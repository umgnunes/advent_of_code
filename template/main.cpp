#include "common.hpp"

void fp1() {
  for (string line; getline(cin, line);) {
    print_elem(line);
  }
}

void fp2() {
  for (string line; getline(cin, line);) {
    // print_elem(line);
  }
}

int main() {
  fp1();
  fp2();
  return 0;
}
