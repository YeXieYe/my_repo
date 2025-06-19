#include <iostream>
#include <vector>
#include <string>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> partition(n);
  std::vector<char> word(n);
  std::vector<char> temp(n);
  for (int i = 0; i < n; i++) {
    std::cin >> partition[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> word[i];
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      temp[partition[j] - 1] = word[j];
    }
    word = temp;
  }
  for (int i = 0; i < n; i++) {
    std::cout << word[i];
  }
  return 0;
}