#ifndef Neuron_H
#define Neuron_H

#include <memory>
#include <vector>

class Neuron
{
public:

   struct Dendrite
   {
   public:
      Dendrite(Neuron* myNeuron, const double& weight=1.0);
      void activate(const double& level=1.0);

   private:
      std::shared_ptr<Neuron> m_owner;
      double m_weight;
      double m_value;
   };

   Neuron();
   ~Neuron();

   /** Creates a dendrite connection to the input neuron with specified initial weight */
   std::shared_ptr<Dendrite> connectToThis(const double& weight=1.0);

   /** "Dopamine" flood to reinforce (positive) [or punish (negative)] current state */
   virtual void reward(const double& level=1.0);

   /** Latches input signals, sums, and presents results to the output synapses */
   virtual void process();

   /* Depreciate the contribution of inactive synapses and find new connections */
   virtual void sleep();

private:
   std::vector<std::shared_ptr<Dendrite> > m_inputs;
   std::vector<std::shared_ptr<Dendrite> > m_outputs;
};

#endif