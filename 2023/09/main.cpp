#include "common.hpp"

void fp1() {
  vector<vector<int>> histories;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    histories.push_back(string_to_vec<int>(line));
  }
  int next_history_value_sum = 0;
  for (const auto &hs : histories) {
    // print_elems(hs);
    vector<vector<int>> seqs;
    seqs.push_back(hs);
    while (!vec_all_zero(seqs.back())) {
      seqs.push_back(diff_vec<int>(seqs.back()));
    }
    seqs.back().push_back(0);
    for (int i = seqs.size() - 2; i >= 0; --i) {
      seqs[i].push_back(seqs[i + 1].back() + seqs[i].back());
    }
    next_history_value_sum += seqs[0].back();
  }
  print_elem(next_history_value_sum);
}

void fp2() {
  vector<vector<int>> histories;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    histories.push_back(string_to_vec<int>(line));
  }
  int next_history_value_sum = 0;
  for (const auto &hs : histories) {
    // print_elems(hs);
    vector<vector<int>> seqs;
    seqs.push_back(hs);
    while (!vec_all_zero(seqs.back())) {
      seqs.push_back(diff_vec<int>(seqs.back()));
    }
    seqs.back().push_back(0);
    for (int i = seqs.size() - 2; i >= 0; --i) {
      seqs[i].push_back(seqs[i].front() - seqs[i + 1].back());
    }
    next_history_value_sum += seqs[0].back();
  }
  print_elem(next_history_value_sum);
}

int main() {
  // fp1();
  fp2();
  return 0;
}
