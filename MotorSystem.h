#include "Neuron.h"

class MotorSystem
{
public:
   SensorySystem();
   ~SensorySystem();

   vector<double>& conclude();

private:
   std::vector<std::shared_ptr<MotorNeuron> > m_motorNeurons;

}
