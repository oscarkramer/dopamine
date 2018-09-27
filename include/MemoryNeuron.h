#ifndef MemoryNeuron_H
#define MemoryNeuron_H

#include "Neuron.h"

class MemoryNeuron : public Neuron
{
public:
   MemoryNeuron();
   ~MemoryNeuron();

   /* Latches the state of the input synapses and associated response */
   void latch();

   /* Recalls prior state if the stimulus is sufficiently similar to latched stimulus */
   void process();

   void sleep();

private:
   double m_response;
   std::vector<Dendrite> m_inputs;
};

#endif