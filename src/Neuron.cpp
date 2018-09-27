#include <Neuron.h>

using namespace std;

Neuron::Neuron() {}
Neuron::~Neuron() {}

void Neuron::connectToThis(std::shared_ptr<Neuron> input, const double& weight) {}

void Neuron::reward(const double& level) {}

void Neuron::process() {}

void Neuron::sleep() {}
