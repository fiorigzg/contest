#include <iostream>
#include <string>

std::string common_suffix(const std::string& a, const std::string& b)
{
  size_t aLen = a.length(), bLen = b.length();
  size_t minLen = std::min(aLen, bLen);
  size_t fromRight = 0;
  for(size_t i = 0; i < minLen; i++) {
    if(a[aLen - i - 1] == b[bLen - i - 1])
      ++fromRight;
    else
      break;
  }
  return a.substr(aLen - fromRight, aLen);
}

int main()
{
  std::string a = "apple";
  std::string b = "tuple";
  std::cout << common_suffix(a, b) << std::endl;
}