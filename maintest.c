#include <stdio.h>
#include <stdlib.h>


int sauvegardePartie(Partie* partie, char* nomsauvegarde); 
int chargePartie(Partie* partie, char* nomsauvegarde);

int main(void)
{
	char nom[20]; 
	int i; 
	printf("quel est le nom de ta partie ?\n"); 
	scanf("%s", &nom); 
	sauvegardePartie(partie, nomsauvegarde);
	printf("Voulez-vous charger la partie ?\n"); 
	scanf("%d", &i);
	if(i==1)
		chargePartie(partie, nomsauvegarde);
	return 0;
}
