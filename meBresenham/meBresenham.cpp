// meBresenham.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Algoritma Bresenham

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void bresenham();

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Bresenham";

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
	glutCreateWindow(judul_window); //set judul window


	init(); //jalankan fungsi init 
	glutDisplayFunc(display); //  set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(10.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(); //jalankan fungsi bresenham
	glutSwapBuffers(); //swap buffer 
}

void bresenham() {
	int x1, y1, x2, y2, x, y, dx, dy, xend, p, yY2, yX2;
	bool tagDist, tagInc;

	x1 = 200;	y1 = 80;
	x2 = 100; 	y2 = 50;

	x = x1;		y = y1;

	dx = x2 - x1;	dy = y2 - y1;
	dx = abs(dx);	dy = abs(dy);

	

	//1st Problem_START, Modified Conditional for 1 Point. It means that if start point and end point is equals will it just make 1 point and draw it. Below the codes:
	if (dx == 0 && dy == 0){
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		printf("x = %d\t y = %d \n", x, y);
		glEnd();
		glFlush(); cout << dy;
		return;
	}
	//1st Problem_END

	//2nd Problem_START, Modified Conditional for Looping whether Dx (distance of x1 to x2) or Dy (distance of y1 to y2) higher. It will be the proposed looping.
	if (dx >= dy) {
		tagDist = true; //true means Dx Higher
	}
	else {
		tagDist = false; //false means Dy higher
	}
	//2nd Problem_END

	//3rd Problem_START, Modified Conditionals for tagging (flag) X or Y axis directions, P for effecting the inc/decrement on all axes.
	if (tagDist) { //X for proposed looping
		yY2 = 2 * dy;	yX2 = 2 * dy - 2 * dx;
		p = 2 * dy - dx;

		if (x1 > x2) {
			x = x2;
			y = y2;
			xend = x1;
			tagInc = false;
		}
		else
		{
			x = x1;
			y = y1;
			xend = x2;
			tagInc = true;
		}
	}
	else { //Y for proposed looping
		yY2 = 2 * dx;	yX2 = 2 * dx - 2 * dy;
		p = 2 * dx - dy;

		if (y1 > y2) {
			x = y2; //swap x <- y
			y = x2; //swap y <- x
			xend = y1; //swap x <- y
			tagInc = false;
		}
		else
		{
			x = y1; //swap x <- y
			y = x1; //swap y <- x
			xend = y2; //swap x <- y
			tagInc = true;
		}
	}
	//3rd Problem
	glBegin(GL_POINTS);

	glVertex2i(x, y);
	for (; x < xend; x++) {
		//simple condition for printing.
		if(tagDist)
			printf("x = %d\t y = %d \n", x, y);
		else
			printf("x = %d\t y = %d \n", y, x);

		if (p < 0) {
			p += yY2;
		}
		else
		{
			//3rd Problem Cont., Tag used for directions codition of X / Y axis. 
			//tagDist already discussed above. tagInc == true means that Y is X1 or Y is Y1, false for another one.
			if (tagDist) {
				if (tagInc) {
					if (y > y2)
						y--;
					else
						y++;
				}
				else {
					if (y > y1)
						y--;
					else
						y++;
				}
			}
			else {
				if (tagInc) {
					if (y > x2)
						y--;
					else
						y++;
				}
				else {
					if (y > x1)
						y--;
					else
						y++;
				}
			}
			//3rd Problem_END
			p += yX2;
		}
		glVertex2i(x, y);
	}
	//simple condition for printing.
	if (tagDist)
		printf("x = %d\t y = %d \n", x, y);
	else
		printf("x = %d\t y = %d \n", y, x);

	glEnd();
	glFlush();
}

