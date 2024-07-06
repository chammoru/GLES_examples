#include <iostream>
#include "GL/freeglut.h"


GLuint g_window_w = 500;
GLuint g_window_h = 500;


void Reshape(int w, int h);
void Display();
void Keyboard(unsigned char key, int x, int y);
void SpeicalKeyboard(int key, int x, int y);
void Mouse(int button, int state, int x, int y);
void MouseMotion(int x, int y);
void Timer(int value);



int main(int argc, char** argv)
{

	///////////////////////////////////////////////////////////////////////////////
	//// freeglut �ʱ�ȭ, ������ �����ϱ�. 
	//// Ref: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/GLUT
	///////////////////////////////////////////////////////////////////////////////

	// 1. �ֱ�ȭ
	glutInit(&argc, argv);

	// 2. ������ ��� ����. 
	// ������۸�, RGB �����ӹ���, Depth ���۸� ����Ѵ�.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// 3. ������ ������ ���� (����, ���� �ȼ� ��).
	glutInitWindowSize(g_window_w, g_window_h);

	// 4. OpenGL Context�� ������ ����.
	glutCreateWindow("Computer Graphics");

	// 5. Callback functions 
	// Ref: http://freeglut.sourceforge.net/docs/api.php#GlobalCallback
	//      http://freeglut.sourceforge.net/docs/api.php#WindowCallback
	//      https://www.opengl.org/resources/libraries/glut/spec3/node45.html
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpeicalKeyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);
	glutTimerFunc(1000, Timer, 0);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	// 6. freeglut ������ �̺�Ʈ ó�� ���� ����. �����찡 ���������� ���ѷ���.
	glutMainLoop();
	std::cout << "A";
	return 0;
}



/**
Display: ������ ȭ���� ������Ʈ �� �ʿ䰡 ���� �� ȣ��Ǵ� callback �Լ�.
������ �� ���� ����� ������ �ϴ� �ڵ�� �� �Լ� ���� �����ؾ��Ѵ�.
�����찡 ó�� ���� ��, ������ ũ�Ⱑ �ٲ� ��, �ٸ� �����쿡 ���� ȭ���� �Ϻ�
�Ǵ� ��ü�� �������ٰ� �ٽ� ��Ÿ�� �� �� �ý����� �ش� ������ ���� �׸��� ����
������Ʈ�� �ʿ��ϴٰ� �Ǵ��ϴ� ��� �ڵ����� ȣ��ȴ�.
���� ȣ���� �ʿ��� ��쿡�� glutPostRedisplay() �Լ��� ȣ���ϸ�ȴ�.
�� �Լ��� �ҽÿ� ����ϰ� ȣ��ȴٴ� ���� ����ϰ�, ������ ���� ��ȭ�� ������
1ȸ�� �ڵ�� �������� �� �Լ� �ۿ� �����ؾ��Ѵ�. Ư�� �޸� �Ҵ�, VAO, VBO ����
���� �ϵ���� ������ �õ��ϴ� �ڵ�� Ư���� ������ ���ٸ� ���� �� �Լ��� ���Խ�Ű��
�ȵȴ�. ���� ���, �޽� ���� �����ϰ� VAO, VBO�� �����ϴ� �κ��� ���� 1ȸ��
�����ϸ�ǹǷ� main() �Լ� �� �ܺο� �����ؾ��Ѵ�. ���ǵ� �޽� ���� ������ ���ۿ�
�׸����� �����ϴ� �ڵ常 �� �Լ��� �����ϸ� �ȴ�.
����, �� �Լ� ������ ���� �޸� �Ҵ��� �ؾ��ϴ� ��찡 �ִٸ� �ش� �޸𸮴� �ݵ��
�� �Լ��� ������ ���� ���� �ؾ��Ѵ�.
ref: https://www.opengl.org/resources/libraries/glut/spec3/node46.html#SECTION00081000000000000000
*/
void Display()
{
	std::cout << "Display() is called." << std::endl;
}



/**
Timer: ������ �ð� �Ŀ� �ڵ����� ȣ��Ǵ� callback �Լ�.
ref: https://www.opengl.org/resources/libraries/glut/spec3/node64.html#SECTION000819000000000000000
*/
void Timer(int value)
{
	std::cout << "Timer() is called." << std::endl;


	// 1000�и�������(1��) �Ŀ� Timer �Լ��� �ٽ� ȣ��Ƿη� �Ѵ�.
	// Timer �Լ� �� ������ �ð� �������� �ݺ� ȣ��ǰ��Ͽ�,
	// �ִϸ��̼� ȿ���� ǥ���� �� �ִ�.
	glutTimerFunc(1000, Timer, 0);
}



