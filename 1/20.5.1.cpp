#include <iostream>
#include <fstream>
#include <string>

bool input_date(std::string &str_date)
{
  std::cout << "Input date: " << std::endl;
  std::getline(std::cin, str_date); //dd.mm.yyyy dd\mm\yyyy dd/mm/yyyy dd-mm-yyyy
  if ((str_date.size() != 10) ||
      (str_date[2] != str_date[5]) ||
      ((str_date[2] != '.') && (str_date[2] != '\\') && str_date[2] != '/') && (str_date[2] != '-'))
    return false;
  int day = std::stoi(str_date.substr(0, 2));
  int month = std::stoi(str_date.substr(3, 2));
  if ((day < 1) || (day > 31) || (month < 1) || (month > 12))
    return false;
//  std::cout << day << " " << month << " " << year << std::endl;
  return true;
}

bool input_amount(std::string &str_amount)
{
  std::cout << "Input amount: " << std::endl;
  std::getline(std::cin, str_amount);
  return true;
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
  input_amount(str_amount);

  std::ofstream payments(".\\payments.txt", std::ios::app);
  if (!payments.is_open())
  {
    std::cout << "Can't open file .\\payments.txt" << std::endl;
    return -1;
  }
  payments << name << " " << str_date << " " << str_amount << std::endl;
  payments.close();
  return 0;
}
