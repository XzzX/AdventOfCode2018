#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

bool doCancel(const char a, const char b)
{
   const int dist = std::abs('a' - 'A');
   return std::abs(a-b) == dist;
}

size_t lengthOfContractedPolymere(std::string str, const char removeA, const char removeB)
{
   str.erase(std::copy_if(str.begin(), str.end(), str.begin(), [removeA](char c){return removeA != c;}), str.end());
   str.erase(std::copy_if(str.begin(), str.end(), str.begin(), [removeB](char c){return removeB != c;}), str.end());
   size_t idx = 1;
   while (idx < str.length())
   {
      if (doCancel(str[idx], str[idx - 1]))
      {
         str.erase(idx-1, 2);
         --idx;
         if (idx < 1) idx = 1;
      } else
      {
         ++idx;
      }
   }

   return str.length();
}

void partA()
{
   std::string str("");
   std::ifstream fin("input05.txt", std::ifstream::in);
   std::getline(fin, str);
   fin.close();
   
   std::cout << lengthOfContractedPolymere(str, ' ', ' ') << std::endl;
}

void partB()
{
   std::string str("");
   std::ifstream fin("input05.txt", std::ifstream::in);
   std::getline(fin, str);
   fin.close();

   size_t min = std::numeric_limits<size_t>::max();
   for (char c : "abcdefghijklmnopqrstuvwxyz")
   {
      auto len = lengthOfContractedPolymere(str, c, c-32);
      if (min>len) min=len;
   }
   std::cout << min << std::endl;
}

int main(int /*argc*/, char** /*argv*/)
{
   partA();
   partB();
}
