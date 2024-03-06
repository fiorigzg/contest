#include <iostream>
#include <fstream>
#include <string>

void countFile(std::ifstream& myfile, size_t* letters, size_t* words, size_t* lines)
{
  if(myfile.is_open())
  {
    char c;
    myfile.get(c);
    bool isWord = (int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122), wasWord;
    while(myfile.good())
    {
      if(c == '\n')
        ++*lines;

      wasWord = isWord;
      isWord = (int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122);

      if(isWord)
        ++*letters;

      if(!isWord && wasWord)
        ++*words;

      myfile.get(c);
    }
    if(isWord)
      ++*words;
  }
}

int main()
{
  std::ifstream myfile;
  myfile.open("input.txt");
  
  size_t letters = 0, words = 0, lines = 0;
  countFile(myfile, &letters, &words, &lines);

  std::cout << "Input file contains:" << std::endl;
  std::cout << letters << " letters" << std::endl;
  std::cout << words << " words" << std::endl;
  std::cout << lines << " lines" << std::endl;
}