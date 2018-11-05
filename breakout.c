#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 600
#define HauteurFenetre 1000


//Structures

typedef struct{

    int R;
    int G;
    int B;
    int resistance;
    int x;
    int y;

}Brique;


typedef struct{

    int R;
    int G;
    int B;
    int longueur;
    int x;
    int vitesse;
    int posG; 
    int posC; 
    int posD; 
    
}Barre;

// --------------------------------------------- //

/*typedef struct bouton
{
    char nom[30]; 
    int X0; 
    int Y0; 
    int X1; 
    int Y1; 
} BOUTON; */

// Fonction de déplacement de la barre
void deplacerBarre(Barre *posC, Barre *posD, Barre *posG, EvenementGfx codeTouche); 
// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);
//BOUTON*initbouton(char*texte, int X0, int X1, int Y0, int Y1);

int main(int argc, char **argv)
{
    Barre*B=NULL; 
    initialiseGfx(argc, argv);
//        char texte[30]="appuie ici"; 
    deplacerBarre(posC, posD, posG, codeTouche);
    prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
    lanceBoucleEvenements();
//        BOUTON*b=initbouton(texte, 750, 800, 0, 600);
    
    return 0;
}


/*BOUTON*initbouton(char*texte, int X0, int X1, int Y0, int Y1)
{
    BOUTON*b=NULL; 
    b=(BOUTON*)malloc(sizeof(BOUTON)); 
    if(b==NULL)
    {
            printf("erreur\n"); 
            exit (-1); 
    }
    b->nom=texte; 
    b->X0=X0; 
    b->Y0=Y0; 
    b->X1=X1; 
    b->Y1=Y1; 
    return b; 
}
*/

/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
    const int Pas = 20; // Nombre de secteurs pour tracer le cercle
    const double PasAngulaire = 2.*M_PI/Pas;
    int index;
    
    for (index = 0; index < Pas; ++index) // Pour chaque secteur
    {
            const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
            triangle(centreX, centreY,
                             centreX+rayon*cos(angle), centreY+rayon*sin(angle),
                             centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
                    // On trace le secteur a l'aide d'un triangle => approximation d'un cercle
    }
    
}

