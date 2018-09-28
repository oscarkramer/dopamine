#include <Neuron.h>

using namespace std;

Neuron::Dendrite::Dendrite(Neuron* myNeuron, const double& weight)
:  m_owner(myNeuron),
   m_weight (weight),
   m_value(0)
{
}

Neuron::Neuron()
{

}

Neuron::~Neuron()
{

}

shared_ptr<Neuron::Dendrite> Neuron::connectToThis(const double& weight)
{
   auto dendrite = make_shared<Dendrite>(this, weight);
   m_inputs.emplace_back(dendrite);
   return dendrite;
}

void Neuron::reward(const double& level)
{

}

void Neuron::process()
{

}

void Neuron::sleep()
{

}
