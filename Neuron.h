#include <memory>
#include <vector>
#include "DendriteSynapse.h"
#include "AxonSynapse.h"

class Neuron
{
public:
   Neuron();
   ~Neuron();

   void connectToThis(std::shared_ptr<Neuron> input, const double& weight=1.0);

   /** "Dopamine" flood to reinforce (positive) [or punish (negative)] current state */
   void reward(const double& level=1.0);

   /** Latches input signals, sums, and presents results to the output synapses */
   void process();

private:
   void age();

   std::vector<std::shared_ptr<DendriteSynapse> > m_inputs;
   std::vector<std::shared_ptr<AxonSynapse> > m_outputs;
}
