#include "common.hpp"

#if 0
int main() {
  int points_total = 0;
  for (string line; getline(cin, line);) {
    int pos = line.find(": ");
    line.erase(0, pos + 2);
    // print_elem(line);
    pos = line.find(" | ");
    string w_num_str = line.substr(0, pos);
    // print_elem(w_num_str);
    line.erase(0, pos + 3);
    // print_elem(line);

    vector<int> w_num;
    {
      stringstream s(w_num_str);
      int num;
      while (s >> num) {
        w_num.push_back(num);
      }
      sort(w_num.begin(), w_num.end());
    }
    // print_elems(w_num);

    vector<int> l_num;
    {
      stringstream s(line);
      int num;
      while (s >> num) {
        l_num.push_back(num);
      }
      sort(l_num.begin(), l_num.end());
    }
    // print_elems(l_num);

    int points = 0;
    for (auto n : l_num) {
      if (find(w_num.begin(), w_num.end(), n) != end(w_num)) {
        if (points == 0) {
          points = 1;
        } else {
          points <<= 1;
        }
      }
    }
    points_total += points;
  }
  print_elem(points_total);
  return 0;
}
#else
int main() {
  int card_num = 0;
  vector<pair<int, int>> card_nums;
  for (string line; getline(cin, line); ++card_num) {
    int pos = line.find(": ");
    line.erase(0, pos + 2);
    // print_elem(line);
    pos = line.find(" | ");
    string w_num_str = line.substr(0, pos);
    // print_elem(w_num_str);
    line.erase(0, pos + 3);
    // print_elem(line);

    vector<int> w_num;
    {
      stringstream s(w_num_str);
      int num;
      while (s >> num) {
        w_num.push_back(num);
      }
      sort(w_num.begin(), w_num.end());
    }
    // print_elems(w_num);

    vector<int> l_num;
    {
      stringstream s(line);
      int num;
      while (s >> num) {
        l_num.push_back(num);
      }
      sort(l_num.begin(), l_num.end());
    }
    // print_elems(l_num);

    vector<vector<int>> s_cards;

    int cards = 0;
    for (auto n : l_num) {
      if (find(w_num.begin(), w_num.end(), n) != end(w_num)) {
        ++cards;
      }
    }
    // print_elem(card_num);
    // print_elem(cards);
    // print_elem('\n');
    card_nums.push_back({card_num, cards});
  }

  for (int i = 0; i < card_nums.size(); ++i) {
    for (int j = 1; j <= card_nums[i].second; ++j) {
      card_nums.push_back(card_nums[j + card_nums[i].first]);
    }
  }
  print_elem(card_nums.size());
  return 0;
}
#endif
