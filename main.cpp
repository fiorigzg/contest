#include <iostream>

bool checkPsw(char* psw)
{
  std::cout << psw << std::endl;
  size_t strLen = 0;
  size_t isLarge = false, isSmall = false, isNum = false, isOther = false;

  while(*psw != '\0')
  {
    int charCode = int(*psw);
    if(int(charCode) < 33 || int(charCode) > 127)
      return false;

    if

    ++psw;
    ++strLen;
  }

  if(strLen < 8 || strLen > 14)
    return false;

  return true;
}

int main()
{
  char psw[]{};
  std::cin.getline(psw, 16);
  std::cout << (checkPsw(psw) ? "YES" : "NO") << std::endl;
  return 0;
}