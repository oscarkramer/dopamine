#include "Neuron.h"

class MotorNeuron : public Neuron
{
public:
   MotorNeuron();
   ~MotorNeuron();

   const double& response();
}
