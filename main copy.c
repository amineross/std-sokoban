#include <stdio.h>
#include <stdlib.h>
#include "Jeu.h"
#include "Element.h"



int main(void){
    char **lab;
    char * nomfichier = "Level2.txt";
    
    lab = initTabLab();

    Element p;
    Element * cibles = recupPosCible(lab);

    recupLab(nomfichier, lab);

    system ("clear");
    afficheLab(lab, &p);
    int c;
	system ("/bin/stty raw");
    int flag = 0;
	while ((c=getchar()) != 'u')
	{
        //input
        if (c == 'd' && p.y < LARGEUR_LAB - 3) //&& lab[p.x][p.y+1] != '#')
        {
            if (lab[p.x][p.y + 1] == 'B' && lab[p.x][p.y + 2] == ' ')
            {
                char temp;
                temp = lab[p.x][p.y+1];
                lab[p.x][p.y+2] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1; // Move player ->

                if (flag != 0)
                {
                    lab[p.x][p.y-1] = 'I';
                    flag = 0;
                }

            } else if (lab[p.x][p.y + 1] == 'B' && lab[p.x][p.y + 2] == 'I')
            {
                char temp;

                lab[p.x][p.y+2] = 'V'; // Move box -> transform to V

                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1; // Move player ->
            } else if (lab[p.x][p.y + 1] == 'V' && lab[p.x][p.y + 2] == ' ')
            {
                char temp;

                lab[p.x][p.y+2] = 'B'; // Move box -> transform to B
                flag = 1; 

                temp = lab[p.x][p.y];
                lab[p.x][p.y+1] = temp;
                lab[p.x][p.y] = ' ';
                p.y += 1; // Move player ->
            } else if (lab[p.x][p.y + 1] == ' ')
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
            if (lab[p.x][p.y - 1] == 'B' && lab[p.x][p.y - 2] == ' ')
            {
                char temp;
                temp = lab[p.x][p.y-1];
                lab[p.x][p.y-2] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1; // Move player ->

                if (flag != 0)
                {
                    lab[p.x][p.y+1] = 'I';
                    flag = 0;
                }
                
            } 
            else if (lab[p.x][p.y - 1] == 'B' && lab[p.x][p.y - 2] == 'I')
            {
                char temp;

                lab[p.x][p.y-2] = 'V'; // Move box -> transform to V

                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1; // Move player ->
            }
            else if (lab[p.x][p.y - 1] == 'V' && lab[p.x][p.y - 2] == ' ')
            {
                char temp;

                lab[p.x][p.y-2] = 'B'; // Move box -> transform to B
                flag = 1; 

                temp = lab[p.x][p.y];
                lab[p.x][p.y-1] = temp;
                lab[p.x][p.y] = ' ';
                p.y -= 1; // Move player ->
            }
            else if (lab[p.x][p.y - 1] == ' ')
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
            if (lab[p.x - 1][p.y] == 'B' && lab[p.x - 2][p.y] == ' ')
            {
                char temp;
                temp = lab[p.x - 1][p.y];
                lab[p.x - 2][p.y] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x - 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1; // Move player ->

                if (flag != 0)
                {
                    lab[p.x+1][p.y] = 'I';
                    flag = 0;
                }
                
            }
            else if (lab[p.x-1][p.y] == 'B' && lab[p.x-2][p.y] == 'I')
            {
                char temp;

                lab[p.x-2][p.y] = 'V'; // Move box -> transform to V

                temp = lab[p.x][p.y];
                lab[p.x-1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1; // Move player ->
            }
            else if (lab[p.x-1][p.y] == 'V' && lab[p.x-2][p.y] == ' ')
            {
                char temp;

                lab[p.x-2][p.y] = 'B'; // Move box -> transform to B
                flag = 1; 

                temp = lab[p.x][p.y];
                lab[p.x-1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x -= 1; // Move player ->
            } 
            else if (lab[p.x - 1][p.y] == ' ')
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
            if (lab[p.x + 1][p.y] == 'B' && lab[p.x + 2][p.y] == ' ')
            {
                char temp;
                temp = lab[p.x + 1][p.y];
                lab[p.x + 2][p.y] = temp; // Move box ->

                temp = lab[p.x][p.y];
                lab[p.x + 1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1; // Move player ->

                if (flag != 0)
                {
                    lab[p.x-1][p.y] = 'I';
                    flag = 0;
                }
                
            }
            else if (lab[p.x+1][p.y] == 'B' && lab[p.x+2][p.y] == 'I')
            {
                char temp;

                lab[p.x+2][p.y] = 'V'; // Move box -> transform to V

                temp = lab[p.x][p.y];
                lab[p.x+1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1; // Move player ->
            }
            else if (lab[p.x+1][p.y] == 'V' && lab[p.x+2][p.y] == ' ')
            {
                char temp;

                lab[p.x+2][p.y] = 'B'; // Move box -> transform to B
                flag = 1; 

                temp = lab[p.x][p.y];
                lab[p.x+1][p.y] = temp;
                lab[p.x][p.y] = ' ';
                p.x += 1; // Move player ->
            }  
            else if (lab[p.x + 1][p.y] == ' ')
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
        afficheLab(lab, &p);
        afficheCibles(lab);
        printf("\nFLAG: %d\n", flag);
        system ("/bin/stty raw");
	}
	system ("/bin/stty cooked");


    return 0;
}
