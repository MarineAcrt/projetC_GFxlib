

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Structures~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct 
{
    int score; 
    int compteur; 
    int ** matrice_brique;

}SAVE;


// ===========PROTOTYPES DES FONCTIONS===========


//design du jeu
void afficheDesign(void); 

//SCORE
void afficheScore(int ** matrice_brique, SAVE* save); 
int calculScore(int ** matrice_brique, SAVE* save);
void compteurVie(int compteur);


//sauvegarde et charge de la partie
void SauvegardePartie(SAVE* save);
void ChargerPartie(SAVE* save);

// AFFICHAGE
void creationBrique(int ** matrice_brique); 
void afficheBrique(int ** matrice_brique); 
void afficheBarre(int xBarre, int yBarre, int xBalle, int yBalle); 

void partieWin(int score, int compteur); 
void rebondBrique1(int ** matrice_brique, int * vxBalle, int * vyBalle, int * xBalle, int * yBalle); 
void rebondBrique2(int ** matrice_brique, int * vxBalle2, int * vyBalle2, int * xBalle2, int * yBalle2); 

void rebondBarre1(int * vxBalle, int * vyBalle, int * xBalle, int * yBalle, int xBarre, int yBarre); 
void rebondBarre2(int * vxBalle2, int * vyBalle2, int * xBalle2, int * yBalle2, int xBarre, int yBarre); 




//menu du jeu
void menu(void);
//niveau du jeu
void initJeuFacile (int ** matrice_brique);
void initJeuMoyen (int ** matrice_brique);
void initJeuDifficile (int ** matrice_brique);

