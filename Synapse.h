#ifndef SYNAPSE_H
#define SYNAPSE_H

#include <queue>
#include "coord.h"


class Neuron;

class Synapse
{
public:
	/** Default constructor */
	Synapse();
	Synapse(double _lifespan, double _weight, int neuron_x, int neuron_y,int neuron_z);


	/** Get and Set functions */
	double getLifespan();
	double getWeight();

	// Add lifespan increment function here.
	void setLifespan(double _lifespan);
	void setWeight(double _weight);

protected:
private:

	double lifespan;
	double weight;
	coord neuronTarget;
};


#endif