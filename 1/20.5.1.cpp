#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool input_date(std::string &str_date)
{
  bool ret = false;
  std::cout << "Input date: " << std::endl;
  std::getline(std::cin, str_date);
  std::stringstream stream_date(str_date);
  unsigned int day;
  unsigned int month;
  int year;
  char delim[2];
  stream_date >> day >> delim[0] >> month >> delim[1] >> year;
  if (day <= 31 && month <= 12 && delim[0] == delim[1] && (delim[0] == '.' || delim[0] == '\\' || delim[0] == '/'))
    ret = true;
  std::cout << day << " " << month << " " << year << std::endl;
  return ret;
}

int main()
{
  std::cout << "Input name: " << std::endl;
  std::string name;
  std::getline(std::cin, name);
  std::string str_date;
  if (!input_date(str_date))
  {
    std::cout << "Invalid date" << std::endl;
    return -1;
  }
  std::string str_amount;
  std::getline(std::cin, str_amount);

  std::ofstream payments(".\\payments.txt", std::ios::app);
  if (!payments.is_open())
  {
    std::cout << "Can't open file .\\payments.txt" << std::endl;
    return -1;
  }
  payments.close();
  return 0;
}
