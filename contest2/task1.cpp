#include <iostream>

bool checkPsw(char* psw)
{
  size_t strLen = 0;
  bool isComp = true;
  bool isLarge = false, isSmall = false, isNum = false, isOther = false;

  while(*psw != '\0')
  {
    short charCode = short(*psw);
    if(charCode < 33 || charCode > 127)
      isComp = false;

    if(charCode >= 65 && charCode <= 90)
      isLarge = true;
    else if(charCode >= 97 && charCode <= 122)
      isSmall = true;
    else if(charCode >= 48 && charCode <= 57)
      isNum = true;
    else
      isOther = true;

    ++psw;
    ++strLen;
  }
  
  return (strLen >= 8 && strLen <= 14 && isComp && (isLarge + isSmall + isNum + isOther) >= 3);
}

int main()
{
  char psw[16]{};
  std::cin.getline(psw, 16);
  std::cout << (checkPsw(psw) ? "YES" : "NO") << std::endl;
  return 0;
}