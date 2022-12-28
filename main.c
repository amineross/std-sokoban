#include <stdio.h>
#include <stdlib.h>
#include <time.h> // TIME SUPPORT

#include "Jeu.h"
#include "Element.h"
#include "MainMenu.c"


int main(void){
    int numLevel = mainMenu();

    char **lab;

    char nomfichier[18] = "levels/Levelx.txt";
    
    // printf("Quel niveau? (ex. Level1.txt): ");
    // scanf("%i", &numLevel);
    nomfichier[12] = numLevel + '0';
    lab = initTabLab();


    
    Element p;
    

    recupLab(nomfichier, lab);
    Element * cibles = recupPosCible(lab);
    int nbCibles = nbCible(lab);
    int nbVal = nbValide(lab);
    int nbTot = nbVal + nbCibles;

    //TIMER SETUP
    time_t start = time(NULL);
    

    system ("clear");
    afficheLab(lab, &p, cibles, nbTot, numLevel);
    int c;
	system ("/bin/stty raw");
	while ((c=getchar()) != 'u')
	{
        // Reload
        if (c == 'r')
        {
            recupLab(nomfichier, lab);
            cibles = recupPosCible(lab);
            nbCibles = nbCible(lab);
            nbVal = nbValide(lab);
            nbTot = nbVal + nbCibles;
        }

        //input
        if (c == 'd' && p.y < LARGEUR_LAB - 3) //&& lab[p.x][p.y+1] != '#')
        {
            if (lab[p.x][p.y + 1] == 'B' && lab[p.x][p.y + 2] != '#')
            {
                char temp;
                temp = lab[p.x][p.y+1];
                lab[p.x][p.y+2] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1; // Move player ->
            } 
            else if (lab[p.x][p.y + 1] == 'V' && lab[p.x][p.y + 2] != '#')
            {
                char temp;
                
                lab[p.x][p.y+2] = 'B'; // Move V and turn into box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1; // Move player ->
            } 
            else if (lab[p.x][p.y + 1] == ' ' || lab[p.x][p.y + 1] == 'I')
            {
                char temp;
                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1;
            }
        }

        if (c == 'q' && p.y > 1) //&& lab[p.x][p.y-1] != '#')
        {
            if (lab[p.x][p.y - 1] == 'B' && lab[p.x][p.y - 2] != '#')
            {
                char temp;
                temp = lab[p.x][p.y-1];
                lab[p.x][p.y-2] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1; // Move player ->
                
            }
            else if (lab[p.x][p.y - 1] == 'V' && lab[p.x][p.y - 2] != '#')
            {
                char temp;
                
                lab[p.x][p.y-2] = 'B'; // Move V and turn into box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1; // Move player ->
            } 
            else if (lab[p.x][p.y - 1] == ' ' || lab[p.x][p.y - 1] == 'I')
            {
                char temp;
                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1;
            }
        }

        if (c == 'z' && p.x > 1) //&& lab[p.x-1][p.y] != '#')
        {
            if (lab[p.x - 1][p.y] == 'B' && lab[p.x - 2][p.y] != '#')
            {
                char temp;
                temp = lab[p.x - 1][p.y];
                lab[p.x - 2][p.y] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x - 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1; // Move player ->
                
            } 
            else if (lab[p.x-1][p.y] == 'V' && lab[p.x-2][p.y] != '#')
            {
                char temp;
                
                lab[p.x-2][p.y] = 'B'; // Move V and turn into box ->

                temp = lab[p.x][p.y];
                lab[p.x-1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1; // Move player ->
            } 
            else if (lab[p.x - 1][p.y] == ' ' || lab[p.x-1][p.y] == 'I')
            {
                char temp;
                temp = lab[p.x][p.y];
                lab[p.x - 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1;
            }
        }

        if (c == 's' && p.x < HAUTEUR_LAB - 2) //&& lab[p.x+1][p.y] != '#')
        {
            if (lab[p.x + 1][p.y] == 'B' && lab[p.x + 2][p.y] != '#')
            {
                char temp;
                temp = lab[p.x + 1][p.y];
                lab[p.x + 2][p.y] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x + 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1; // Move player ->
                
            }
            else if (lab[p.x+1][p.y] == 'V' && lab[p.x+2][p.y] != '#')
            {
                char temp;
                
                lab[p.x+2][p.y] = 'B'; // Move V and turn into box ->

                temp = lab[p.x][p.y];
                lab[p.x+1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1; // Move player ->
            }  
            else if (lab[p.x + 1][p.y] == ' ' || lab[p.x+1][p.y] == 'I')
            {
                char temp;
                temp = lab[p.x][p.y];
                lab[p.x + 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1;
            }
        }

        system ("/bin/stty cooked");
        system ("clear");
        afficheLab(lab, &p, cibles, nbTot, numLevel);
        // afficheCibles(cibles, nbTot);
        nbVal = nbValide(lab);
        if (nbTot == nbVal)
        {
            printf("Gagné !\n");
            exit(0);
        }
        // else 
        // {
        //     printf("\nNombre de Cibles Validees: %d\n", nbVal);
        // }
        /* TIMER */
        time_t end = time(NULL);
        double elapsed = difftime(end, start);
        printf("TIMER: %.fs\n",elapsed);
        

        system ("/bin/stty raw");
	}
    system ("clear");
	system ("/bin/stty cooked");


    return 0;
}
