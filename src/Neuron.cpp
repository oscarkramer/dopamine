#include <Neuron.h>
#include <Config.h>

using namespace std;

static const double AGING_RATE = 0.01;

Neuron::Dendrite::Dendrite(Neuron* myNeuron, const double& weight)
      :  m_owner(myNeuron),
         m_weight (weight),
         m_value(0)
{
}

void Neuron::Dendrite::activate(const double& level)
{
   m_value = level*m_weight;
}

void Neuron::Dendrite::age()
{
   m_weight *= Config::instance().asFloat("agingRate");
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

void Neuron::age()
{
   for (auto &dendrite : m_inputs)
      dendrite->age();

}
