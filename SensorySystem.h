#include "Neuron.h"

class SensorySystem
{
public:
   SensorySystem();
   ~SensorySystem();

   void stimulate(const vector<double> perception);

private:
   std::vector<std::shared_ptr<SensoryNeuron> > m_sensoryNeurons;

}
