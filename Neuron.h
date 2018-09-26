#include <memory>
#include <vector>
#include "DendriteSynapse.h"
#include "AxonSynapse.h"


class Neuron
{
public:

   struct Dendrite
   {
      std::shared_ptr<Neuron> m_sourceNeuron;
      double m_weight;
      double m_value;
   }

   Neuron();
   ~Neuron();

   void connectToThis(std::shared_ptr<Neuron> input, const double& weight=1.0);

   /** "Dopamine" flood to reinforce (positive) [or punish (negative)] current state */
   void reward(const double& level=1.0);

   /** Latches input signals, sums, and presents results to the output synapses */
   void process();

   /* Depreciate the contribution of inactive synapses and find new connections */
   void sleep();

private:
   std::vector<Dendrite> m_inputs;
   std::vector<std::shared_ptr<Neuron> > m_outputs;
}
