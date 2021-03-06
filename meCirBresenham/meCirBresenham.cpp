// meCirBresenham.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Algoritma pembuat lingkaran

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void cirBresenham();

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Pembuat Lingkaran";

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

	init(); // jalankan fungsi init
	glutDisplayFunc(display); // set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(3.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	cirBresenham(); //jalankan fungsi lingkaran
	glutSwapBuffers(); //swap buffer 
}

void cirBresenham() {
	int xc, yc, r, p, x, y;
	r = 25;		xc = 100;		yc = 70;

	p = 1 - r;
	x = 0;	y = r;

	glBegin(GL_POINTS);
	//1st Problem_START, Addition statements for 1 point for radius-top & radius-bottom.
	glVertex2i(xc, yc + r);
	glVertex2i(xc, yc - r);
	//1st Problem_END
	for (; x <= y; x++) {
		if (p < 0) {
			p += 2 * x + 1;
		}
		else {
			y--;
			p += 2 * x - 2 * y + 1;
		}

		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc - y, yc - x);
	}
	glEnd();
	glFlush();
}