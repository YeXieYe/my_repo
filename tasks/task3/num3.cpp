#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> vec(n);
  for (int i = 0; i < k; i++) {
    int request = 0;
    int a = 0;
    int b = 0;
    std::cin >> request >> a >> b;
    if (request == 1) {
      vec[a] = b;
    } else if (request == 2) {
      int res = 0;
      for (int j = a; j <= b; j++) {
        res += vec[j];
      }
      std::cout << res << std::endl;
    }
  }
  return 0;
}