#include "common.hpp"

unordered_map<string, int> max_cubes_colors{
    {"red", 12}, {"green", 13}, {"blue", 14}};

#if 0
bool is_num_cubes_valid(string cubes_str) {
  const int pos = cubes_str.find(" ");
  const int num_cubes = stoi(cubes_str.substr(0, pos));
  const string color = cubes_str.substr(pos + 1);
  // print_elem(num_cubes);
  // print_elem(color);
  if (num_cubes > max_cubes_colors[color]) {
    return false;
  }
  return true;
}

int main() {
  int game_id_sum = 0;
  for (string line; getline(cin, line);) {
    line.erase(0, 5);
    int pos = line.find(": ");
    const int game_id = stoi(line.substr(0, pos));
    line.erase(0, pos + 2);
    // print_elem(line);
    // print_elem(game_id);
    bool game_id_ok = true;
    while ((pos = line.find("; ")) != string::npos && game_id_ok) {
      string game_subset = line.substr(0, pos);
      line.erase(0, pos + 2);
      while ((pos = game_subset.find(", ")) != string::npos && game_id_ok) {
        string cubes_str = game_subset.substr(0, pos);
        // print_elem(cubes_str);
        // print_elem(game_subset);
        game_subset.erase(0, pos + 2);

        game_id_ok &= is_num_cubes_valid(cubes_str);
      }
      game_id_ok &= is_num_cubes_valid(game_subset);
    }
    while ((pos = line.find(", ")) != string::npos && game_id_ok) {
      string cubes_str = line.substr(0, pos);
      line.erase(0, pos + 2);

      game_id_ok &= is_num_cubes_valid(cubes_str);
    }
    game_id_ok &= is_num_cubes_valid(line);

    if (game_id_ok) {
      game_id_sum += game_id;
    }
  }

  print_elem(game_id_sum);
  return 0;
}
#else
void update_min_cubes_colors(string cubes_str,
                             unordered_map<string, int> &min_cubes_colors) {
  const int pos = cubes_str.find(" ");
  const int num_cubes = stoi(cubes_str.substr(0, pos));
  const string color = cubes_str.substr(pos + 1);
  // print_elem(num_cubes);
  // print_elem(color);
  if (min_cubes_colors[color] < num_cubes) {
    min_cubes_colors[color] = num_cubes;
  }
}

int main() {
  int sum_power_sets = 0;
  for (string line; getline(cin, line);) {
    line.erase(0, 5);
    int pos = line.find(": ");
    const int game_id = stoi(line.substr(0, pos));
    line.erase(0, pos + 2);
    // print_elem(line);
    // print_elem(game_id);
    unordered_map<string, int> min_cubes_colors{
        {"red", 0}, {"green", 0}, {"blue", 0}};

    while ((pos = line.find("; ")) != string::npos) {
      string game_subset = line.substr(0, pos);
      line.erase(0, pos + 2);
      while ((pos = game_subset.find(", ")) != string::npos) {
        string cubes_str = game_subset.substr(0, pos);
        // print_elem(cubes_str);
        // print_elem(game_subset);
        game_subset.erase(0, pos + 2);

        update_min_cubes_colors(cubes_str, min_cubes_colors);
      }
      update_min_cubes_colors(game_subset, min_cubes_colors);
    }

    while ((pos = line.find(", ")) != string::npos) {
      string cubes_str = line.substr(0, pos);
      line.erase(0, pos + 2);

      update_min_cubes_colors(cubes_str, min_cubes_colors);
    }
    update_min_cubes_colors(line, min_cubes_colors);

    sum_power_sets += min_cubes_colors["red"] * min_cubes_colors["green"] *
                      min_cubes_colors["blue"];
  }

  print_elem(sum_power_sets);
  return 0;
}
#endif