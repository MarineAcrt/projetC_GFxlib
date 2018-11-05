
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include <time.h> //pour utiliser le temps 
#include "fonctions.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 600
#define HauteurFenetre 1000

static const char nomFichierSauvegarde[] = "Sauvegarde";
/*
static int vxBalle, vyBalle, vxBalle2, vyBalle2; 
static int xBalle, yBalle, xBalle2, yBalle2; 
static int xBarre, yBarre;
*/



// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
        initialiseGfx(argc, argv);
        prepareFenetreGraphique("Breakout", LargeurFenetre, HauteurFenetre);
        /* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
                qui elle-meme utilise fonctionAffichage ci-dessous */
        lanceBoucleEvenements();
        return 0;
}






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


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
        static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
        static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
        /* On va aussi animer une balle traversant l'ecran */

        //balle 1
        static int xBalle;
        static int yBalle;
        static int vxBalle = 7;
        static int vyBalle = -7;

        //balle 2
        static int xBalle2; 
        static int yBalle2; 
        static int vxBalle2 = 7; 
        static int vyBalle2 = -7; 

        //barre
        static int xBarre;
        static int yBarre;
 
        static int compteur = 3;
        static int pause = 1, appuyeJ = 0, appuyeN = 0, niveau2=0; 

        //images
        static DonneesImageRGB * imageFond = NULL;

        //sauvegarde
        static SAVE* save=NULL;

      
        switch (evenement)
        {
                case Initialisation:

                        //Initialisation Balle 1
                        xBalle = largeurFenetre()/2;
                        yBalle = hauteurFenetre()/8.5;
                        vxBalle=0; 
                        vyBalle=0;
                        
                        if (niveau2)
                        {
                            //initialisation Balle 2
                            xBalle2 = largeurFenetre()/2;
                            yBalle2 = hauteurFenetre()/8.5;
                            vyBalle2=0; 
                            vxBalle2=0; 
                        }

                        //initialisation Barre
                        xBarre = largeurFenetre()/2;
                        yBarre = hauteurFenetre()/10;


                        //initialisation matrice
                        static int ** matrice_brique = NULL; 
                        save = (SAVE*) malloc(sizeof(SAVE));
                        /*if( save==NULL )
                        {  
                            printf("ERROR\n"); 
                            exit(-1); 
                        }*/



                        //source image
                        imageFond = lisBMPRGB("etoile.bmp");

                        activeGestionDeplacementPassifSouris(); 

                        //creation matrice brique
                        matrice_brique = calloc (12,sizeof(int*));
                        creationBrique(matrice_brique); 


                        // Configure le systeme pour generer un message Temporisation
                        // toutes les 20 millisecondes
                        demandeTemporisation(20);

                        break;
                
                case Temporisation:

                        // On met a jour les coordonnees de la balle
                        xBalle += vxBalle;
                        yBalle += vyBalle;

                        if (niveau2)
                        {
                            xBalle2 += vxBalle2; 
                            yBalle2 += vyBalle2; 
                        }
                        
       
                        // On fait rebondir la balle 1 sur les bords de la fenetre
                        if (xBalle <= (largeurFenetre()/30)+10 || xBalle >= (largeurFenetre()-largeurFenetre()/30)-10)
                            vxBalle = -vxBalle;
                        if (yBalle >= (hauteurFenetre()/10*8)-10)
                            vyBalle = -vyBalle;


                        // On fait rebondir la balle 2 sur les bords de la fenetre
                        if (xBalle2 <= (largeurFenetre()/30)+10 || xBalle2 >= (largeurFenetre()-largeurFenetre()/30)-10)
                            vxBalle2 = -vxBalle2;
                        if (yBalle2 >= (hauteurFenetre()/10*8)-10)
                            vyBalle2 = -vyBalle2;

                        
                        rebondBarre1(&vxBalle, &vyBalle, &xBalle, &yBalle, xBarre, yBarre); 
                        rebondBarre2(&vxBalle2, &vyBalle2, &xBalle2, &yBalle2, xBarre, yBarre); 

                        rebondBrique1(matrice_brique, &vxBalle, &vyBalle, &xBalle, &yBalle); 
                        rebondBrique2(matrice_brique, &vxBalle2, &vyBalle2, &xBalle2, &yBalle2); 
        

                        // Les coordonnees de la balle ayant eventuellement change,
                        // il faut redessiner la fenetre :
                        rafraichisFenetre();
                        break;
                        


                case Affichage:

                        // On part d'un fond d'ecran noir
                        //effaceFenetre (0, 0, 0);
                        if (appuyeJ==1)
                        {
                            ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB);

                            // Affichage d'une balle blanche
                            couleurCourante(255, 255, 255);
                            cercle(xBalle, yBalle, 5);

                            //Affiche le design global du jeu
                            afficheDesign();
                            afficheScore(matrice_brique, save);

                            //Affichage de la barre du joueur 1
                            afficheBarre(xBarre, yBarre, xBalle, yBalle); 
     
                            //matrice qui affiche les briques
                            afficheBrique(matrice_brique); 
                            
                        }


                        if (appuyeN==1)
                        {
                            ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB); 

                            couleurCourante(100, 255, 255); 
                            epaisseurDeTrait(3); 
                            afficheChaine("NIVEAU 2", 40, largeurFenetre()/2, hauteurFenetre()/2); 

                            couleurCourante(255, 255, 255); 
                            epaisseurDeTrait(5);
                            afficheChaine("B R E A K O U T", 40, largeurFenetre()/2-230, hauteurFenetre()-200); 

                            if (niveau2==1)
                            {
                                ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB); 

                                // Affichage d'une balle blanche
                                couleurCourante(255, 255, 255);
                                cercle(xBalle, yBalle, 5);

                                // Affichage d'une balle de couleur 
                                couleurCourante(255, 0, 205);
                                cercle(xBalle2, yBalle2, 5);

                                //Affiche le design global du jeu
                                afficheDesign();
                                afficheScore(matrice_brique, save);

                                //Affichage de la barre du joueur 1
                                afficheBarre(xBarre, yBarre, xBalle, yBalle); 

                                //affichage de la matrice Brique
                                afficheBrique(matrice_brique);  
                            
                            }
                        }

                    

