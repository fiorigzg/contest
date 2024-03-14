#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
    size_t wordsCount, vecSize;
    std::string firstWord;
    std::vector<short> firstVec;
    std::vector<std::string> topWords;
    std::string word;
    short num;
    int sum, topSum = -3000001;

    std::cin >> wordsCount >> vecSize;
    std::cin >> firstWord;
    for (size_t i = 0; i < vecSize; i++)
    {
        std::cin >> num;
        firstVec.push_back(num);
    }

    for (size_t i = 0; i < wordsCount - 1; i++)
    {
        std::cin >> word;
        sum = 0;
        for (size_t j = 0; j < vecSize; j++)
        {
            std::cin >> num;
            sum += num * firstVec[j];
        }
        if (sum >= topSum)
        {
            if (sum > topSum)
            {
                topWords.clear();
            }
            topSum = sum;
            topWords.push_back(word);
        }
    }

    for (std::string& word: topWords)
    {
        std::cout << word << std::endl;
    }

    return 0;
}