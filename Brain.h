#include <memory>
#include <vector>
#include "SensorySystem.h"
#include "MotorSystem.h"

class Brain
{
public:
   /** Initializes sensory and motor systems as well as initial internal network */
   Brain();

   /** Painless destruction */
   ~Brain();

   /** Presents vector of outside world event quantified for the given sensory system */
   void stimulate(const vector<double> perception);

   /** Brain's conclusion mapped to the decision space for comparison to training sets */
   const vector<double> conclude()

   /** Apply global reward for close match to training set for reinforcing (or discouraging)
    * current network state */
   void reward(const double& level=1.0);

   /** Enter neural reconnection phase to explore more optimal connections using prior sensory
    * and training information. */
   void sleep();

private:
   void age();

   std::shared_ptr<SensorySystem> m_sensorySystem;
   std::shared_ptr<MotorSystem> m_motorSystem;
   std::vector<std::shared_ptr<Neuron> > m_interNeurons;
   std::vector<std::shared_ptr<AxonSynapse> > m_outputs;
}
