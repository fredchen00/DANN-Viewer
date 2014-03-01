#include <GL\glut.h>


void drawSphere(int x,int y,int z){
	
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(x, y, z);
	glutSolidSphere(0.1, 20, 20);
	glTranslatef(-x, -y, -z);
	glPopMatrix();


}

void drawLine(double b_x,double b_y,double b_z,double e_x,double e_y, double e_z){
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(b_x, b_y, b_z);
	glVertex3f(e_x, e_y, e_z);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0, 0, -4,
		0, 0, 10,
		0, 1, 0);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0, 0);
	glEnd();


	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 20, 20);
	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);
	glutSolidSphere(0.1, 20, 20);

	glPopMatrix();

	glutSwapBuffers();
}


void reshape(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(70.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
