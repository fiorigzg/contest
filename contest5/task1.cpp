#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    size_t seqLen, winLen;
    std::cin >> seqLen >> winLen;

    std::vector<int16_t> winvec;
    int16_t newVal;
    for (size_t i = 0; i < seqLen; ++i)
    {
        std::cin >> newVal;
        winvec.push_back(newVal);
    }

    std::multiset<int16_t> winset;
    for (size_t i = 0; i < winLen - 1; ++i)
    {
        winset.insert(winvec[i]);
    }
    for (size_t i = winLen - 1; i < seqLen; ++i)
    {
        winset.insert(winvec[i]);
        std::cout << *winset.begin() << std::endl;
        winset.extract(winvec[i - winLen + 1]);
    }

    return 0;
}