#include "common.hpp"

void fp1() {
  string times_str;
  getline(cin, times_str);
  times_str.erase(0, 6);
  const vector<size_t> times = string_to_vec<size_t>(times_str);
  // print_elems(times);

  string distances_str;
  getline(cin, distances_str);
  distances_str.erase(0, 10);
  const vector<size_t> distances = string_to_vec<size_t>(distances_str);
  // print_elems(distances);

  size_t num_beat_total = 1;
  for (size_t i = 0; i < times.size(); ++i) {
    size_t num_beat = 0;
    for (size_t t = 0; t < times[i]; ++t) {
      const size_t distance_travelled = t * (times[i] - t);
      if (distance_travelled > distances[i]) {
        ++num_beat;
      }
    }
    num_beat_total *= num_beat;
  }
  print_elem(num_beat_total);
}

void fp2() {
  string time_str;
  getline(cin, time_str);
  time_str.erase(0, 6);
  string_remove_char(time_str, ' ');
  const size_t tt = string_to_num<size_t>(time_str);
  // print_elem(tt);

  string distance_str;
  getline(cin, distance_str);
  distance_str.erase(0, 10);
  string_remove_char(distance_str, ' ');
  const size_t d = string_to_num<size_t>(distance_str);
  // print_elem(d);

  size_t num_beat_total = 1;
  size_t num_beat = 0;
  for (size_t t = 0; t < tt; ++t) {
    const size_t distance_travelled = t * (tt - t);
    if (distance_travelled > d) {
      ++num_beat;
    }
  }
  num_beat_total *= num_beat;
  print_elem(num_beat_total);
}

int main() {
  fp1();
  fp2();
  return 0;
}