/**
Reshape: �������� ũ�Ⱑ ������ ������ �ڵ����� ȣ��Ǵ� callback �Լ�.
 @param w, h�� ���� ������ �������� ���� ũ��� ���� ũ�� (�ȼ� ����).
ref: https://www.opengl.org/resources/libraries/glut/spec3/node48.html#SECTION00083000000000000000
*/
void Reshape(int w, int h)
{
	std::cout << "Reshape() is called. (width=" << w << ", height=" << h << ")" << std::endl;


}






/**
Mouse: ���콺 ��ư�� �Էµ� ������ �ڵ����� ȣ��Ǵ� �Լ�.
 �Ķ������ �ǹ̴� ������ ����.
 @param button: ���� ��ư�� ����
  GLUT_LEFT_BUTTON - ���� ��ư
  GLUT_RIGHT_BUTTON - ������ ��ư
  GLUT_MIDDLE_BUTTON - ��� ��ư (�� ��ư�� �������� ��)
  '3' - ���콺 �� (���� ���� ���� ����).
  '4' - ���콺 �� (���� �Ʒ��� ���� ����).
 @param state: ��ư �׼� ����
  GLUT_DOWN - ���� ����
  GLUT_UP - ���� ����
 @param x,y: �ش� �̺�Ʈ �߻� ��, ���콺 �������� ��ǥ��.
ref: https://www.opengl.org/resources/libraries/glut/spec3/node50.html#SECTION00085000000000000000
*/
void Mouse(int button, int state, int x, int y)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		std::cout << "mouse left button pushed : (" << x << ", " << y << ")" << std::endl;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		std::cout << "mouse left button released : (" << x << ", " << y << ")" << std::endl;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		std::cout << "mouse right button pushed : (" << x << ", " << y << ")" << std::endl;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		std::cout << "mouse right button released : (" << x << ", " << y << ")" << std::endl;
	}
	else if (button == 3)
	{
		std::cout << "mouse wheel up" << std::endl;
	}
	else if (button == 4)
	{
		std::cout << "mouse wheel down" << std::endl;
	}

}





/**
MouseMotion: ���콺 ��ư�� ������ ���¿��� �����Ͱ� ������ �� (�巡���� ��)���� �ڵ����� ȣ��Ǵ� �Լ�.
 @param x�� ���콺 �������� x ��ǥ��
 @param y�� ���콺 �������� y ��ǥ��.
 ref: https://www.opengl.org/resources/libraries/glut/spec3/node51.html#SECTION00086000000000000000
*/
void MouseMotion(int x, int y)
{
	std::cout << "mouse dragged : (" << x << ", " << y << ")" << std::endl;

}



/**
Keyboard: Ű���� �Է��� ���� ������ �ڵ����� ȣ��Ǵ� �Լ�.
 @param key�� ������ Ű������ ���ڰ�.
 @param x,y�� ���� ���콺 �������� ��ǥ��.
ref: https://www.opengl.org/resources/libraries/glut/spec3/node49.html#SECTION00084000000000000000
�� ���������� Ű���� 'r' �� �������� �׸��� ������Ʈ �� ���� ��û�Ѵ�.
*/
void Keyboard(unsigned char key, int x, int y)
{
	std::cout << "key '" << key << "' pushed : (" << x << ", " << y << ")" << std::endl;

	if (key == 'r')
	{
		// glutPostRedisplay�� ������ ���� �ð� �ȿ� ��ü �׸��� �ٽ� �׸� ���� �ý��ۿ� ��û�Ѵ�.
		// ��������� Display() �Լ��� ȣ���ϰ� �ȴ�.
		glutPostRedisplay();
	}
	else if (key == 'q')
	{
		glutLeaveMainLoop();
	}
}




/**
SpeicalKeyboard: ���ڰ��� �ƴ� Ư��Ű�� �Է� �� ������ �ڵ����� ȣ��Ǵ� �Լ�.
 @param key�� ������ Ű���带 ��Ÿ���� ��ũ�� �� (freeglut_std.h ����).
 @param x,y�� ���� ���콺 �������� ��ǥ��.
ref: https://www.opengl.org/resources/libraries/glut/spec3/node54.html#SECTION00089000000000000000
*/
void SpeicalKeyboard(int key, int x, int y)
{
	switch (key)
	{
		std::cout << key << std::endl;
		/* fill here */
	case GLUT_KEY_DOWN:
		std::cout << "down" << std::endl;
		break;

	case GLUT_KEY_UP:
		std::cout << "up" << std::endl;
		break;

	case GLUT_KEY_LEFT:
		std::cout << "left" << std::endl;
		break;

	case GLUT_KEY_RIGHT:
		std::cout << "right" << std::endl;
		break;

	}
}