void deplacerBarre(Barre *posC, Barre *posD, Barre *posG, EvenementGfx codeTouche)
{   switch(codeTouche)
    {
        case ToucheFlecheDroite: /* barre vers la droite */
            if (posD->x++ < 12) /* afin d'être bloqué par le mur */
            {
                posC->x++;
                posG->x = posC->x--;
                posD->x = posC->x++;
                break;
            }
            else
            {
                break;
            }
        case ToucheFlecheGauche: /* barre vers la gauche */
            if (posG->x-- > 2) /* afin d'être bloqué par le mur */
            {
                posC->x--;
                posG->x = posC->x--;
                posD->x = posC->x++;
                break;
            }
            else
            {
                break;
            }

        } 
    }

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
    static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
    static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran

    /* On va aussi animer une balle traversant l'ecran */
    static int xBalle;
    static int yBalle;

    static int vxBalle = 7;
    static int vyBalle = -7;

    static int posD; 
    static int posG; 
    static int posC; 



   
    
    switch (evenement)
    {
            case Initialisation:
                    xBalle = largeurFenetre()*valeurAleatoire();
                    yBalle = hauteurFenetre()*valeurAleatoire();
                   // image = lisBMPRGB("bebe.bmp");
                    /* Le message "Initialisation" est envoye une seule fois, au debut du
                    programme : il permet de fixer "image" a la valeur qu'il devra conserver
                    jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
                    pas pu etre lue, soit "image" pointera sur une structure contenant
                    les caracteristiques de l'image "imageNB.bmp" */

                    // Configure le systeme pour generer un message Temporisation
                    // toutes les 20 millisecondes
                    demandeTemporisation(20);
                    break;
            
            case Temporisation:
                    // On met a jour les coordonnees de la balle
                    xBalle += vxBalle;
                    yBalle += vyBalle;

                    // On fait rebondir la balle si necessaire
                    if (xBalle < 0 || xBalle >= largeurFenetre())
                            vxBalle = -vxBalle;
                    if (yBalle < 0 || yBalle >= hauteurFenetre())
                            vyBalle = -vyBalle;
                    // Les coordonnees de la balle ayant eventuellement change,
                    // il faut redessiner la fenetre :
                    rafraichisFenetre();
                    break;
                    
            case Affichage:
                    
                    // On part d'un fond d'ecran blanc
                    effaceFenetre (0, 0, 0);
                    int compteur=0; 
                    //Affiche Barre
                    couleurCourante(255, 0, 255);
                    rectangle((largeurFenetre()-600)/10, (hauteurFenetre()-400)/40, (largeurFenetre()-600)/10+100, (hauteurFenetre()-400)/40+10);



                    // Affichage d'une image
                    if (image != NULL) // Si l'image a pu etre lue
                    {
                            // On affiche l'image
                            ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
                    }

                                            
                    // Affichage d'une balle noire
                    couleurCourante(255, 255, 255);
                    cercle(xBalle, yBalle, 5);

                    //deplacerBarre(posC, posD, posG, codeTouche);
                    break;


                


            case Clavier:
                    printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

                    switch (caractereClavier())
                    { 
                            case 'Q': /* Pour sortir quelque peu proprement du programme */
                            case 'q':
                                    libereDonneesImageRGB(&image); /* On libere la structure image,
                                    c'est plus propre, meme si on va sortir du programme juste apres */
                                    termineBoucleEvenements();
                                    break;

                            case 'F':
                            case 'f':
                                    pleinEcran = !pleinEcran; // Changement de mode plein ecran
                                    if (pleinEcran)
                                            modePleinEcran();
                                    else
                                            redimensionneFenetre(LargeurFenetre, HauteurFenetre);
                                    break;

                            case 'R':
                            case 'r':
                                    // Configure le systeme pour generer un message Temporisation
                                    // toutes les 20 millisecondes (rapide)
                                    demandeTemporisation(20);
                                    break;

                            case 'L':
                            case 'l':
                                    // Configure le systeme pour generer un message Temporisation
                                    // toutes les 100 millisecondes (lent)
                                    demandeTemporisation(100);
                                    break;

                            case 'S':
                            case 's':
                                    // Configure le systeme pour ne plus generer de message Temporisation
                                    demandeTemporisation(-1);
                                    break;
                            case 'J':
                            case 'j': 
                                Barre.posG+=30;
                                Barre.posD+=30;
                                break;     
                            case 'L':
                            case 'l':
                                Barre.posG+=30; 
                                Barre.posD+=30;


                    }
                    break;
                    
            case ClavierSpecial:
                    printf("ASCII %d\n", toucheClavier());
                    break;
            

          /*  case BoutonSouris:
                    if (etatBoutonSouris() == GaucheAppuye)
                    {
                            printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
                            // Si le bouton gauche de la souris est appuye, faire repartir
                            // la balle de la souris
                            xBalle = abscisseSouris();
                            yBalle = ordonneeSouris();
                    }
                    else if (etatBoutonSouris() == GaucheRelache)
                    {
                            printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
                    }
                    break;*/
            
            case Souris: // Si la souris est deplacee
                    break;
            
            case Inactivite: // Quand aucun message n'est disponible
                    break;
            
            case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
                    // Donc le systeme nous en informe
                    if (xBalle >= largeurFenetre())
                            xBalle = largeurFenetre()-1;
                    if (yBalle >= hauteurFenetre())
                            yBalle = hauteurFenetre()-1;
                    printf("Largeur : %d\t", largeurFenetre());
                    printf("Hauteur : %d\n", hauteurFenetre());
                    break;
    }
}


/*
Structure de briques prenant en compte l'écart entre chaque brique 
Structure brique prenant en compte les coordonnées d'une brique ainsi que sa résistance.
*/
