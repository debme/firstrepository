#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
  glClearColor(0.0,0.0,0.0,0.0);	
  glShadeModel(GL_FLAT);	
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 1.0);
  // Resetear transformaciones
  glLoadIdentity();
  gluLookAt(1.0, 2.0, 3.0, //eye
	    0.0, 0.0, 0.0, //at
	    0.0, 1.0, 0.0); //up
  glScalef(1.0, 1.0, 1.0);
  glRotatef(60, 0.1, 0.1, 0.0);
  //glutWireTetrahedron();
  //glutWireOctahedron();
  //glutWireIcosahedron();
  //glutWireSphere(0.8,10,10);
  glFlush();
}

void menu (int valor)
{
  switch (valor)
    {
    case 1:
      {
	glutWireTorus(0.5, 1.0, 20, 20);
	break;
      }
    case 2:
    {
      glutWireTeapot(1);
      break;
    }
    case 3:
      {
	glutWireIcosahedron();
	break;
      }
    case 4:
    {
      glutWireCone(1.0, 1.0, 10, 10);
      break;
    }
    case 5:
    {
      glutWireOctahedron();
      break;
    }
    case 6:
      {
	glutWireTetrahedron();
	break;
      }
    case 7:
      exit(0);
    }
}

void menu_opciones (void)
{
  glutCreateMenu(menu);
  glutAddMenuEntry("Torus",1);
  glutAddMenuEntry("Tetera",2);
  glutAddMenuEntry("Cono",4);
  glutAddMenuEntry("Isosaedro",3);
  glutAddMenuEntry("Octahedro",5);
  glutAddMenuEntry("Tetrahedro",6);
  glutAddMenuEntry("Salir",7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  menu_opciones();
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
  //  Inicializar los parámetros GLUT y de usuario proceso
  glutInit(&argc,argv);
  // Solicitar ventana con color real y doble buffer con Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100,100);
  // Crear ventana
  glutCreateWindow("Cubo controlado por teclas");
  init ();
  // Funciones de retrollamada
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  // Pasar el control de eventos a GLUT
  glutMainLoop();
  // Regresar al sistema operativo
  return 0;
}
