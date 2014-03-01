#include "Axon.h"

using namespace std;



Axon::Axon(double _searchRadius, int _numSynapses){
	searchRadius = _searchRadius;
	numSynapses = _numSynapses;
}

Axon::~Axon(){
	int length = synapse.size();
	for (int i = 0; i < length; i++)
		delete synapse[i];
}

void Axon::setsearchRadius(double radius){
	searchRadius = radius;
}
void Axon::setnumSynapses(int numsynapse){
	numSynapses = numsynapse;

}

double Axon::getsearchRadius(){
	return searchRadius;
}
int Axon::getnumSynapses(){
	return numSynapses;
}

void Axon::addSynapse(Synapse* _synapse){
	synapse.push_back(_synapse);
}