#include "Neuron.h"

class SensoryNeuron : public Neuron
{
public:
   SensoryNeuron();
   ~SensoryNeuron();

   void sense(const double& level);
}
