#ifndef MemorySystem_H
#define MemorySystem_H

#include "MemoryNeuron.h"

class MemorySystem
{
public:
   MemorySystem();
   ~MemorySystem();

   void stimulate(const std::vector<double> perception);

private:
   std::vector<std::shared_ptr<MemoryNeuron> > m_memoryNeurons;

};

#endif