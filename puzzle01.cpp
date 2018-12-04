#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

int main(int /*argc*/, char** /*argv*/)
{
   std::vector<int> freqs;
   std::ifstream fin("input01.txt", std::ifstream::in);
   int v;
   fin >> v;
   while (fin.good())
   {
      freqs.emplace_back(v);
      fin >> v;
   }
   fin.close();

   auto shift = std::accumulate(freqs.begin(), freqs.end(), 0);
   std::cout << "shift: " << shift << std::endl;

   shift = 0;
   bool rerun = true;
   std::unordered_set<int> hashmap;
   while (rerun)
   {
      for (size_t i = 0; i < freqs.size(); ++i)
      {
         shift += freqs[i];
         if (!hashmap.insert(shift).second)
         {
            std::cout << "freq occured twice: " << shift << std::endl;
            rerun = false;
            break;
         }
      }
   }
}
