#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    int res = 0;
    std::vector<int> results;
    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        int B_pairs = std::min(b, x);
        int remaining_x = x - B_pairs;
        int A_pairs = std::min(a, std::max(0, remaining_x) + y);
        int total_pairs = B_pairs + A_pairs;
        results.push_back(total_pairs);
    }
    for (int i = 0; i < n; i++) {
        std::cout << results[i] << " ";
    }
    return 0;
}