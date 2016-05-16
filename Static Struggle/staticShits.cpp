#include <iostream>

class House
{
   public:
      static int houseCounter;

      House()
      {
         std::cout << " House created :)" << std::endl;

         houseCounter++;
      }
};

int House::houseCounter = 0;

int main( )
{
    House Stark;
    House Lannister;

    std::cout << "Count of houses : " << House::houseCounter << std::endl;

    House Bolton;

    std::cout << "New count of houses : " << House::houseCounter << std::endl;

    return 0;
}