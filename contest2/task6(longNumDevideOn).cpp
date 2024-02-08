#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int devideOn(string n, int k)
{
  string devideS = "";
  for(size_t i = 0; i < n.length(); ++i)
  {
    devideS += n[i];
    int devideN = stoi(devideS);
    if(devideN / k > 0)
      devideS = to_string(devideN % k);
  }
  return stoi(devideS);
}

int main()
{
  int k;
  cin >> k;

  string n;
  cin >> n;

  cout << devideOn(n, k) << endl;
  return 0;
}