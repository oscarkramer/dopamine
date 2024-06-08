//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <Axon.h>
#include <kommons/AppConfig.h>

using namespace std;
using namespace ka;

double  Axon::s_agingRate = 0;

Axon::Axon()
   :  m_value(0)
{
}

void Axon::propagate(const double& level)
{
}

void Axon::age()
{
}

void Axon::configure()
{
   AppConfig::instance()->get("agingRate", s_agingRate);
}

