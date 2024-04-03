#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<short>> getMines(short rowsCount, short columnsCount, short minesCount)
{
  vector<vector<short>> mines;
  for(short i = 0; i < minesCount; ++i)
  {
    vector<short> mine {0, 0};
    cin >> mine[0] >> mine[1];
    --mine[0];
    --mine[1];
    mines.push_back(mine);
  }

  return mines;
}

bool isMine(vector<vector<short>> mines, short row, short col)
{
  bool res = false;
  for(vector<short> mine : mines)
  {
    if(mine[0] == row && mine[1] == col)
    {
      res = true;
      break;
    }
  }
  return res;
}

void printMines(short rowsCount, short columnsCount, short minesCount)
{
  vector<vector<short>> mines = getMines(rowsCount, columnsCount, minesCount);
  vector<vector<short>> variants = {{ -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }};
  for(short rowi = 0; rowi < rowsCount; ++rowi)
  {
    for(short coli = 0; coli < columnsCount; ++coli)
    {
      short fieldValue = 0;
      if(isMine(mines, rowi, coli))
        fieldValue = 9;
      else
      {
        for(vector<short> variant : variants)
        {
          if(isMine(mines, rowi + variant[0], coli + variant[1]))
            ++fieldValue;
        }
      }
      cout << (fieldValue == 9 ? "*" : to_string(fieldValue)) << " ";
    }
    cout << endl;
  }
}

int main()
{
  short rowsCount, columnsCount, minesCount;
  cin >> rowsCount >> columnsCount >> minesCount;
  printMines(rowsCount, columnsCount, minesCount);
  return 0;
}