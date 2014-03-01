#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "Axon.h"

using namespace std;

class Neuron
{
public:
	/** Default constructor */
	Neuron();
	Neuron(int x, int y, int z, double cue, double actionPotential,double inputSignal,int numAxons);
	/** Default destructor */
	virtual ~Neuron();

	void setCue(double _cue);
	void setActionPotential(double actionPotential);


	double getCue();
	double getActionPotential();
	vector<Axon*> getAxon();

	void addAxon(Axon* axon );


protected:
private:

	coord Pos;
	double cue;
	double actionPotential;
	double inputSignal;
	int numAxons;
	vector <Axon*> axonSegment;

};







#endif