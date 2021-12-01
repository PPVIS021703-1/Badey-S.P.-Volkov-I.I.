#pragma once
#ifndef _SMALL_CUBE_H
#define _SMALL_CUBE_H

#include <glut.h>
#include <cstring>

//////////////////////////////////
///	\author Badey S.P. Volkov I.I.
///	\brief  class of Rubik's cube parts, a large cube will consist of 27 small.
///	\date November 2021
///
//////////////////////////////////////

struct Small_Cube
{

	unsigned int color[6]; /* ... six sides of a cube - six colors ... */

	double size; /* ... cube size ... */

	Small_Cube()
	{
		memset(color, 0, sizeof(color)); /* ... six sides of a cube - six colors ... */
		size = 0.0;
	}

	void rotateZ() /* ... X0Y rotation method ... */
	{
		unsigned int tmp = color[5];
		color[5] = color[3];
		color[3] = color[4];
		color[4] = color[2];
		color[2] = tmp;
	}

	void rotateY() /* ... X0Z rotation method ... */
	{
		unsigned int tmp = color[2];
		color[2] = color[1];
		color[1] = color[3];
		color[3] = color[0];
		color[0] = tmp;
	}

	void rotateX() /* ... Y0Z rotation method... */
	{
		unsigned int tmp = color[0];
		color[0] = color[4];
		color[4] = color[1];
		color[1] = color[5];
		color[5] = tmp;
	}

	void setColor(int i, int color) /* ... method for obtaining the color of a face ... */
	{
		this->color[i] = color;
	}

	unsigned char* at(int i)
	{
		_color[0] = color[i] >> 16;
		_color[1] = color[i] >> 8;
		_color[2] = color[i];
		return _color;
	}

	void draw() /* ... cube drawing method ... */
	{
		glPushMatrix();
		glBegin(GL_QUADS);

	
		glColor3ubv(at(0));
		glNormal3f(0, 0, 1);
		glVertex3f(size, size, size);
		glVertex3f(0, size, size);
		glVertex3f(0, 0, size);
		glVertex3f(size, 0, size);

	
		glColor3ubv(at(1));
		glNormal3f(0, 0, -1);
		glVertex3f(size, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, size, 0);
		glVertex3f(size, size, 0);

	
		glColor3ubv(at(2));
		glNormal3f(0, -1, 0);
		glVertex3f(size, 0, size);
		glVertex3f(0, 0, size);
		glVertex3f(0, 0, 0);
		glVertex3f(size, 0, 0);

	
		glColor3ubv(at(3));
		glNormal3f(0, 1, 0);
		glVertex3f(size, size, 0);
		glVertex3f(0, size, 0);
		glVertex3f(0, size, size);
		glVertex3f(size, size, size);

	
		glColor3ubv(at(4));
		glNormal3f(-1, 0, 0);
		glVertex3f(0, size, size);
		glVertex3f(0, size, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, size);


		glColor3ubv(at(5));
		glNormal3f(1, 0, 0);
		glVertex3f(size, size, 0);
		glVertex3f(size, size, size);
		glVertex3f(size, 0, size);
		glVertex3f(size, 0, 0);

		glEnd();
		glPopMatrix();
	}

	void draw(double x, double y, double z) /* ... cube drawing method with offset (x, y, z) ... */
	{
		glPushMatrix();
		glTranslated(x, y, z);
		draw();
		glPopMatrix();
	}

private:
	unsigned char _color[4];
};


#endif;