//-----------------------------------------------------

                           // Affichage d'une image
                        if (image != NULL) // Si l'image a pu etre lue
                        {
                                // On affiche l'image
                                ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
                        }


                        

                        int score = calculScore(matrice_brique, save);

                        partieWin(score, compteur); 

                        //Perte de vie
                        if (yBalle < 0 || yBalle==0)
                        {
                            compteur = compteur-1;
                            xBalle = largeurFenetre()/2;
                            yBalle = hauteurFenetre()/8.5;

                            vxBalle=0; 
                            vyBalle=0;
                            xBarre = largeurFenetre()/2;
                            yBarre = hauteurFenetre()/10;

                            xBalle2 = largeurFenetre()/2;
                            yBalle2 = hauteurFenetre()/8.5;
                            vxBalle2=0; 
                            vyBalle2=0;

                        }



                        // suivi déplacement balle - barre
                        if (vxBalle==0 && vyBalle==0 && vxBalle2==0 && vyBalle2==0)
                        {
                            xBalle=xBarre;
                            xBalle2=xBarre;

                        }


                        compteurVie(compteur);


                        if(pause==1)
                        {
                            menu(); 
                            //Initialisation Balle 1
                            xBalle = largeurFenetre()/2;
                            yBalle = hauteurFenetre()/8.5;
                            vxBalle=0; 
                            vyBalle=0;

                            //initialisation Balle 2
                            xBalle2 = largeurFenetre()/2;
                            yBalle2 = hauteurFenetre()/8.5;
                            vyBalle2=0; 
                            vxBalle2=0; 

                            //initialisation Barre
                            xBarre = largeurFenetre()/2;
                            yBarre = hauteurFenetre()/10;
                        }

                    
                        break;


                case Clavier:
                        printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

                        switch (caractereClavier())
                        {
                                case 'Q': /* Pour sortir quelque peu proprement du programme */
                                case 'q':
                                                                                
                                        printf("Vous avez quitté la partie en cours\n");
                                        free(matrice_brique);
                                        free(save);
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
                                        compteur=3; 
                                        xBalle = largeurFenetre()/2;
                                        yBalle = hauteurFenetre()/8.5;
                                        vxBalle=0; 
                                        vyBalle=0;

                                        xBalle2 = largeurFenetre()/2;
                                        yBalle2 = hauteurFenetre()/8.5;
                                        vxBalle2=0; 
                                        vyBalle2=0;

                                        xBarre = largeurFenetre()/2;
                                        yBarre = hauteurFenetre()/10;
                        

                                        for (int i=0 ; i<12; i++)
                                        matrice_brique[i] = calloc(12, sizeof(int));

                                        for (int i = 0 ; i < 12; i++)
                                        {
                                                for (int j = 0 ; j<5; j++)
                                                {
                                                    matrice_brique[i][j]=0;
                                                }
                                        }    
                                        rafraichisFenetre();
                                    
                                        break;

                                case 'L':
                                case 'l':
                                                    
                                        xBalle2 = largeurFenetre()*valeurAleatoire();
                                        yBalle2 = hauteurFenetre()*valeurAleatoire();
                                        vxBalle2=7; 
                                        vyBalle2=-7; 

                                        break;

                                case 'S':
                                case 's':
                                       // SauvegardePartie(save);
                                        break;

                                case 'C':
                                case 'c':
                                        //ChargerPartie(save);
                                        rafraichisFenetre();
                                        break; 

                                case 'D':
                                case 'd':
                                        if(xBarre>60)
                                            xBarre-=20;
                                        break;

                                case 'G':
                                case 'g':
                                        if(xBarre<(largeurFenetre()-60))
                                            xBarre+=20;
                                        break;      


                                //début de partie
                                case ' ' :
                                    if (appuyeJ || niveau2)
                                    {
                                        if(xBalle<0 && vxBalle==0 && vyBalle==0)
                                        {
                                            vxBalle=3;
                                            vyBalle=-7;
                                        }
                                        if(xBalle>0 && vxBalle==0 && vyBalle==0)
                                        {
                                            vxBalle=3;
                                            vyBalle=7;
                                        }

                                        if(vxBalle2==0 && vyBalle2==0)
                                        {
                                            vxBalle2=3;
                                            vyBalle2= 4; 
                                        }
                                    }
                                    rafraichisFenetre();
                                    break;

                                case 'p' :
                                case 'P' :
                                    pause=1; 
                                    appuyeJ=0; 
                                    appuyeN=0; 
                                    vxBalle=0;
                                    vyBalle=0;
                                    vxBalle2=0; 
                                    vyBalle2=0; 
                                    menu(); 
                                    rafraichisFenetre();
                                    break;

                                case 'j': 
                                case 'J':
                                    appuyeJ=1;
                                    pause=0;  
                                    appuyeN=0; 
                                    rafraichisFenetre();
                                    break; 

                                case 'n': 
                                case 'N': 
                                    appuyeN=1; 
                                    pause=0; 
                                    appuyeJ=0; 

                                    rafraichisFenetre(); 
                                    break; 
                            }
                        break;
                        
                case ClavierSpecial:
                        printf("ASCII %d\n", toucheClavier());
                        if(toucheClavier() == ToucheFlecheGauche && xBarre>60)
                            xBarre-=20;

                        else if(toucheClavier() == ToucheFlecheDroite && xBarre<(largeurFenetre()-60))
                            xBarre+=20; 

                        break;


                case Souris: // Si la souris est deplacee
                    if ( (xBarre>60) || (xBarre<(largeurFenetre()-60)) )
                    {
                        xBarre = abscisseSouris();
                    }
                        break;



                case BoutonSouris:
                        if (etatBoutonSouris() == GaucheAppuye)
                        {
                            printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
                            if (pause==1)
                            {
                                if ((abscisseSouris()>largeurFenetre()/2) && (abscisseSouris()<largeurFenetre()/2+180) && (ordonneeSouris()>540) && (ordonneeSouris()<650))
                                {
                                    appuyeJ=1;
                                    pause=0; 
                                    rafraichisFenetre();
                                }
                          
                                if ((abscisseSouris()>largeurFenetre()/2) && (abscisseSouris()<largeurFenetre()/2+180) && (ordonneeSouris()>440) && (ordonneeSouris()<550))
                                {
                                    appuyeN=1; 
                                    pause=0; 
                                    appuyeJ=0; 
                                    niveau2=0; 
                                    rafraichisFenetre();
                                }

                                if ((abscisseSouris()>largeurFenetre()/2) && (abscisseSouris()<largeurFenetre()/2+180) && (ordonneeSouris()>340) && (ordonneeSouris()<450))
                                {
                                    printf("Vous avez quitté la partie en cours\n");
                                    free(matrice_brique);
                                    free(save);
                                    libereDonneesImageRGB(&image); /* On libere la structure image,
                                    c'est plus propre, meme si on va sortir du programme juste apres */
                                    termineBoucleEvenements();
                                }
                            }

                            if (appuyeN==1)
                            {
                                if ( (abscisseSouris()>largeurFenetre()/2) && (abscisseSouris()<largeurFenetre()/2+180) && (ordonneeSouris()>340) && (ordonneeSouris()<450))
                                {
                                    niveau2=1;
                                    appuyeJ=0;
                                    pause=0; 
                                    appuyeN=1;
                                    rafraichisFenetre();
                                }
                            }
                        
                        }
                        else if (etatBoutonSouris() == GaucheRelache)
                        {
                                printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());

                        }

                        break;


                case Inactivite: // Quand aucun message n'est disponible
                        break;
                
                case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
                        // Donc le systeme nous en informe
                        if (xBalle >= largeurFenetre())
                                xBalle = largeurFenetre()-1;
                        if (yBalle >= hauteurFenetre())
                        {
                            yBalle = hauteurFenetre()-1;
                            printf("Largeur : %d\t", largeurFenetre());
                            printf("Hauteur : %d\n", hauteurFenetre());
                        }

                        if (xBarre >= largeurFenetre())
                                xBalle = largeurFenetre()-1;
                        if (yBarre >= hauteurFenetre())
                        {
                            yBarre = hauteurFenetre()-1;
                            printf("Largeur : %d\t", largeurFenetre());
                            printf("Hauteur : %d\n", hauteurFenetre());

                            printf("Largeur : %d\t", largeurFenetre());
                            printf("Hauteur : %d\n", hauteurFenetre());
                        }
                        rafraichisFenetre(); 
                        break;
    }
}


/*
Structure de briques prenant en compte l'écart entre chaque brique 
Structure brique prenant en compte les coordonnées d'une brique ainsi que sa résistance.
*/


