#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Rand(int n) {
    vector<vector<int>> mountain;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 99);
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j <= i; j++) {
            row.push_back(dist(rd));
        }
        mountain.push_back(row);
    }
    for (const auto& row : mountain) {
        for (const auto& num : row) {
           cout << num << " ";
        }
        cout << endl;
    }
    return mountain;
}

void MinWay(vector<vector<int>> mountain, int n) {
    if (n == 0) {
        cout << "0" << endl;
        return;
    }
    int res = mountain[0][0];;
    vector<int> way;
    way.push_back(mountain[0][0]);
    int current_num = 0;
    for (int i = 1; i < n; i++) {
        if (current_num + 1 >= mountain[i].size()) {
            res += mountain[i][current_num];
            way.push_back(mountain[i][current_num]);
        }
        else {
            if (mountain[i][current_num] > mountain[i][current_num + 1] && mountain[i][current_num + 1] != 0) {
                res += mountain[i][current_num + 1];
                way.push_back(mountain[i][current_num + 1]);
                current_num++;
            }
            else {
                res += mountain[i][current_num];
                way.push_back(mountain[i][current_num]);
            }
        }
    }
    cout << res << endl;
    for (const auto& i : way) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;
    MinWay(Rand(n), n);
    return 0;
}