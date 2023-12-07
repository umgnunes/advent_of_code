#include "common.hpp"

enum Hands {
  HighCard,
  OnePair,
  TwoPair,
  ThreeKind,
  FullHouse,
  FourKind,
  FiveKind
};

struct hand_bid {
  string hand;
  size_t bid;
  Hands type;
};

// switch Jack order between part 1 and 2 to get the correct results
enum Cards {
  Jack,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nive,
  Ten,
  Queen,
  King,
  Ace
};

Hands hand_type(const string &hand) {
  unordered_map<char, int> hand_map;
  for (char c : hand) {
    ++hand_map[c];
  }
  int prev_value = -1;
  for (auto &[key, value] : hand_map) {
    if (value == 5) {
      return FiveKind;
    }
    if (value == 4 || (value)) {
      return FourKind;
    }
    if ((value == 3 && prev_value == 2) || (value == 2 && prev_value == 3)) {
      return FullHouse;
    }
    if ((value == 2 && prev_value == 2) || (value == 2 && prev_value == 2)) {
      return TwoPair;
    }
    if (prev_value < value) {
      prev_value = value;
    }
  }
  if (prev_value == 3) {
    return ThreeKind;
  }
  if (prev_value == 2) {
    return OnePair;
  }
  return HighCard;
}

void fp1() {
  unordered_map<char, Cards> cards{
      {'A', Ace},  {'K', King},  {'Q', Queen}, {'J', Jack}, {'T', Ten},
      {'9', Nive}, {'8', Eight}, {'7', Seven}, {'6', Six},  {'5', Five},
      {'4', Four}, {'3', Three}, {'2', Two}};
  vector<hand_bid> hands;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    const string hand = line.substr(0, 5);
    line.erase(0, 5);
    hands.push_back({hand, string_to_num<size_t>(line)});
  }
  sort(hands.begin(), hands.end(),
       [&cards](const hand_bid &a, const hand_bid &b) {
         const Hands a_type = hand_type(a.hand);
         const Hands b_type = hand_type(b.hand);
         if (a_type == b_type) {
           for (int i = 0; i < 5; ++i) {
             if (a.hand[i] != b.hand[i]) {
               return cards[a.hand[i]] < cards[b.hand[i]];
             }
           }
         }
         return a_type < b_type;
       });

  size_t total_w = 0;
  for (int i = 0; i < hands.size(); ++i) {
    total_w += (i + 1) * hands[i].bid;
  }
  print_elem(total_w);
}

Hands hand_type_j(const string &hand) {
  unordered_map<char, int> hand_map;
  for (char c : hand) {
    ++hand_map[c];
  }
  int prev_value = -1;
  for (auto &[key, value] : hand_map) {
    if (value == 5 || (key != 'J' && ((value == 4 && hand_map['J'] == 1) ||
                                      (value == 3 && hand_map['J'] == 2) ||
                                      (value == 2 && hand_map['J'] == 3) ||
                                      (value == 1 && hand_map['J'] == 4)))) {
      return FiveKind;
    }
    if (value == 4 || (key != 'J' && ((value == 3 && hand_map['J'] == 1) ||
                                      (value == 2 && hand_map['J'] == 2) ||
                                      (value == 1 && hand_map['J'] == 3)))) {
      return FourKind;
    }
    if ((value == 3 && prev_value == 2) || (value == 2 && prev_value == 3) ||
        (key != 'J' &&
         ((value == 3 && prev_value == 1 && hand_map['J'] == 1) ||
          (value == 2 && hand_map['J'] == 1 && prev_value == 2)))) {
      return FullHouse;
    }
    if ((value == 2 && prev_value == 2) || (value == 2 && prev_value == 2)) {
      return TwoPair;
    }
    if (prev_value < value && key != 'J') {
      prev_value = value;
    }
  }
  if (prev_value == 3 || (prev_value == 2 && hand_map['J'] == 1) ||
      (prev_value == 1 && hand_map['J'] == 2)) {
    return ThreeKind;
  }
  if (prev_value == 2 || (prev_value == 1 && hand_map['J'] == 1)) {
    return OnePair;
  }
  return HighCard;
}

void fp2() {
  unordered_map<char, Cards> cards{
      {'A', Ace},  {'K', King},  {'Q', Queen}, {'J', Jack}, {'T', Ten},
      {'9', Nive}, {'8', Eight}, {'7', Seven}, {'6', Six},  {'5', Five},
      {'4', Four}, {'3', Three}, {'2', Two}};
  vector<hand_bid> hands;
  for (string line; getline(cin, line);) {
    // print_elem(line);
    const string hand = line.substr(0, 5);
    line.erase(0, 5);
    hands.push_back({hand, string_to_num<size_t>(line)});
  }
  sort(hands.begin(), hands.end(), [&cards](hand_bid &a, hand_bid &b) {
    a.type = hand_type_j(a.hand);
    b.type = hand_type_j(b.hand);
    if (a.type == b.type) {
      for (int i = 0; i < 5; ++i) {
        if (a.hand[i] != b.hand[i]) {
          return cards[a.hand[i]] < cards[b.hand[i]];
        }
      }
    }
    return a.type < b.type;
  });

  size_t total_w = 0;
  for (int i = 0; i < hands.size(); ++i) {
    total_w += (i + 1) * hands[i].bid;
  }
  print_elem(total_w);
}

int main() {
  // fp1();
  fp2();
  return 0;
}
