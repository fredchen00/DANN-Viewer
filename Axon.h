
#ifndef AXON_H
#define AXON_H

#include <vector>
#include "Synapse.h"

using namespace std;

class Axon
{
public:
	/** Default constructor */
	Axon();
	Axon(double _searchRadius,int _numSynapses);
	/** Default destructor */
	virtual ~Axon();
	
	void setsearchRadius(double radius);
	void setnumSynapses(int numsynapse);

	double getsearchRadius();
	int getnumSynapses();

	void addSynapse(Synapse * _synapse);


protected:
private:

	//Vector3D* position; 
	//Vector3D* fixedPosition;
	//bool fixed; //not sure how to deal with these three???????

	double searchRadius;
	int numSynapses;
	vector <Synapse*> synapse;

};


#endif