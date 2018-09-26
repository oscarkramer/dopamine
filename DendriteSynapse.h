#include "Synapse.h"

class DendriteSynapse : public Synapse
{
public:
   DendriteSynapse(std::shared_ptr<Neuron> owner, const double& weight=1.0);
   ~DendriteSynapse();

   void activate(const double& level) override;
}
