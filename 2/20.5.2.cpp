#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
  std::cout << "Input width and height: " << std::endl;
  int width;
  int height;
  std::cin >> width >> height;
  std::ofstream pic("pic.txt");
  if (!pic.is_open())
  {
    std::cout << "Can't open pic.txt" << std::endl;
    return -1;
  }
  std::srand(std::time(nullptr));
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
    {
      pic << (char)('0' + (std::rand() % 2));
    }
    pic << std::endl;
  }
  pic.close();

  return 0;
}
