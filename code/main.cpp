#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("data/input.txt");

  if (!file.is_open()) {
    return 1;
  }

  std::vector<std::string> text;
  std::string line;

  while (std::getline(file, line)) {
    text.push_back(line);
  }

  file.close();

  int limit;
  std::cin >> limit;

  auto lambda = [limit](const std::string& line) {
    return line.size() < limit;
  };
  std::erase_if(text, [&lambda](const std::string& line) { return lambda(line); } );

  return 0;
}