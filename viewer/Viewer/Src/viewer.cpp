#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"
#include "touches.h"

//#include "pluie_gammatons.hpp"
#include "Obj/OBJReader.hpp"
#include <iostream>

/* dimensions initiales de la fenêtre d'affichage */
#define LARGEUR  512
#define HAUTEUR  512

float angle_rotY = 0.0;
float angle_rotX = 0.0;
float trans_axeZ = -10.0;
//OBJReader r("./Scenes", "cube1.obj");

OBJReader r("./Scenes", "cube1.obj");
/**
 * Fonction d'initialisation des paramètres d'affichage
 */
static void init_screen(void)
{
  srand(time(NULL));
  /* initialiser la position de la camera */
  /* en deplacant l'origine du repere et  */
  /* non pas la camera */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, trans_axeZ);
  glRotatef(angle_rotX, 1.0, 0.0, 0.0);
  glRotatef(angle_rotY, 0.0, 1.0, 0.0);

  /* definir le matrice de projection */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 1.0, 100.0);

  /* definir le viewport */
  glViewport(0, 0, 255, 50);
  /* attention : annule par l'appel implicite de la fonction */
     /* de reshape, qu'elle existe ou pas .... */

  glutPostRedisplay();
}


/**
 * Fonction principale qui crée et initialise la fenêtre
 * d'affichage et lance la boucle d'affichage Glut.
 * @param argc le nombre d'argument sur la ligne de commande
 * @param argv une table de chaîne de caractères contenant chacun
 * des arguments de la ligne de commande.
 */
int main (int argc, char *argv[])
{

  std::cout << argv[0] << std::endl;
  glutInit (&argc, argv);

  glutInitWindowPosition(100, 100); 
  glutInitWindowSize(LARGEUR, HAUTEUR); 

  glutInitDisplayMode(GLUT_DEPTH);

  glutCreateWindow(argv[0]);

  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);
  /* choix de la fonction des gestion des touches */
  glutKeyboardFunc(gerer_clavier);

  
  

  //-----------------
  
  init_screen();
  
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  

  return 0;
}


