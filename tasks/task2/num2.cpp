#include <iostream>
#include <vector>

enum Color {
  White,
  Grey,
  Black
};

std::vector<std::vector<int>> vertices;
std::vector<Color> colors;

void DFS(int index) {
  colors[index] = Grey;
  for (int ner : vertices[index]) {
    if (colors[ner] == White) {
      DFS(ner);
    }
  }
  colors[index] = Black;
}

int countComponents(int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (colors[i] == White) {
      DFS(i);
      count++;
    }
  }
  return count;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  vertices.resize(n);
  colors.resize(n, White);
  for (int i = 0; i < m; i++) {
    int from = 0;
    int to = 0;
    std::cin >> from >> to;
    from--;
    to--;
    vertices[from].push_back(to);
    vertices[to].push_back(from);
  }
  int components = countComponents(n);
  std::cout << components - 1 << std::endl;
  return 0;
}