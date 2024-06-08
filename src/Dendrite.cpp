//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <Dendrite.h>
#include <kommons/AppConfig.h>

using namespace std;
using namespace ka;

double  Dendrite::s_agingRate = 0;

Dendrite::Dendrite(const double& weight)
   :  m_weight (weight),
      m_value(0)
{
}

void Dendrite::activate(const double& level)
{
   m_value = level*m_weight;
}

void Dendrite::age()
{
   m_weight *= s_agingRate;
}

void Dendrite::configure()
{
   AppConfig::instance()->get("agingRate", s_agingRate);
}

