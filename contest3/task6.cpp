#include <iostream>
#include <string>
#include <vector>

std::string ExtractDigits(const std::string& s)
{
  std::string res = "";
  for(char c : s)
  {
    if(int(c) >= 48 && int(c) <=57) {
      res += c;
    }
  }
  return res;
}

int main()
{
  std::string a = "2+2=4";
  std::cout << ExtractDigits(a) << std::endl;
}