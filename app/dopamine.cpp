#include <iostream>
#include <Brain.h>
#include <kommons/AppConfig.h>

using namespace ka;

int main()
{
   Brain newBrain(std::shared_ptr<Neuron>());

   std::cout << "I can feel it, Dave." << std::endl;
   return 0;
}