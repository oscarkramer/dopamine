#include <memory>
#include <vector>

class AxonSynapse : public Synapse
{
public:
   AxonSynapse(std::shared_ptr<Neuron> owner, const double& weight=1.0);
   ~AxonSynapse();

   void activate(const double& level) override;
}
