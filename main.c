#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char** argv )
{
    int nombreMystere = 0, nombreEntree = 0, continuerPartie = 1, compteur = 0, MAX = 0, niveaux = 0, joueur = 0;
    const int MIN = 1;

        printf("== BIENVENUE DANS LE JEU DU NOMBRE MYSTERE ! ==\n\n"); // intro + selection du mode
        printf("1. Solo ou 2. Duo\n\n");
        scanf("%d", &joueur);

 while (continuerPartie) // boucle pour relancer
    {
        printf("Choisis la difficulte :\n"); // selection du level
        printf("1. 1 a 100\n");
        printf("2. 1 a 1000\n");
        printf("3. 1 a 10000\n");
        scanf("%d", &niveaux);

        if (niveaux == 1)   // conditions pour fixer le max du level
        {
            MAX = 100;
        }
        if (niveaux == 2)
        {
            MAX = 1000;
        }
        if (niveaux == 3)
        {
            MAX = 10000;
        }

        if (joueur == 1) // cas joueur 1
        {
    srand(time(NULL));  // generation random d'un nombre
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        if (joueur == 2) // cas joueur 2
        {
            printf("Joueur 1 entrez le nombre mystere entre 1 et %d a faire deviner\n\n", MAX);
            scanf("%d", &nombreMystere);
            system("cls"); // cache le nombre mystere
        }
        if (nombreMystere >= MAX) // le cas du petit filou
        {
            printf("Eh ! Toi ! Faut que ton ami puisse trouver quand meme !\n\nSois gentil et rentre un chiffre entre 1 et %d\n\n", MAX);
            scanf("%d", &nombreMystere);
            system("cls");
        }
    printf("Trouvez le nombre mystere entre 1 et %d\n", MAX);


   while(nombreEntree != nombreMystere)
   {
       compteur++; // incrementation
       printf("Entrez votre chiffre\n");
       scanf("%d", &nombreEntree);
       if(nombreEntree < nombreMystere) // interaction suivant le resultat donne
       {
            printf("Non ! C'est plus !\n\n");
       }
       if (nombreEntree > nombreMystere)
       {
           printf("Non ! C'est moins !\n\n");
       }
       if (nombreEntree == nombreMystere)
       {
           printf("Bien joue !!\nVous avez trouve le nombre mystere en %d coup !\n\n", compteur);
       }

   }

    printf("Voulez vous relancer une partie ?\n1 : oui\n0 : non\n\n");
    scanf("%d", &continuerPartie);
    compteur = 0 ; // remise a 0 du compteur
}

return 0;

}
