#include "common.hpp"

#if 0
int main() {
  char c;
  int first_digit = -1, last_digit;
  int sum = 0;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    for (char c : line) {
      if ('0' <= c && c <= '9') {
        last_digit = c - '0';
        if (first_digit < 0) {
          first_digit = last_digit;
        }
      }
    }
    sum += 10 * first_digit + last_digit;
    first_digit = -1;
  }

  print_elem(sum);
  return 0;
}
#else

int get_digit(vector<string> &search_table, const string &str,
              const vector<string>::iterator it1,
              const vector<string>::iterator it2) {
  const vector<string>::iterator it =
      find(search_table.begin(), search_table.end(), str);
  int digit = distance(it1, it);
  if (digit < 0) {
    digit = distance(it2, it);
  }
  ++digit;
  return digit;
}

int main() {
  vector<string> search_table{"1",    "2",    "3",   "4",     "5",     "6",
                              "7",    "8",    "9",   "one",   "two",   "three",
                              "four", "five", "six", "seven", "eight", "nine"};
  const vector<string>::iterator it_1 =
      find(search_table.begin(), search_table.end(), string("1"));
  const vector<string>::iterator it_one =
      find(search_table.begin(), search_table.end(), string("one"));
  int sum = 0;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    int first_digit_pos = line.size(), last_digit_pos = -1;
    string first_digit_str, last_digit_str;
    for (int i = 0; i < search_table.size(); ++i) {
      int pos = line.find(search_table[i]);
      if (pos != string::npos && pos < line.size()) {
        if (first_digit_pos > pos) {
          first_digit_pos = pos;
          first_digit_str = search_table[i];
        }
        pos = line.rfind(search_table[i]);
        if (pos != string::npos && pos < line.size() && last_digit_pos < pos) {
          last_digit_pos = pos;
          last_digit_str = search_table[i];
        }
      }
    }

    const int first_digit =
        get_digit(search_table, first_digit_str, it_one, it_1);
    const int last_digit =
        get_digit(search_table, last_digit_str, it_one, it_1);
    // print_elem(first_digit);
    // print_elem(last_digit);
    // cout << line << ' ' << first_digit << ' ' << last_digit << '\n';
    sum += 10 * first_digit + last_digit;
  }

  print_elem(sum);
  return 0;
}
#endif
