#ifndef Neuron_H
#define Neuron_H

#include <memory>
#include <vector>

class Neuron
{
public:

   struct Dendrite
   {
      std::shared_ptr<Neuron> m_sourceNeuron;
      double m_weight;
      double m_value;
   };

   Neuron();
   ~Neuron();

   void connectToThis(std::shared_ptr<Neuron> input, const double& weight=1.0);

   /** "Dopamine" flood to reinforce (positive) [or punish (negative)] current state */
   virtual void reward(const double& level=1.0);

   /** Latches input signals, sums, and presents results to the output synapses */
   virtual void process();

   /* Depreciate the contribution of inactive synapses and find new connections */
   virtual void sleep();

private:
   std::vector<Dendrite> m_inputs;
   std::vector<std::shared_ptr<Neuron> > m_outputs;
};

#endif