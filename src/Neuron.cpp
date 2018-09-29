//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <Neuron.h>
#include <MemoryNeuron.h>
#include <Config.h>
#include <Brain.h>

using namespace std;
double  Neuron::Dendrite::s_agingRate = 0;

Neuron::Dendrite::Dendrite(const double& weight)
      :  m_weight (weight),
         m_value(0)
{
}

void Neuron::Dendrite::activate(const double& level)
{
   m_value = level*m_weight;
}

void Neuron::Dendrite::age()
{
   m_weight *= s_agingRate;
}

void Neuron::Dendrite::configure()
{
   s_agingRate = Config::instance().asFloat("agingRate");
}

Neuron::Neuron()
      :  m_state(0)
{
   Brain::instance().registerNeuron(make_shared<Neuron>(*this));
}

Neuron::~Neuron()
{

}

shared_ptr<Neuron::Dendrite> Neuron::connectToThis(const double& weight)
{
   auto dendrite = make_shared<Dendrite>(weight);
   m_inputs.emplace_back(dendrite);
   return dendrite;
}

void Neuron::reward(const double& level)
{
   // If positive, check if this neuron was a positive contributor:
   if ((level > 0) && (m_state > m_highThreshold))
   {
      latchMemory();
      m_highThreshold = m_state;
   }
   else if ((level < 0) && (m_state < m_lowThreshold))
   {
      latchMemory();
      m_lowThreshold = m_state;
   }

   // Amplify the weights according to the reward
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

void Neuron::latchMemory ()
{
   auto memNeuron = make_shared<MemoryNeuron>(*this);

}
