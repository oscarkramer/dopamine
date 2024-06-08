//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef MemoryNeuron_H
#define MemoryNeuron_H

#include <Neuron.h>

/**
 * A memory neuron is created when conventional neuron detects it contributed significantly
 * to a reward. It shares the same input and output connections as the original neuron, but
 * remains static (no exploring new connections), and only fires if all input dendrites match
 * closely to the original stimulation.
 */
class MemoryNeuron : public Neuron
{
public:
   MemoryNeuron(Neuron& rememberThis);

   /** Only activates if similar input to original experience is encountered. */
   void process() override final;

   /** Memories aren't rewarded (yet?) */
   void reward(const double& /*level*/) override final {}

   /** Initializes static members once at program startup (called from Brain) */
   static void configure();

private:
   /** Hide */
   MemoryNeuron() : m_latchedState(0) {}

   std::vector<double> m_latchedInputs; //!< The saved values of each dendrite when the memory was formed
   const double m_latchedState; //<! The activation state of neuron when mem was formed

   // Statics are used to avoid repeated initialization of configurable parameters from Config
   // singleton:
   static double s_memEpsilon; //!< The max difference between received dendrite value and stored value for considering matching input
   static double s_recallThreshold; //!< The minimum required percentage match among inputs
};

#endif