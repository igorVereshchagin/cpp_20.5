#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

enum {
  bknt_100 = 0,
  bknt_200,
  bknt_500,
  bknt_1000,
  bknt_2000,
  bknt_5000,
  bknt_types_count
};

int main()
{
  int banknotes_count[bknt_types_count];
  const int banknotes_value[bknt_types_count] = {100, 200, 500, 1000, 2000, 5000};
  std::cout << "Input operation: " << std::endl;
  std::string str_operation;
  std::cin >> str_operation;
  if (str_operation[0] == '+')
  {
    std::ofstream atm("..\\atm.bin", std::ios::binary);
    if (!atm.is_open())
    {
      std::cout << "Can't open ..\\atm.bin" << std::endl;
      return -1;
    }
    std::srand(std::time(nullptr));
    for (int i = 0; i < bknt_types_count; i++)
      banknotes_count[i] = 0;
    for (int i = 0; i < 1000; i++)
      banknotes_count[std::rand() % bknt_types_count]++;
    atm.write((char *)banknotes_count, sizeof(banknotes_count));
    atm.close();
  }
  else if (str_operation[0] == '-')
  {
    int amount = std::stoi(str_operation.substr(1));
    if (0 != (amount % banknotes_value[0]))
    {
      std::cout << "Invalid amount" << std::endl;
      return -1;
    }

  }
  else
  {
    std::cout << "Invalid operation" << std::endl;
  }
  return 0;
}
