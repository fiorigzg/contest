#include <iostream>
#include <string>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter)
{
  std::string res = "";
  for(std::string token : tokens)
  {
    res += token;
    res += delimiter;
  }
  res.pop_back();
  return res;
}

int main()
{
  std::vector<std::string> a = {"What", "is", "your", "mmafddsfd", "fdsfds", "fdsfddd"};
  char b = '_';
  std::cout << join(a, b) << std::endl;
}