#pragma once
#ifndef _CUBE_H
#define _CUBE_H

#include "Small_Cube.h"
#include <cstring>

/*!
	\author Badey S.P. Volkov I.I.
	\brief Rubik's cube class, consisting of 27 small cubes.
	\date November 2021

*/

class Cube
{

	Small_Cube a[4][4][4];

	int rotate[6];

	double size;

	unsigned int color[6];
	

public:
	int current;
	int sizeCUBE = 3;

	Cube()
	{

	}

	Cube(double size, unsigned int* color, int sizeCUBE)
	{
		clear(size, color, sizeCUBE);
	}

	void clear(double size, unsigned int* color, int sizeCUBE)
	{
		this->size = size;
		current = -1;

		int i, j, k;
		for (i = 0; i < 6; i++)
			this->color[i] = color[i];


		for (i = 0; i < sizeCUBE; i++)
			for (j = 0; j < sizeCUBE; j++)
				a[i][j][sizeCUBE - 1].setColor(0, color[0]);


		for (i = 0; i < sizeCUBE; i++)
			for (j = 0; j < sizeCUBE; j++)
				a[i][j][0].setColor(1, color[1]);


		for (k = 0; k < sizeCUBE; k++)
			for (j = 0; j < sizeCUBE; j++)
				a[j][0][k].setColor(2, color[2]);

	
		for (k = 0; k < sizeCUBE; k++)
			for (j = 0; j < sizeCUBE; j++)
				a[j][sizeCUBE-1][k].setColor(3, color[3]);

	
		for (i = 0; i < sizeCUBE; i++)
			for (k = 0; k < sizeCUBE; k++)
				a[0][k][i].setColor(4, color[4]);

		
		for (i = 0; i < sizeCUBE; i++)
			for (k = 0; k < sizeCUBE; k++)
				a[sizeCUBE-1][k][i].setColor(5, color[5]);


		for (i = 0; i < sizeCUBE; i++)
			for (j = 0; j < sizeCUBE; j++)
				for (k = 0; k < sizeCUBE; k++)
					a[i][j][k].size = (size / 3.0) * 0.95;
	}


	void draw() /*... drawing a cube ...*/
	{
		//const double K = 1;


		memset(ok, true, sizeof(ok));
		if (current != -1)
		{
			glPushMatrix();
			int i, j, k;

			if (current == 0 || current == 1)
			{

				k = (current & 1) * 2;
				for (i = 0; i < sizeCUBE; i++)
					for (j = 0; j < sizeCUBE; j++)
						ok[i][j][k] = false;


				glTranslated(size / 2, size / 2, 0);   // сдвигаемся к центру
				glRotatef(rotate[current], 0, 0, 1);   // крутим
				glTranslated(-size / 2, -size / 2, 0); // сдвигаемся обратно
				// рисуем
				for (i = 0; i < sizeCUBE; i++)
					for (j = 0; j < sizeCUBE; j++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			// аналагично с остальными четырмя гранями
			else if (current == 2 || current == 3)
			{
				j = (current & 1) * 2;
				for (i = 0; i < sizeCUBE; i++)
					for (k = 0; k < sizeCUBE; k++)
						ok[i][j][k] = false;

				glTranslated(size / 2, 0, size / 2);
				glRotatef(rotate[current], 0, 1, 0);
				glTranslated(-size / 2, 0, -size / 2);
				for (i = 0; i < sizeCUBE; i++)
					for (k = 0; k < sizeCUBE; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			else if (current == 4 || current == 5)
			{
				i = (current & 1) * 2;
				for (j = 0; j < sizeCUBE; j++)
					for (k = 0; k < sizeCUBE; k++)
						ok[i][j][k] = false;

				glTranslated(0, size / 2, size / 2);
				glRotatef(rotate[current], 1, 0, 0);
				glTranslated(0, -size / 2, -size / 2);
				for (j = 0; j < sizeCUBE; j++)
					for (k = 0; k < sizeCUBE; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			glPopMatrix();
		}

		for (int i = 0; i < sizeCUBE; i++)
			for (int j = 0; j < sizeCUBE; j++)
				for (int k = 0; k < sizeCUBE; k++)
					if (ok[i][j][k])
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
	}

	void rot90(int idx, int sign) /*... cube face rotation ...*/
	{
		int i, j, k;
		if (sign == -1)
			sign = 3;
		while (sign--)
		{
			if (idx == 0 || idx == 1)
			{
				// низ/верх
				k = (idx & 1) * 2;
				// копируем повёрнутую на 90 градусов верхнюю/нижнюю грань
				// в массив tmp, затем грани присваиваем tmp
				// и не забываем повернуть каждую деталь этой грани
				for (i = 0; i < 4; i++)
					for (j = 0; j < 4; j++)
						tmp[j][2 - i] = a[i][j][k];
				for (i = 0; i < 4; i++)
					for (j = 0; j < 4; j++)
						tmp[i][j].rotateZ(), a[i][j][k] = tmp[i][j];
			}
			// аналогично с остальными четырмя гранями
			else if (idx == 2 || idx == 3)
			{
				// лево/право
				j = (idx & 1) * 2;
				for (i = 0; i < 4; i++)
					for (k = 0; k < 4; k++)
						tmp[k][2 - i] = a[i][j][k];
				for (i = 0; i < 4; i++)
					for (k = 0; k < 4; k++)
						tmp[i][k].rotateX(), a[i][j][k] = tmp[i][k];
			}
			else if (idx == 4 || idx == 5)
			{
				// впереди/сзади
				i = (idx & 1) * 2;
				for (j = 0; j < 4; j++)
					for (k = 0; k < 4; k++)
						tmp[k][2 - j] = a[i][j][k];
				for (j = 0; j < 4; j++)
					for (k = 0; k < 4; k++)
						tmp[j][k].rotateY(), a[i][j][k] = tmp[j][k];
			}
		}
	}
	
	Cube& operator++() /*... increment overload ...*/
	{
		this->sizeCUBE++;
		return *this;
	}

	Cube& operator--() /*... overload of dicrement ...*/
	{
		this->sizeCUBE--;
		return *this;
	}
	Cube& operator++(int x) /*... increment overload ...*/
	{
		this->sizeCUBE++;
		return *this;
	}
	Cube& operator--(int y) /*... overload of dicrement ...*/
	{
		this->sizeCUBE--;
		return *this;
	}

	// крутит грань под номером idx на угол angle (в градусах)
	void Rotate(int idx, int angle) /*... twists the face at idx by angle angle (in degrees) ...*/
	{
		// мы пытаемся покрутить грань с номером idx
		// значит нужно проверить что другая грань уже не крутится
		if (current == -1 || current == idx)
		{
			// обновляем поворот
			rotate[idx] += angle;

			if (rotate[idx] % 90 != 0)
			{
				current = idx;
			}
			else
			{
				// если угол стал кратным 90, то поварачиваем на массиве
				if ((rotate[idx] < 0) ^ (current == 2 || current == 3))
					rot90(idx, 1);
				else
					rot90(idx, -1);
				rotate[idx] = 0;
				current = -1;
			}
		}
	}
private:
	int _angle[4];
	bool ok[4][4][4];
	Small_Cube tmp[4][4];
};

#endif;