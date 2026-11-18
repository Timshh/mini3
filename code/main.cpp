#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> text;
  std::string line;

  // input
  std::ifstream file("data/input.txt");

  if (!file.is_open()) {
    std::cout << "File not found\n";
    return 1;
  }

  while (std::getline(file, line)) {
    text.push_back(line);
  }

  file.close();

  // output
  std::ofstream output("data/output.txt");

  auto out_lambda = [&output](const std::vector<std::string>& array) {
    for (const std::string& line : array) {
      output << line << "\n";
    }
    output << "\n";
  };

  out_lambda(text);

  // 1 - remove
  int limit;
  std::cout << "Enter limit: ";
  std::cin >> limit;

  auto lim_lambda = [limit](const std::string& line) {
    return line.size() < limit;
  };

  std::erase_if(text, [&lim_lambda](const std::string& line) {
    return lim_lambda(line);
  });

  out_lambda(text);

  // 2 - remove symbols
  const std::string symbols = "ieayouYOUAEI";

  for (std::string& line : text) {
    std::erase_if(line, [&symbols](char c) {
      return symbols.find(c) != std::string::npos;
    });
  }

  out_lambda(text);

  // 3 - search
  std::string search;
  std::cout << "Enter find: ";
  std::cin.ignore();
  std::getline(std::cin, search);

  auto search_lambda = [&search](const std::string& line) {
    return line.find(search) != std::string::npos;
  };

  bool is_found = false;
  for (const std::string& line : text) {
    if (search_lambda(line)) {
      output << "Found" << "\n";
      is_found = true;
      break;
    }
  }
  if (!is_found) {
    output << "Not found" << "\n";
  }

  // 4 - count arrrrray size
  int summ = 0;
  for (const std::string& line : text) {
    for (const char symbol : line) {
      if (symbol != '_') {
        summ++;
      }
    }
  }
  output << summ << "\n";

  // 5 - sizes array
  std::vector<int> sizes;
  for (const std::string& line : text) {
    sizes.push_back(line.size());
  }

  for (const int& size : sizes) {
    output << size << "\n";
  }

  output.close();

  return 0;
}