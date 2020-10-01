#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
char NameSource[255];
char NameDestination[255];

printf("Entrer le nom du fichier a copier\n");

scanf("%254s", NameSource);

//printf("Nom du fichier est  %s !\n", NameSource);


printf("Entrer le nom du fichier destination\n");

scanf("%254s", NameDestination);

//printf("Nom du fichier est  %s !\n", NameSource);

BOOL bfile;
bfile = CopyFile(NameSource, NameDestination, TRUE);

if(bfile==FALSE)
{
    printf("Copie echouee\n");
    printf("%lu",GetLastError());


     if(GetLastError()==80)
        {
           printf("Le fichier destination existe deja\n");
        }
     else if(GetLastError()==2)
         {
             printf("Le fichier source n'existe pas\n");
         }
    else if(GetLastError()==5)
        {
            printf("Vous n'avez pas acces pour faire cette operation\n");
        }
    else
        {
            printf("Erreur!!!");
        }



}
else{
    printf("La copie a ete effectuee\n");
}





    return 0;
}




