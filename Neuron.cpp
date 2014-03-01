#include "Neuron.h"

using namespace std;




Neuron::Neuron(int x, int y, int z, double _cue, double _actionPotential, double _inputSignal, int _numAxons){
	Pos.setX(x);
	Pos.setY(y);
	Pos.setZ(z);


	cue = _cue;
	actionPotential = _actionPotential;
	inputSignal = _actionPotential;
	numAxons = _numAxons;

}

Neuron::~Neuron(){
	int length = axonSegment.size();
	for (int i = 0; i < length; i++)
		delete axonSegment[i];

}



void Neuron::setCue(double _cue){
	cue = _cue;
}
void Neuron::setActionPotential(double _actionPotential){
	actionPotential = _actionPotential;
}


double Neuron::getCue(){
	return cue;
}
double Neuron::getActionPotential(){
	return actionPotential;
}

vector<Axon*> Neuron::getAxon(){
	return axonSegment;
}

void Neuron::addAxon(Axon * axon){
	axonSegment.push_back(axon);
}