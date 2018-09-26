#include "Neuron.h"

class MemorySystem
{
public:
   MemorySystem();
   ~MemorySystem();

   void stimulate(const vector<double> perception);

private:
   std::vector<std::shared_ptr<MemoryNeuron> > m_memoryNeurons;

}
