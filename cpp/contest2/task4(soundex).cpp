#include <iostream>
using namespace std;

char* replaceAll(char* word, char* toReplace, char replaceTo)
{
  char* wordPtr = word;
  while(*wordPtr != '\0')
  {
    char* toReplacePtr = toReplace;
    while(*toReplacePtr != '\0')
    {
      if(*wordPtr == *toReplacePtr)
      {
        *wordPtr = replaceTo;
        break;
      }
      ++toReplacePtr; 
    }
    ++wordPtr;
  }
  return word;
}

string getSoundex(char* word)
{
  char newWord[5] = "0000";
  char* wordPtr = word;
  char* newWordPtr = newWord;
  char* res = newWord;
  *newWordPtr = *wordPtr;
  ++wordPtr;

  char deleteIt[] = "aehiouwy", to1[] = "bfpv", to2[] = "cgjkqsxz", to3[] = "dt", to4[] = "l", to5[] = "mn", to6[] = "r";
  word = replaceAll(word, deleteIt, '*');
  word = replaceAll(word, to1, '1');
  word = replaceAll(word, to2, '2');
  word = replaceAll(word, to3, '3');
  word = replaceAll(word, to4, '4');
  word = replaceAll(word, to5, '5');
  word = replaceAll(word, to6, '6');

  while(*wordPtr != '\0' && *newWordPtr != '\0')
  {
    if(*wordPtr != '*' && *wordPtr != *newWordPtr && *(newWordPtr + 1) != '\0')
    {
      ++newWordPtr;
      *newWordPtr = *wordPtr;
    }
    ++wordPtr;
  }
  string resS = res;
  return resS;
}

int main()
{
  char word[21];
  cin >> word;
  cout << getSoundex(word) << endl;
  return 0;
}