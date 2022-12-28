#include <stdio.h>

// Definition couleurs UNIX
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int mainMenu()
{
    system ("clear");
    int c;
    int numLev = 1;
	
    printf(RED "PROJECT SOKOBAN 2022\n"     RESET);
    printf("Level           ☚ %d ☛\n", numLev);
    printf(GRN "Utilisez Q et D pour choisir le numero de niveau :)\n"   RESET);
    printf(GRN "Cliquez sur V pour commencer :)\n"   RESET);

    system ("/bin/stty raw");
	while ((c=getchar()) != 'v')
    {
        system ("clear");

        if (c == 'd' && numLev < 10)
        {
            numLev += 1;
        }

        if (c == 'q' && numLev > 0)
        {
            numLev -= 1;
        }

        system ("/bin/stty cooked");
        printf(RED "PROJECT SOKOBAN 2022\n"     RESET);
        printf("Level           ☚ %d ☛\n", numLev);
        printf(GRN "Utilisez Q et D pour choisir le numero de niveau :)\n"   RESET);
        printf(GRN "Cliquez sur V pour commencer :)\n"   RESET);
        system ("/bin/stty raw");
        
    }
	system ("/bin/stty cooked");

    return numLev;
}