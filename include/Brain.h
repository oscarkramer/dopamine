//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef Brain_H
#define Brain_H

#include <memory>
#include <vector>
#include <SensorySystem.h>
#include <CognitiveSystem.h>
#include <Neuron.h>

class Brain
{
public:
   //! Singleton implementation.
   static Brain& instance();

   /** Initializes sensory, memory and cognitive systems as well as initial internal network */
   Brain();

   /** Painless destruction with memory retention */
   ~Brain();

   /** Presents vector of outside world event quantified for the given sensory system */
   void sense(const std::vector<double> perception);

   /** Brain's conclusion mapped to the decision space for comparison to training sets */
   const std::vector<double>& getDecision();

   /** Apply global reward for close match to training set for reinforcing (or discouraging)
    * current network state */
   void reward(const double& level=1.0);

   /** Enter neural reconnection phase to explore more optimal connections using prior sensory
    * and training information. */
   void sleep();

   /** Each time a neuron is created, it is registered as a member */
   void registerNeuron(std::shared_ptr<Neuron> neuron);

private:
   void age();

   std::shared_ptr<SensorySystem> m_sensorySystem;
   std::shared_ptr<CognitiveSystem> m_cognitiveSystem;
   std::vector<std::shared_ptr<Neuron> > m_neurons;
};

#endif