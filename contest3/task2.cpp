#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string getRevPerm(size_t n)
{
  int revPerm[n];
  for(size_t i = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    revPerm[num-1] = i + 1;
  }

  string res = "";
  for(int obj : revPerm) {
    res += to_string(obj) + " ";
  }
  return res;
}


int main()
{
  size_t n;
  cin >> n;
  cout << getRevPerm(n) << endl;
  return 0;
}