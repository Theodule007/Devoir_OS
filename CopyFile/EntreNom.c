#include <stdio.h>
#include <stdlib.h>

char *EntrerNom()
{
     char chaine[255];

    //printf("saisir votre nom de fichier ");

    if (scanf("%254s", chaine) != 1)
    {
        printf("Erreur lors de la saisie\n");
        return EXIT_FAILURE;
    }


    return chaine;


}
