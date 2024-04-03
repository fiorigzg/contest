#include <iostream>

unsigned short strLen(char* str)
{
  unsigned short res = 0;
  while(*str != '\0')
  {
    ++res;
    ++str;
  }
  return res;
}

unsigned short strLenNoSpaces(char* str)
{
  unsigned short res = 0;
  while(*str != '\0')
  {
    if(*str != ' ')
      ++res;
    ++str;
  }
  return res;
}

bool isPolindrome(char* str)
{
  unsigned short len = strLen(str);
  bool res = true;

  char* addrLeft = str;
  char* addrRight = str + len - 1;
  short stepsCount = strLenNoSpaces(str);
  
  while(addrLeft != addrRight)
  {
    while(*addrLeft == ' ')
      ++addrLeft;
    while(*addrRight == ' ')
      --addrRight;

    if(*addrLeft != *addrRight)
    {
      res = false;
      break;
    }

    ++addrLeft;
    --addrRight;
    stepsCount -= 2;

    if(stepsCount <= 0)
    {
      res = true;
      break;
    }
  }

  return res;
}

int main()
{
  char str[101]{};
  std::cin.getline(str, 101);
  std::cout << (isPolindrome(str) ? "yes" : "no") << std::endl;
  return 0;
}