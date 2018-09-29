//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef SensoryNeuron_H
#define SensoryNeuron_H

#include "Neuron.h"

/**
 * A sensory neuron accepts "analog" input stimulus (for example, one band pixel of an
 * RGB image), and converts it into the first layer of the neural net. These neurons are
 * contained inside a parent SensorySystem
 */
class SensoryNeuron : public Neuron
{
public:
   SensoryNeuron();
   ~SensoryNeuron();
};

#endif