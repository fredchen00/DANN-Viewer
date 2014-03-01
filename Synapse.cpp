#include <iostream>
#include "Synapse.h"


using namespace std;


Synapse::Synapse(double _lifespan, double _weight, int neuron_x, int neuron_y, int neuron_z){
	lifespan = _lifespan;
	weight = _weight;

	neuronTarget.setX(neuron_x);
	neuronTarget.setY(neuron_y);
	neuronTarget.setZ(neuron_z);
}

double Synapse::getLifespan(){
	return lifespan;
}
double Synapse::getWeight(){
	return weight;
}

// Add lifespan increment function here.
void Synapse::setLifespan(double _lifespan){
	lifespan = _lifespan;
}
void Synapse::setWeight(double _weight){
	weight = _weight;

}