//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef Neuron_H
#define Neuron_H

#include <memory>
#include <vector>
#include <Dendrite.h>
#include <Axon.h>

class Neuron
{
public:

   Neuron();

   Neuron(Neuron& dupThis);

   ~Neuron();

   /** Creates a dendrite connection to the input neuron with specified initial weight */
   std::shared_ptr<Dendrite> connectToThis(const double& weight=1.0);

   /** "Dopamine" flood to reinforce (positive) [or punish (negative)] current state */
   virtual void reward(const double& level=1.0);

   /** Latches input signals, sums, and presents resulting state to the output synapses */
   virtual void process();

   /** Depreciate the contribution of inactive synapses and find new connections */
   virtual void sleep();

   /** Apply global degradation to input dendrites to eventually eliminate unused synapses */
   virtual void age();

   double getState () const  { return m_state; }
   std::vector<std::shared_ptr<Dendrite> >& getInputs() { return m_dendrites; }
   std::shared_ptr<Axon>& getOutput() { return m_axon; }

   /** Callback to timer interrupt to effect decays, connection exploration, or cleanup. 
    *  Should be overridden. */
   virtual void processTimerEvent() {}
   
protected:
   /** If this neuron contributed to a high reward outcome, latch the memory by duplicating this
    * and freezing the weights and connections. The input and output connections will be
    * forever preserved, and the new memory neuron will not explore new connections */
   void latchMemory();

   std::vector<std::shared_ptr<Dendrite> > m_dendrites;
   std::shared_ptr<Axon> m_axon;
   double m_state;
   double m_highThreshold; //!< Threshold for creating good memory, latches new max
   double m_lowThreshold;  //!< Threshold for creating bad memory, latches new min
   double m_dopeLevel;     //!< Dopamine level decays with time, acts as reward for previous decision
};

#endif
