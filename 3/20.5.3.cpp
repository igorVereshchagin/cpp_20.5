#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream river("..\\river.txt");
  if (!river.is_open())
  {
    std::cout << "Can't open ..\\river.txt" << std::endl;
    return -1;
  }
  std::ofstream basket("..\\basket.txt", std::ios::app);
  if (!basket.is_open())
  {
    std::cout << "Can't open ..\\basket.txt" << std::endl;
    return -1;
  }
  std::cout << "input fish type:" << std::endl;
  std::string fish_goal;
  std::cin >> fish_goal;
  int fish_counter = 0;
  while(!river.eof())
  {
    std::string fish_river;
    river >> fish_river;
    if (fish_river == fish_goal)
    {
      fish_counter++;
      basket << fish_river << std::endl;
    }
  }
  river.close();
  basket.close();
  std::cout << fish_counter << " fishes caught" << std::endl;
  return 0;
}
