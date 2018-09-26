#include <memory>
#include <vector>

class Synapse
{
public:
   Synapse(std::shared_ptr<Synapse> connection, const double& weight=1.0);
   ~Synapse();

   void activate(const double& level);

private:
   std::shared_ptr<Synapse> > m_connection;
   double m_damping;
   std::shared_ptr<Neuron> m_neuron;
}
