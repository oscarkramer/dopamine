//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <MemoryNeuron.h>
#include <Brain.h>
#include <Config.h>

using namespace std;

double MemoryNeuron::s_memEpsilon = 0;
double MemoryNeuron::s_recallThreshold = 0;

MemoryNeuron::MemoryNeuron(Neuron& dupThis)
:  Neuron(),
   m_latchedState(dupThis.getState())
{
   for (auto &dendrite : dupThis.getInputs())
   {
      // The ordering of dendrites corresponds to latched inputs, used later for signal comparison:
      m_inputs.emplace_back(dendrite);
      m_latchedInputs.emplace_back(dendrite->m_value);
   }

   for (auto &dendrite : dupThis.getOutputs())
      m_outputs.emplace_back(dendrite);
}


void MemoryNeuron::process()
{
   // Rather than summing the inputs, the memory neuron looks for a close match to the
   // original experience, and activates when match found:
   int numFailed = 0;
   int maxNumFail = (int)((1.0-s_recallThreshold) * m_inputs.size());
   m_state = 0;
   for (size_t i=0; (i<m_inputs.size())&&(numFailed<maxNumFail); ++i)
   {
      if (fabs(m_inputs[i]->m_value - m_latchedInputs[i]) > s_memEpsilon)
         ++numFailed;
   }
   if (numFailed < maxNumFail)
   {
      // Good match, compute response weighted by relative failure ratio:
      m_state = (1.0 - (double)numFailed/m_inputs.size()) * m_latchedState;
   }
}

void MemoryNeuron::configure ()
{
   s_memEpsilon = Config::instance().asFloat("memEpsilon");
   s_recallThreshold = Config::instance().asFloat("recallThreshold");
}

