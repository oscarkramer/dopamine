#include "Neuron.h"

/**
 * System of neurons at the first layer that receive stimulus from the outside world.
 * The input side remains hardwired.
 */
class SensorySystem
{
public:
   SensorySystem();
   ~SensorySystem();

   void stimulate(const vector<double> perception);

private:
   std::vector<std::shared_ptr<SensoryNeuron> > m_sensoryNeurons;

}
