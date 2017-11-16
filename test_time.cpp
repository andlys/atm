#include <ctime>
#include <iostream>
#include "lib/fmt/time.h"

int main()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
    std::time_t t = std::time(nullptr);
    std::cout << fmt::format("The date is {:%Y-%m-%d %H:%M:%S}.\n", *std::localtime(&t)) << std::endl;
}
