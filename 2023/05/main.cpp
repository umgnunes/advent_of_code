#include "common.hpp"

struct map_range {
  size_t dest;
  size_t src;
  size_t range;
};

void fp1() {
  string line;
  getline(cin, line);
  line.erase(0, 7);

  const vector<size_t> seeds = string_to_vec<size_t>(line);
  // print_elems(seeds);
  getline(cin, line); // '\n'

  vector<vector<map_range>> map_ranges;
  while (getline(cin, line)) //  'text:'
  {
    vector<map_range> mr;
    for (string line_map; getline(cin, line_map);) {
      if (line_map.empty()) {
        break;
      }
      const vector<size_t> m = string_to_vec<size_t>(line_map);
      if (m.size() == 3) {
        mr.push_back({m[0], m[1], m[2]});
      }
    }
    map_ranges.push_back(mr);
  }

  size_t lowest_loc = -1;
  for (size_t s : seeds) {
    size_t map_value = s;
    for (int i = 0; i < map_ranges.size(); ++i) {
      for (int j = 0; j < map_ranges[i].size(); ++j) {
        const size_t md = map_value - map_ranges[i][j].src;
        if (0 <= md && md < map_ranges[i][j].range) {
          map_value = map_ranges[i][j].dest + md;
          break;
        }
      }
    }
    if (lowest_loc > map_value) {
      lowest_loc = map_value;
    }
  }

  print_elem(lowest_loc);
}

void fp2() {
  string line;
  getline(cin, line);
  line.erase(0, 7);

  const vector<size_t> seeds = string_to_vec<size_t>(line);
  getline(cin, line); // '\n'

  vector<vector<map_range>> map_ranges;
  while (getline(cin, line)) //  'text:'
  {
    vector<map_range> mr;
    for (string line_map; getline(cin, line_map);) {
      if (line_map.empty()) {
        break;
      }
      const vector<size_t> m = string_to_vec<size_t>(line_map);
      if (m.size() == 3) {
        mr.push_back({m[0], m[1], m[2]});
      }
    }
    map_ranges.push_back(mr);
  }

  size_t lowest_loc = -1;
  for (int k = 0; k < seeds.size(); k += 2) {
    print_elem(k);
    for (size_t s = seeds[k]; s < seeds[k] + seeds[k + 1]; ++s) {
      size_t map_value = s;
      for (int i = 0; i < map_ranges.size(); ++i) {
        for (int j = 0; j < map_ranges[i].size(); ++j) {
          const size_t md = map_value - map_ranges[i][j].src;
          if (0 <= md && md < map_ranges[i][j].range) {
            map_value = map_ranges[i][j].dest + md;
            break;
          }
        }
      }
      if (lowest_loc > map_value) {
        lowest_loc = map_value;
      }
    }
  }

  print_elem(lowest_loc);
}

int main() {
  fp1();
  fp2();
  return 0;
}
