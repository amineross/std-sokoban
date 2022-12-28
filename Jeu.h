#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"

#ifndef JEU_H
#define JEU_H
#define NOM_FICHIER 15
#define LARGEUR_LAB 8+1		/*prise en compte du saut à la ligne*/ //11x10
#define HAUTEUR_LAB 9

void recupLab(char * fichier, char **lab);
char **initTabLab();
void afficheLab(char **lab, Element * p, Element * cibles, int nbCibles, int level);
int nbCible(char **lab);
int nbValide(char **lab);
Element *recupPosCible(char **lab);
void afficheCibles(Element * tab, int n);//char ** lab);

#endif
