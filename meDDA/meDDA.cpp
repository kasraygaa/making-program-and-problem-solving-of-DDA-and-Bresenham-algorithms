// meDDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Algoritma DDA

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void dda();

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma DDA";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);


	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(0.0, 1.0, 1.0); //set warna titik
	glPointSize(10.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda 
	glutSwapBuffers(); //swap buffer 
}

void dda() {
	int x1, y1, x2, y2;
	double x, y, xInc, yInc, dx, dy, steps;

	x1 = 40;		y1 = -50;
	x2 = -50;		y2 = 100;

	x = x1;		y = y1;

	dx = x2 - x1;	dy = y2 - y1;
	dx = abs(dx);	dy = abs(dy);

	if (dx > dy) {
		steps = dx;
	}
	else {
		steps = dy;
	}

	glBegin(GL_POINTS);
	//Here it is 1 point that mentioned below in 1st Problem.
	glVertex2i(x, y);
	//1st Problem_START, Modified Conditional for 1 Point. It means that if start point and end point is equals will it just make 1 point that already running.
	printf("x = %.0f\t y = %.0f \n", round(x), round(y));
	if (steps == 0) {
		glEnd();
		glFlush();
		return;
	}
	//1st Problem_END
	xInc = dx / steps;
	yInc = dy / steps;

	for (int i = 0; i <steps; i ++)
	{
		//1st Problem_START, Modified Conditionals for directions of X and Y in every loop.
		if (x1 <= x2 && y1 <= y2) {
			x = x + xInc;
			y = y + yInc;
		}
		else if (x1 >= x2 && y1 <= y2)
		{
			x = x - xInc;
			y = y + yInc;
		}
		else if (x1 <= x2 && y1 >= y2)
		{
			x = x + xInc;
			y = y - yInc;

		}
		else {
			x = x - xInc;
			y = y - yInc;
		}
		//2nd Problem_END
		glVertex2i(round(x), round(y));
		printf("x = %.0f\t y = %.0f \n", round(x), round(y));
	}
	glEnd();
	glFlush();
}



