#include <iostream>

void printTolower(int size_tab, char **tab)
{
  for (int i = 1; i < size_tab; i++)
  {
    std::string str = tab[i];
    for (size_t j = 0; j < str.size(); j++)
    {
      std::cout << (char)std::toupper(str[j]);
    }
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  if (argc >= 2) {
    printTolower(argc, argv);
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return 0;
} 