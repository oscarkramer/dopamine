//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef CognitiveSystem_H
#define CognitiveSystem_H

#include <Neuron.h>

/**
 * Subsystem of neurons at the final layer that arrive at a specific decision vector.
 */
class CognitiveSystem
{
public:
   CognitiveSystem();
   ~CognitiveSystem();

   /** The decision is in the form of an N-tuple, likely a simple confidence scalar */
   std::vector<double>& getDecision();

private:
   std::vector<std::shared_ptr<Neuron> > m_neurons;
   std::vector<double> m_decision;

};

#endif