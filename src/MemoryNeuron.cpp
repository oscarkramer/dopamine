//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <MemoryNeuron.h>
#include <Brain.h>
#include <kommons/AppConfig.h>
#include <cmath>

using namespace std;
using namespace ka;

double MemoryNeuron::s_memEpsilon = 0;
double MemoryNeuron::s_recallThreshold = 0;

MemoryNeuron::MemoryNeuron(Neuron& remThis)
:  Neuron(remThis),
   m_latchedState(remThis.getState())
{
   for (auto &dendrite : m_dendrites)
   {
      // The ordering of dendrites corresponds to latched inputs, used later for signal comparison:
      m_latchedInputs.emplace_back(dendrite->m_value);
   }
}


void MemoryNeuron::process()
{
   // Rather than summing the inputs, the memory neuron looks for a close match to the
   // original experience, and activates when match found:
   int numFailed = 0;
   int maxNumFail = (int)((1.0-s_recallThreshold) * m_dendrites.size());
   m_state = 0;
   for (size_t i=0; (i<m_dendrites.size())&&(numFailed<maxNumFail); ++i)
   {
      if (fabs(m_dendrites[i]->m_value - m_latchedInputs[i]) > s_memEpsilon)
         ++numFailed;
   }
   if (numFailed < maxNumFail)
   {
      // Good match, compute response weighted by relative failure ratio:
      m_state = (1.0 - (double)numFailed/m_dendrites.size()) * m_latchedState;
   }
}

void MemoryNeuron::configure ()
{
   AppConfig::instance()->get("memEpsilon", s_memEpsilon);
   AppConfig::instance()->get("recallThreshold", s_recallThreshold);
}

