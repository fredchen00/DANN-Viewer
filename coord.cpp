#include "coord.h"


using  namespace std;

coord::coord(){
	x = 0;
	y = 0;
	z = 0;
}
coord::coord(int x_coord, int y_coord, int z_coord){
	x = x_coord;
	y = y_coord;
	z = z_coord;

}


void coord::setX(int x_coord){
	x = x_coord;
}
void coord::setY(int y_coord){
	y = y_coord;
}
void coord::setZ(int z_coord){
	z = z_coord;
}


int coord::getX(){
	return x;
}
int coord::getY(){
	return y;
}
int coord::getZ(){
	return z;
}