#include "Cube.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>

#define CUBE_SIZE 13
#define TIMER 15

//                    (����,      ���,   �������,   �����,    ����,      �����)
unsigned int c[9] = { 0x0000FF, 0x00FF00, 0xFFFF00, 0xFFFFFF, 0xFF0000, 0xCD853F };

// ���������� ��������� �����
GLfloat lightPos[] = { 0, 100, 200, 0 };
// �������� ���� �������� �� ���
int xRot = 24, yRot = 34, zRot = 0;
// ���������
double translateZ = -35.0;
// �����-�����
Cube cube;
//�������� ��� ���, ��� ��� (����� ������������� ������ ������� ����)
int timerOn = 0;

void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0, 0, translateZ);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glTranslatef(CUBE_SIZE / -2.0, CUBE_SIZE / -2.0, CUBE_SIZE / -2.0);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(60, fAspect, 1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// �������������� ��������� �����
	srand(time(0));

	// ���������
	float mat_specular[] = { 0.3, 0.3, 0.3, 0 };
	float diffuseLight[] = { 0.2, 0.2, 0.2, 1 };
	float ambientLight[] = { 0.9, 0.9, 0.9, 1.0 };
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	cube.clear(CUBE_SIZE, c, cube.sizeCUBE);
}

void specialKeys(int key, int, int)
{

	if (key == GLUT_KEY_DOWN)
	{
		xRot += 3;
		if (xRot >= 360)
			xRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_UP)
	{
		xRot -= 3;
		if (xRot < 0)
			xRot += 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_RIGHT)
	{
		yRot += 3;
		if (yRot >= 360)
			yRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_LEFT)
	{
		yRot -= 3;
		if (yRot < 0)
			yRot += 360;
		glutPostRedisplay();
	}

}

void keys(unsigned char key, int, int)
{
	// ���� ������ ������� �� 0 �� 5 - �������� ������� �� 3 �������
	if (cube.current == -1 && key >= '0' && key < '6')
	{
		cube.Rotate(key - '0', 3);
		display();
	}
}

void mouse(int key, int state, int, int)
{
	if (key == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// ����������� ����
		timerOn = 1 - timerOn;
	}
}

void timer(int)
{
	glutTimerFunc(TIMER, timer, 0);
	if (timerOn)
	{
		// ���� ������� �������������� �������, � �������
		// ���� ������ ������� ����� �� ��������, �� �������� ������� ���������,
		// ����� ������ �������
		if (cube.current == -1)
			keys(rand() % 6 + '0', 0, 0);
		else
			cube.Rotate(cube.current, 3);
	}
	else
	{
		if (cube.current != -1)
			cube.Rotate(cube.current, 3);
	}
	display();
}

void fu(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glutTimerFunc(TIMER, timer, 0);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
}
void fu1(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(TIMER, timer, 0);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	int v;
	std::cout << "/*��� ����, ����� ������ ��������� ��������� ���������� ������ ������� \n������ ������ ���� ����� ���������, ������� ����� ������ ������ ����*/" << std::endl << std::endl << std::endl << std::endl;
	std::cout << "	��� ������ ������ 3�3 ������� 1, ��� ������ ����������-1 ������� 2, ��� ������ ����������-2 ������� 3" << std::endl;
	std::cin >> v;
	switch (v)
	{
	case 1:
		std::cout << std::endl;
		fu(argc, argv);
	case 2:
		++cube;
		fu1(argc, argv);
	case 3:
		--cube;
		fu1(argc, argv);
	case 4:
		cube++;
		fu1(argc, argv);
	case 5:
		cube--;
		fu1(argc, argv);
	default:
		break;
	}
	return 0;
}