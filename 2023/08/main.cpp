#include "common.hpp"

struct left_right {
  string l;
  string r;
};

void fp1() {
  string instructions;
  getline(cin, instructions);
  // print_elem(instructions);

  string line;
  getline(cin, line);

  unordered_map<string, left_right> path;
  left_right lr;
  while (getline(cin, line)) {
    // print_elem(line);
    const string from = line.substr(0, 3);
    line.erase(0, 7);
    lr.l = line.substr(0, 3);
    line.erase(0, 5);
    lr.r = line.substr(0, 3);
    path[from] = lr;
  }

  size_t steps;
  string to = "AAA";
  for (steps = 0; to != "ZZZ"; ++steps) {
    const char i = instructions[steps % instructions.size()];
    to = (i == 'L') ? path[to].l : path[to].r;
  }
  print_elem(steps);
}

void fp2() {
  string instructions;
  getline(cin, instructions);
  // print_elem(instructions);

  string line;
  getline(cin, line);

  vector<string> to;
  unordered_map<string, left_right> path;
  left_right lr;
  while (getline(cin, line)) {
    // print_elem(line);
    const string from = line.substr(0, 3);
    if (from[2] == 'A') {
      to.push_back(from);
    }
    line.erase(0, 7);
    lr.l = line.substr(0, 3);
    line.erase(0, 5);
    lr.r = line.substr(0, 3);
    path[from] = lr;
  }

  vector<size_t> steps_v;
  for (const auto &s : to) {
    string to_s = s;
    size_t steps = 0;
    for (steps = 0; to_s[2] != 'Z'; ++steps) {
      const char i = instructions[steps % instructions.size()];
      to_s = (i == 'L') ? path[to_s].l : path[to_s].r;
    }
    steps_v.push_back(steps);
  }
  const size_t steps = lcm_vec<size_t>(steps_v);
  print_elem(steps);
}

int main() {
  // fp1();
  fp2();
  return 0;
}
