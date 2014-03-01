#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
#include <GL\glut.h>
#include "Neuron.h"
#include "coord.h"


#define Max_X 10
#define Max_Y 10
#define Max_Z 10

using namespace std;
 

vector<vector<vector<Neuron*> > > neuron;


void initializeNeuron(){


	neuron.resize(Max_X);
	for (int i = 0; i < Max_X; i++) {
			neuron[i].resize(Max_Y);
			for (int j = 0; j < Max_Y; j++) {
				neuron[i][j].resize(Max_Z);
				for (int k = 0; k < Max_Z; k++) {
					//cue = (double)rand()/((double)RAND_MAX/2) - 1;    // A random float value between -1 and 1.
					//neuron[i][j][k] = new InterNeuron(cue, actionPotential);
					//neuron[i][j][k] = new  neuron();
				}
			}
	}
}



void readFile(ifstream& rFile){
	
	bool newConnection = false, newNode = false;
	coord newNeuronPos;
	string nodeInfo;
	string firstComponents;
	string components;
	stringstream parser;
	
	
	getline(rFile, nodeInfo);
	parser << nodeInfo;
	parser >> firstComponents;

	while (!rFile.eof() && firstComponents != "end")
	{
		int numAxon = 0, numSynapse=0;
			// parse the string using white space
		cout<<"nodeinfo: " << nodeInfo << endl;
		if (firstComponents == "N"){
			int components;
			double cue,actionPotential,inputSignal;

			parser >> components;
			newNeuronPos.setX(components);
			parser >> components;
			newNeuronPos.setY(components);
			parser >> components;
			newNeuronPos.setZ(components);
			parser >> cue >> actionPotential >> inputSignal >> numAxon;
			
			int x = newNeuronPos.getX();
			int y = newNeuronPos.getY();
			int z = newNeuronPos.getZ();

			neuron[x][y][z] = new Neuron(x, y, z, cue, actionPotential, inputSignal, numAxon);;
			//cout << " N:" << newNode_coord.x << " " << newNode_coord.y << " " << newNode_coord.z << endl;
		}

		int nx = newNeuronPos.getX();
		int ny = newNeuronPos.getY();
		int nz = newNeuronPos.getZ(); 

		for (int i = 0; i < numAxon; i++){
			
			getline(rFile, nodeInfo);
			parser << nodeInfo;
			parser >> components;
			cout << "comp: " << components << endl;
			double searchRadius;
			parser >> searchRadius >> numSynapse;
			Axon* axon = new Axon(searchRadius, numSynapse);
			
			for (int j = 0; j < numSynapse; j++){

				getline(rFile, nodeInfo);
				parser << nodeInfo;
				parser >> components;

				int targetX, targetY, targetZ;
				int lifespan, weight;
				parser >> lifespan >> weight >> targetX >> targetY >> targetZ;
				Synapse* synapse = new Synapse(lifespan, weight, targetX, targetY, targetZ);
				axon->addSynapse(synapse);
			}
			neuron[nz][ny][nx]->addAxon(axon);
		}

		getline(rFile, nodeInfo);
		parser << nodeInfo;
		parser >> firstComponents;
	}
}


int main(int argc, char **argv) {
	
	//initialize neuron class.
	
	initializeNeuron();




	//read file
	string filename;
	cout << "Please enter the file to read: ";
	getline(cin, filename);
	ifstream rFile(filename, ifstream::in);
	
	readFile(rFile);

	cout << neuron[0][0][0]->getCue() << neuron[0][0][1]->getCue() << endl;

	// init GLUT and create window


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");


	// register callbacks
	//glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutIdleFunc(display);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}