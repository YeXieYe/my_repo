#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> vec(n, 0);
  std::vector<int> output;
  for (int i = 0; i < k; i++) {
    int request = 0;
    int a = 0;
    int b = 0;
    std::cin >> request >> a >> b;
    if (request == 1) {
      vec[a - 1] = b;
    } else if (request == 2) {
      int res = 0;
      for (int j = a; j <= b; j++) {
        res += vec[j - 1];
      }
      output.push_back(res);
    }
  }
  for (int res : output) {
    std::cout << res << std::endl;
  }
  return 0;
}