#include <Brain.h>

using namespace std;

Brain::Brain()
{
   // Initialize network:
   // Load prior memory states:

}

Brain::~Brain()
{
   // Save all new memories:
   // Teardown network:
}

void Brain::stimulate(const vector<double> perception)
{
   // Pass the stimulus to the sensory system to begin processing:
}

const vector<double> Brain::decision()
{
   // Fetch the current state of the cognitive system for external evaluation:
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
}
