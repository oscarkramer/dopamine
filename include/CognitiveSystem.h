#ifndef CognitiveSystem_H
#define CognitiveSystem_H

#include "Neuron.h"

/**
 * System of neurons at the final layer that arrive at a specific decision vector.
 * They remain hardwired and do not reconnect on the output side.
 */
class CognitiveSystem
{
public:
   CognitiveSystem();
   ~CognitiveSystem();

   /** The decision is in the form of an N-tuple, likely a simple N=1 boolean */
   std::vector<double>& getDecision();

private:
   std::vector<std::shared_ptr<Neuron> > m_neurons;
   std::vector<double> m_decision;

};

#endif