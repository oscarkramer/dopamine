//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef DOPAMINE_DENDRITE_H
#define DOPAMINE_DENDRITE_H

class Dendrite
{
public:
   Dendrite(const double& weight=1.0);
   void activate(const double& level=1.0);
   void age();

   /** Initializes static members once at program startup (called from Brain) */
   static void configure();

   double m_weight;
   double m_value;
   static double s_agingRate;
};


#endif //DOPAMINE_DENDRITE_H
