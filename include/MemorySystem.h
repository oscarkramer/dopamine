#ifndef MemorySystem_H
#define MemorySystem_H

#include "MemoryNeuron.h"

/**
 * System of neurons at intermediate layers that maintain a state from prior latch ("remember")
 * and subsequently reduce to a single output neuron that fires when the latched pattern is
 * received. The input side remains hardwired. Triggered by extreme rewards.
 */
class MemorySystem
{
public:
   MemorySystem();
   ~MemorySystem();

   void latch();

private:
   std::vector<std::shared_ptr<MemoryNeuron> > m_memoryNeurons;

};

#endif