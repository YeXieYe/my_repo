#include <iostream>
#include <vector>

int main()
{
    std::vector<char> num(6);
    for (int i = 0; i < 6; i++) {
        std::cin >> num[i];
    }
    bool flag = true;
    for (int i = 0; i < 6; i++) {
        if (1 <= i && i <= 3) {
            if (!(48 <= static_cast<int>(num[i]) && static_cast<int>(num[i]) <= 57)) {
                flag = false;
            }
        } else {
            if (!(65 <= static_cast<int>(num[i]) && static_cast<int>(num[i]) <= 90)) {
                flag = false;
            }
        }
    }
    if (flag) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
}