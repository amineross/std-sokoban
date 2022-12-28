#include "Jeu.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
char ** initTabLab(){
    char **lab;    
    lab = malloc(HAUTEUR_LAB*sizeof(char*));

    if (lab == NULL){
        printf("Erreur d'initialisation de TabLab\n");
        return NULL;
    }

    for(int i=0; i<HAUTEUR_LAB; i++){

        lab[i] = malloc(LARGEUR_LAB*sizeof(char));
        
        if(lab[i] == NULL){
            printf("Erreur d'initialisation des colonnes de TabLab\n");
            return NULL;
        }
    }
    
    printf("Succes LAB!\n"); 
    return lab;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void recupLab(char * nom_fichier, char **lab){

    FILE *fc = fopen(nom_fichier, "r");
    if(fc == NULL){
        printf("Erreur d'ouverture du fichier labyrinthe\n");
        return;
    }

    char c = fgetc(fc);
    int i=0, j=0;
    
    while (c != EOF)
    {
        if(i < HAUTEUR_LAB){
		lab[i][j] = c;
        	j++;

        	if(c == '\n'){
            		i++;
            		j=0;
        	}
    	}

       	c = fgetc(fc);
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void afficheLab(char **lab, Element * p, Element * cibles, int nbCibles, int level)
{

    if(lab == NULL){
        printf("Le labyrinthe n'est pas cree.\n");
        return;
    }

    char * wall = "☐";
    char * box = "☲";
    char * valid = "☑";
    char * invalid = "☒";
    char * playerChar = "☃";

    int y_offset = 0; // x,y bug fix > level 4
    // if (level > 4)
    // {
    //     y_offset = 1;
    // }

    for(int k = 0; k<nbCibles; k++)
    {
        if (lab[cibles[k].y + y_offset][cibles[k].x] == ' ')
        {
            lab[cibles[k].y + y_offset][cibles[k].x] = 'I';
        } else if (lab[cibles[k].y + y_offset][cibles[k].x] == 'B')
        {
            lab[cibles[k].y + y_offset][cibles[k].x] = 'V';
        }
    }

    for(int i=0; i<HAUTEUR_LAB; i++)
    {
        for(int j=0; j<LARGEUR_LAB; j++)
        {
            // for (int k = 0; k<nbCibles; k++)
            // {
            //     if (i == cibles[k].x && j == cibles[k].y && lab[i][j] == 'I')
            //     {
            //         printf("%s", invalid);
            //     }
            // }
            if (lab[i][j] == '#')
            {
                printf("%s ", box);
            }
            else if (lab[i][j] == 'V')
            {
                printf("%s ", valid);
            } 
            else if (lab[i][j] == 'I')
            {
                printf("%s ", invalid);
            } 
            else if (lab[i][j] == 'B')
            {
                printf("%s ", wall);
            } else if (lab[i][j] == '\n')
            {
                printf("\n");
            } else if (lab[i][j] == 'P')
            {
                p->x = i;
                p->y = j;
                printf("%s ", playerChar);
            } else
            {
                printf("%c ", lab[i][j]);
            }
        }
    }
       
    printf("PLAYER (%d, %d)\n", p->x, p->y);
    printf("Cliquez sur la touche U pour sortir\n");
    printf("Cliquez sur la touche R pour recommencer\n");
    //DEBUG
    // for (int i = 0; i<HAUTEUR_LAB; i++)
    // {
    //     for (int j = 0; j<LARGEUR_LAB; j++)
    //     {
    //         if (lab[i][j] == '\n')
    //         {
    //             printf("\n");
    //         } else
    //         {
    //             printf("%c ", lab[i][j]);
    //         }
    //     }
    // }

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int nbCible(char **lab){		//compte le nombre de cibles dans le labyrinthe
	int nb = 0;
	if(lab == NULL){
		printf("Le labyrinthe est introuvable, donc cibles introuvables\n");
		return -1;
	}

	for(int i=0; i<HAUTEUR_LAB; i++){
		for(int j=0; j<LARGEUR_LAB; j++){

			if(lab[i][j] == 'I')
				
				nb++;
		}
	}

	return nb;
}

int nbValide(char **lab){		//compte le nombre de cibles validees dans le labyrinthe
	int nb = 0;
	if(lab == NULL){
		printf("Le labyrinthe est introuvable, donc cibles introuvables\n");
		return -1;
	}

	for(int i=0; i<HAUTEUR_LAB; i++){
		for(int j=0; j<LARGEUR_LAB; j++){

			if(lab[i][j] == 'V')
				
				nb++;
		}
	}

	return nb;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Element *recupPosCible(char **lab)
{
	if(lab == NULL)
    {
		printf("Le labyrinthe est introuvable\n");
		return NULL;
	}

	int nb_cible = nbCible(lab) + nbValide(lab);
    
	Element *tab = malloc(nb_cible *sizeof(Element));	//tableau qui contiendra les cibles et leurs positions
	
	int cpt = 0;						//indice des cibles dans le tableau						

	for(int i=0; i<HAUTEUR_LAB; i++)			//on ne prend pas en compte les indices des murs
    {
		for(int j=0; j<LARGEUR_LAB; j++)
        {
			if((lab[i][j] == 'I') || (lab[i][j] == 'V'))
            {
			
				tab[cpt].x = j;		
				tab[cpt].y = i;		
				cpt ++;
			}
		
		}

	}

	return tab;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void afficheCibles(Element* tab, int n)//char ** lab)
{
    // Element * tab = recupPosCible(lab);
    // int n = nbCible(lab);
    // printf("\nCIBLES: ");
    for (int i = 0; i<n; i++)
    {
        printf("(%d, %d)  ", tab[i].x, tab[i].y);
    }
}