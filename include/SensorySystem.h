//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef SensorySystem_H
#define SensorySystem_H

#include "SensoryNeuron.h"

/**
 * System of neurons at the first layer that receive stimulus from the outside world.
 * The input side remains hardwired.
 */
class SensorySystem
{
public:
   SensorySystem();
   ~SensorySystem();

   void sense(const std::vector<double> perception);

private:
   std::vector<std::shared_ptr<SensoryNeuron> > m_sensoryNeurons;
};

#endif