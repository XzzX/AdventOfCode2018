#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int numDifferentChars(const std::string& lhs, const std::string& rhs)
{
   assert(lhs.length() == rhs.length());

   int counter = 0;
   for (size_t idx = 0; idx < lhs.size(); ++idx)
   {
      if (lhs[idx] != rhs[idx]) ++counter;
   }
   return counter;
}

void partA()
{
   int counterTwo = 0;
   int counterThree = 0;

   std::ifstream fin("input02.txt", std::ifstream::in);
   std::string v("aaabccd");
   fin >> v;
   while (fin.good())
   {
      bool two = false;
      bool three = false;

      std::sort(v.begin(), v.end());
      auto it = v.begin();
      while (it!=v.end())
      {
         char c = *it;
         auto fIt = std::find_if(it + 1, v.end(), [&c](auto& rhs){return rhs != c;});
         auto dist = std::distance(it, fIt);
         if (dist==2) two=true;
         if (dist==3) three=true;
         it = fIt;
      }

      if (two) ++counterTwo;
      if (three) ++counterThree;

      fin >> v;
   }
   fin.close();

   std::cout << counterTwo << " * " << counterThree << " = " << counterTwo*counterThree << std::endl;
}

void partB()
{
   std::vector<std::string> strings;
   std::ifstream fin("input02.txt", std::ifstream::in);
   std::string v("aaabccd");
   fin >> v;
   while (fin.good())
   {
      strings.emplace_back(v);
      fin >> v;
   }
   fin.close();

   for (auto aIt = strings.begin(); aIt != strings.end(); ++aIt)
   {
      for (auto bIt = aIt + 1; bIt != strings.end(); ++bIt)
      {
         if (numDifferentChars(*aIt, *bIt) == 1)
         {
            for (size_t idx = 0; idx < aIt->size(); ++idx)
            {
               if ((*aIt)[idx] == (*bIt)[idx]) std::cout << (*aIt)[idx];
            }
            std::cout << std::endl;

            break;
         }
      }
   }
}

int main(int /*argc*/, char** /*argv*/)
{
   partA();
   partB();
}
