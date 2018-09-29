//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <Brain.h>
#include <Config.h>
#include <MemoryNeuron.h>

using namespace std;

Brain& Brain::instance()
{
   static Brain singleton;
   return singleton;
}

Brain::Brain()
{
   // Initialize static configuration from config file:
   auto config = Config::instance();
   MemoryNeuron::configure();
   Neuron::Dendrite::configure();

   // Initialize network:
   // Load prior memory states:

}

Brain::~Brain()
{
   // Save all new memories:
   // Teardown network:
}

void Brain::sense(const vector<double> perception)
{
   // Pass the stimulus to the sensory system to begin processing:
}

const vector<double>& Brain::getDecision()
{
   // Fetch the current state of the cognitive system for external evaluation:
   return m_cognitiveSystem->getDecision();
}

void Brain::reward(const double& level)
{
   // Reinforce(+) or discourage(-) the prior decision
}

void Brain::sleep()
{
   // Change mode to permit rewiring given memories and expectations
}

void Brain::age()
{
   // Attenuate synapse weights for little-used pathways
   for (auto &neuron : m_neurons)
      neuron->age();
}

void Brain::registerNeuron(std::shared_ptr<Neuron> neuron)
{
   m_neurons.emplace_back(neuron);
}
