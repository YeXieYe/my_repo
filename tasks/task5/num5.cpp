#include <iostream>
#include <vector>

int main() {
    int h = 0;
    int w = 0;
    std::cin >> h >> w;
    std::vector<std::vector<int>> matrix(h, std::vector<int>(w));
    bool flag = false;
    int save_i = 0;
    int save_j = 0;
    int save_i_end = 0;
    int save_j_end = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 1 && !flag) {
                save_i = i;
                save_j = j;
                flag = true;
            }
            if (matrix[i][j] == 1) {
                save_i_end = i;
                save_j_end = j;
            }
        }
    }
    std::cout << save_i - 1 << " " << save_j - 1 << " ";
    std::cout << save_i_end + 1 << " " << save_j_end + 1;
    return 0;
}