#ifndef COORD_H
#define COORD_H

#include <queue>

class Neuron;

class coord
{
public:
	coord ();
	coord(int x_coord, int y_coord, int z_coord);



	void setX(int x_coord);
	void setY(int y_coord);
	void setZ(int z_coord);


	int getX();
	int getY();
	int getZ();

protected:
private:

	int x;
	int y;
	int z;
};


#endif