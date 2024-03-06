#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter)
{
  std::vector<std::string> res;
  size_t dpos = 0;
  size_t n = 0;
  for(char s : str)
  {
    if(s == delimiter)
    {
      res.push_back(str.substr(dpos, n-dpos));
      dpos = n+1;
    }
    ++n;
  }
  res.push_back(str.substr(dpos, n-dpos));
  return res;
}

int main()
{
  std::string a = "What_is__your_name";
  char b = '_';
  std::vector<std::string> c = split(a, b);
  for(std::string el : c)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}