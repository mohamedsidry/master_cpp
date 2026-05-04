#include <iostream>
#include "BitcoinExchange.hpp"


/**
 * @brief main - entry point of program .
 * @param [in] argc number of arguments passed to program .
 * @param [in] argv array of arguments passed to program .
 * 
 * @return 0 on success 1 on failure .
*/
int main(int argc , char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error : invalid program arguments '" << argv[0] << " <input.txt>'" << std::endl;
    return (1);
  }
  try
  {
    BitcoinExchange btc;
    btc.evaluate(argv[1]);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << BitcoinExchange::DEFAULT_DB << std::endl;
    return (1);
  }
  return (0);
}

