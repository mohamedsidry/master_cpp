#include <iostream>
#include "BitcoinExchange.hpp"


int main(int argc , char *argv[])
{
  if (argc == 2)
  {
    BitcoinExchange btc;
    btc.evaluate(argv[1]);
    return (0);
  }
  std::cerr << "\033[1;31mError : " << "\033[0m"
  << "invalid program arguments '"
  << argv[0]
  << " <input.txt> '"
  << std::endl;
  return (1);
}

