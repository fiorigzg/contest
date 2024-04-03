#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string plusOne(string num)
{
  string res = num;
  reverse(res.begin(), res.end());
  bool isPlusOne = true;
  for(size_t i = 0; i < res.length(); ++i) 
  {
    short iNum = res[i] - '0';
    if(isPlusOne)
    {
      iNum += 1;
      isPlusOne = false;
    }

    if(iNum > 9)
    {
      isPlusOne = true;
    }

    res[i] = char(iNum % 10 + 48);
  }
  reverse(res.begin(), res.end());
  if(res[0] == '0') {
    res = "1" + res;
  }
  return res;
}

int main()
{
  string num;
  cin >> num;
  cout << plusOne(num);
  return 0;
}