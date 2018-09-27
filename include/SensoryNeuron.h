#ifndef SensoryNeuron_H
#define SensoryNeuron_H

#include "Neuron.h"

class SensoryNeuron : public Neuron
{
public:
   SensoryNeuron();
   ~SensoryNeuron();

   void sense(const double& level);
};

#endif