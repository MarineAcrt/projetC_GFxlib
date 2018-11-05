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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Fonctions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*

//________________FONCTION SAUVEGARDEPARTIE____________

void SauvegardePartie(SAVE* save)
{
    FILE* Sauvegarde = NULL;
    Sauvegarde = fopen("Sauvegarde.b","wb");

    if(Sauvegarde != NULL)
        {
        fwrite( save , sizeof(SAVE) , 1 , Sauvegarde);

        fclose(Sauvegarde);
        printf("\nPartie Sauvegardée\n");
        }

    else
        {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier Sauvegarde.b\n");
        }

  
}


//________________FONCTION CHARGERPARTIE________________________________

void ChargerPartie(SAVE* save)
{
    //strcat(nomFichierSauvegarde,".txt");
    FILE* Sauvegarde = NULL;
    Sauvegarde = fopen("Sauvegarde.b","rb");

    if(Sauvegarde != NULL)
    {
        fread( save, sizeof(SAVE), 1, Sauvegarde);
        //fscanf( Sauvegarde, &(save->score), &(save->compteur), save->matrice_brique); 
        fclose(Sauvegarde);
        printf("\nPartie Chargée\n");
    }
    else
    {
        printf("Impossible d'ouvrir");
        fclose(Sauvegarde);
        //return 0;
    }
}

*/





/*

void initJeuMoyen(int ** matrice_brique)
{
    // création matrice brique
                        matrice_brique = calloc (12,sizeof(int*));

                        for (int i=0 ; i<12; i++)
                        matrice_brique[i] = calloc(5, sizeof(int));

                        for (int i = 0 ; i < 12; i++)
                        {
                                for (int j = 0 ; j<5; j++)
                                {
                                    int a = rand()*10000;
                                    if (a>= 5000)
                                    {
                                        matrice_brique[i][j]= 0;
                                    }
                                    else{
                                        matrice_brique[i][j]= 1;
                                    }
                                    
                                }
                        }
}


void initJeuFacile (int ** matrice_brique)
{
    // création matrice brique
                        matrice_brique = calloc (12,sizeof(int*));

                        for (int i=0 ; i<12; i++)
                        matrice_brique[i] = calloc(5, sizeof(int));

                        for (int i = 0 ; i < 12; i++)
                        {
                                for (int j = 0 ; j<5; j++)
                                {
                                    int a = rand()*10000;
                                    if (a>= 10000)
                                    {
                                        matrice_brique[i][j]= 0;
                                    }
                                    else{
                                        matrice_brique[i][j]= 1;
                                    }
                                    
                                }
                        }
}

void initJeuDifficile (int ** matrice_brique)
{
    // création matrice brique
                        matrice_brique = calloc (12,sizeof(int*));

                        for (int i=0 ; i<12; i++)
                        matrice_brique[i] = calloc(5, sizeof(int));

                        for (int i = 0 ; i < 12; i++)
                        {
                                for (int j = 0 ; j<5; j++)
                                {
                                    int a = rand()*10000;
                                    if (a>= 2000)
                                    {
                                        matrice_brique[i][j]= 0;
                                    }
                                    else{
                                        matrice_brique[i][j]= 1;
                                    }
                                    
                                }
                        }
}
*/

/*

//Initialise theme
//initialisation Couleur de Fond

couleur initialisationFond(int numerotheme)
{
    switch(numerotheme)
    {
    case 1:
    {
        couleur couleurfond1;
            couleurfond1.B=0;
            couleurfond1.R=0;
            couleurfond1.V=128;
        return couleurfond1;
        break;
    }
    case 2:
    {
        couleur couleurfond2;
            couleurfond2.B=240;
            couleurfond2.R=240;
            couleurfond2.V=240;
        return couleurfond2;
        break;
    }
}

//initialisation Couleur Police

couleur initialisationPolice(int numerotheme)
{
    if(numerotheme==1)
    {
        couleur couleurpolice1;
            couleurpolice1.B=0;
            couleurpolice1.R=0;
            couleurpolice1.V=128;
        return couleurpolice1;
    }
    if(numerotheme==2)
    {
        couleur couleurpolice2;
            couleurpolice2.B=0;
            couleurpolice2.R=128;
            couleurpolice2.V=0;
        return couleurpolice2;
    }
}



//initialisation structure Thème

theme initialisationTheme(int numerotheme)
{
    switch(numerotheme)
    {
    case 1:
    {
        theme theme1;
        theme1.numerotheme=1;
        theme1.musiquetheme=1;
        theme1.couleurfond=initialisationFond(theme1.numerotheme);
        theme1.couleurpolice=initialisationPolice(theme1.numerotheme);
        return theme1;
        break;
    }

    case 2:
    {
        theme theme2;
        theme2.numerotheme=2;
        theme2.musiquetheme=2;
        theme2.couleurfond=initialisationFond(theme2.numerotheme);
        theme2.couleurpolice=initialisationPolice(theme2.numerotheme);
        return theme2;
        break;
    }
*/




void menu(void)
{
    static DonneesImageRGB * imageFond = NULL;
    imageFond = lisBMPRGB("etoile.bmp");

    ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB);

    couleurCourante(100, 255, 255); 
    epaisseurDeTrait(3); 
    afficheChaine("JOUER", 40, largeurFenetre()/2, hauteurFenetre()/2+100); 
    afficheChaine("PARAMETRES", 40, largeurFenetre()/2, hauteurFenetre()/2); 
    afficheChaine("QUITTER", 40, largeurFenetre()/2, hauteurFenetre()/2-100); 

    couleurCourante(255, 255, 255); 
    epaisseurDeTrait(5);
    afficheChaine("B R E A K O U T", 40, largeurFenetre()/2-230, hauteurFenetre()-200); 
    //rectangle((largeurFenetre()/2), 650, largeurFenetre()/2+200, 580);

}


//Fonction affiche score
void afficheScore(int ** matrice_brique, SAVE* save)
{
    int score=0;

    //Affiche Score
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(4); 
    //afficheChaine("SCORE", 30, largeurFenetre()/12, 865); 

    score = calculScore(matrice_brique, save); 

    char caractere1[10];
    sprintf(caractere1, "%d", score);
    afficheChaine(caractere1, 30, largeurFenetre()/11, 830);
   

}
    




// fonction qui calcule le score
int calculScore(int ** matrice_brique, SAVE* save)
{
    int score = 0; 
    for (int i = 0 ; i < 12; i++)
                            {
                                    for (int j = 0 ; j<5; j++)
                                    {
                                        if (matrice_brique[i][j] == 1)
                                        {   
                                            score += 10; 
                                        }
                                        if (matrice_brique[i][j] == 2)
                                        {   
                                            score += 20; 
                                        }
                                    }
                            }
    save->score=score;
    return score; 
}



//affiche le Design
void afficheDesign(void)
{

    static DonneesImageRGB * imageMur = NULL;
    static DonneesImageRGB * imageMurDroit = NULL;
    static DonneesImageRGB * imageMurGauche = NULL;

    imageMur = lisBMPRGB("murscore1.bmp");
    imageMurGauche = lisBMPRGB("cote_gauche.bmp");
    imageMurDroit = lisBMPRGB("cote-droit.bmp");

    ecrisImage(0, 800, imageMur->largeurImage, imageMur->hauteurImage, imageMur->donneesRGB);
    ecrisImage(0, 0, imageMurGauche->largeurImage, imageMurGauche->hauteurImage, imageMurGauche->donneesRGB);
    ecrisImage(largeurFenetre()-20, 0, imageMurDroit->largeurImage, imageMurDroit->hauteurImage, imageMurDroit->donneesRGB);

    rafraichisFenetre();
/*
    //Affiche Design
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(5);

    //Affiche Joueurs
    afficheChaine("Joueur 1 :", 20, largeurFenetre()/2-290, hauteurFenetre()/2+hauteurFenetre()/2.5);
    afficheChaine("Joueur 2 :", 20, largeurFenetre()/2-30, hauteurFenetre()/2+hauteurFenetre()/2.5);
*/

    }

void compteurVie(int compteur)
{
        static DonneesImageRGB * imageVieOff = NULL;
        static DonneesImageRGB * imageGameOver = NULL;
        static DonneesImageRGB * imageFond = NULL;
        static DonneesImageRGB * imageVieOn = NULL;

        imageVieOn = lisBMPRGB("vie_on.bmp");
        imageVieOff = lisBMPRGB("vie_off.bmp");
        imageGameOver = lisBMPRGB("game_over.bmp");
        imageFond = lisBMPRGB("etoile.bmp");

                // Affichage de la vie 3
        ecrisImage(460, 950, imageVieOn->largeurImage, imageVieOn->hauteurImage, imageVieOn->donneesRGB);                       
        // Affichage de la vie 2
        ecrisImage(500, 950, imageVieOn->largeurImage, imageVieOn->hauteurImage, imageVieOn->donneesRGB);
        // Affichage de la vie 1
        ecrisImage(540, 950, imageVieOn->largeurImage, imageVieOn->hauteurImage, imageVieOn->donneesRGB);


                            // Disparition des vies
                        if (compteur==2)
                        {
                            ecrisImage(460, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);                     
                        }

                        else if (compteur==1)
                        {
                            ecrisImage(460, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);                       
                            ecrisImage(500, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);
                        }

                        if (compteur==0)
                        {
                            //affichage du fond étoilé
                            ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB);
                            //game over
                            ecrisImage(50, hauteurFenetre()/2, imageGameOver->largeurImage, imageGameOver->hauteurImage, imageGameOver->donneesRGB);                       
                            //affichage des vies off
                            ecrisImage(460, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);                       
                            ecrisImage(500, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);
                            ecrisImage(540, 950, imageVieOff->largeurImage, imageVieOff->hauteurImage, imageVieOff->donneesRGB);  
                            rafraichisFenetre();                    
                        }
}


void creationBrique(int ** matrice_brique)
{
        // création matrice brique

    for (int i=0 ; i<12; i++)
    matrice_brique[i] = calloc(12, sizeof(int));
    /*if(matrice_brique==NULL)
    {
        printf("ERROR\n"); 
        exit(-1); 
    }
*/
    for (int i = 0 ; i < 12; i++)
    {
            for (int j = 0 ; j<5; j++)
            {
                matrice_brique[i][j]=0; 
            }
    }    

}


void afficheBrique(int ** matrice_brique)
{
    static DonneesImageRGB * imageBriqueCasse = NULL;
    static DonneesImageRGB * imageBrique = NULL;

    imageBrique = lisBMPRGB("brique_lingot.bmp");
    imageBriqueCasse = lisBMPRGB("brique_casse.bmp");

    //matrice qui affiche les briques
    for (int i = 0 ; i < 12; i++)
    {  
            for (int j = 0 ; j<5; j++)
            {
                if (matrice_brique[i][j] == 0)
                {
                    ecrisImage (((i*40)+largeurFenetre()/30)+40, (4-j)*20+(hauteurFenetre()/2), imageBrique->largeurImage, imageBrique->hauteurImage, imageBrique->donneesRGB);
                }
                if (matrice_brique[i][j] == 1)
                {
                    ecrisImage (((i*40)+largeurFenetre()/30)+40, (4-j)*20+(hauteurFenetre()/2), imageBriqueCasse->largeurImage, imageBriqueCasse->hauteurImage, imageBriqueCasse->donneesRGB);
                }
            }
    }
    rafraichisFenetre();
}


void afficheBarre(int xBarre, int yBarre, int xBalle, int yBalle)
{
    static DonneesImageRGB * imageBarreOn = NULL;
    static DonneesImageRGB * imageBarreOff = NULL;
    imageBarreOff = lisBMPRGB("barre_neonoff.bmp");
    imageBarreOn = lisBMPRGB("barre_neonon.bmp");

    if ((yBalle <= (yBarre+19)) && (xBalle>=xBarre-40) && (xBalle<=xBarre+40))
        {
            ecrisImage (xBarre-40, yBarre+2.5, imageBarreOn->largeurImage, imageBarreOn->hauteurImage, imageBarreOn->donneesRGB);    
        }
        else
        {
            ecrisImage (xBarre-40, yBarre+2.5, imageBarreOff->largeurImage, imageBarreOff->hauteurImage, imageBarreOff->donneesRGB);
        } 
}


void partieWin(int score, int compteur)
{
    static DonneesImageRGB * imageFond = NULL;
    imageFond = lisBMPRGB("etoile.bmp");

    // Partie gagnée
    if (score >= 12*5)
    {
        ecrisImage(0, 0, imageFond->largeurImage, imageFond->hauteurImage, imageFond->donneesRGB);

        couleurCourante(255, 255, 255); 
        epaisseurDeTrait(5);
        afficheChaine("B R E A K O U T", 40, largeurFenetre()/2-230, hauteurFenetre()-200); 

        couleurCourante(255, 0, 0);
        epaisseurDeTrait(5); 
        afficheChaine("YOU WIN", 50, largeurFenetre()/3, hauteurFenetre()/2); 
        compteur=compteur; 
        rafraichisFenetre();
    }
}


void rebondBrique1(int ** matrice_brique, int * vxBalle, int * vyBalle, int * xBalle, int * yBalle)
{

    // on fait rebondir la balle 1 sur les briques
    for (int i = 0 ; i < 12; i++)
        {
                for (int j = 0 ; j<5; j++)
                {
                    // cas des X
                    int x = ((i*40)+largeurFenetre()/30)+40;
                    int y = (5-j)*20+(hauteurFenetre()/2);
                    int x2 = x+ 40;
                    int y2 = y- 20;

                    if ((*xBalle >= x-7) &&  (*xBalle <= x) && (*yBalle >= y2) && (*yBalle < y) && (matrice_brique[i][j] < 2))
                    {   
                        *vxBalle=-*vxBalle; 
                        matrice_brique[i][j]+=1;

                    }

                    if ((*yBalle <= y+7) && (*yBalle >= y)  && (*xBalle >= x) && (*xBalle < x2) && (matrice_brique[i][j] < 2))
                    {
                        *vyBalle=-*vyBalle;
                        matrice_brique[i][j]+=1;                                        
                    }


                    if ((*xBalle <= x2+7) && (*xBalle >= x2) && (*yBalle >= y2) && (*yBalle < y) && (matrice_brique[i][j] < 2))
                    {   
                        *vxBalle=-*vxBalle; 
                        matrice_brique[i][j]+=1;

                    }

                    if ((*yBalle >= y2-7) &&  (*yBalle <= y2) && (*xBalle >= x) && (*xBalle < x2) && (matrice_brique[i][j] < 2))
                    {
                        *vyBalle=-*vyBalle;
                        matrice_brique[i][j]+=1; 
                    }

                }
        } 
}


void rebondBrique2(int ** matrice_brique, int * vxBalle2, int * vyBalle2, int * xBalle2, int * yBalle2)
{
    // on fait rebondir la balle 2 sur les briques
    for (int i = 0 ; i < 12; i++)
        {
                for (int j = 0 ; j<5; j++)
                {
                    // cas des X
                    int x = ((i*40)+largeurFenetre()/30)+40;
                    int y = (5-j)*20+(hauteurFenetre()/2);
                    int x2 = x+ 40;
                    int y2 = y- 20;

                    if ((*xBalle2 >= x-7) && (*xBalle2 <= x) && (*yBalle2 >= y2) && (*yBalle2 < y) && (matrice_brique[i][j] < 2))
                    {   
                        *vxBalle2=-*vxBalle2; 
                        matrice_brique[i][j]+=1;

                    }

                    if ((*yBalle2 <= y+7) && (*yBalle2 >= y)  && (*xBalle2 >= x) && (*xBalle2 < x2) && (matrice_brique[i][j] < 2))
                    {
                        *vyBalle2=-*vyBalle2;
                        matrice_brique[i][j]+=1;                                        
                    }


                    if ((*xBalle2 <= x2+7) && (*xBalle2 >= x2) && (*yBalle2 >= y2) && (*yBalle2 < y) && (matrice_brique[i][j] < 2))
                    {   
                        *vxBalle2=-*vxBalle2; 
                        matrice_brique[i][j]+=1;

                    }

                    if ((*yBalle2 >= y2-7) &&  (*yBalle2 <= y2) && (*xBalle2 >= x) && (*xBalle2 < x2) && (matrice_brique[i][j] < 2))
                    {
                        *vyBalle2=-*vyBalle2;
                        matrice_brique[i][j]+=1; 
                    }

                }
        } 
}





void rebondBarre1(int * vxBalle, int * vyBalle, int * xBalle, int * yBalle, int xBarre, int yBarre)
{
        // on fait rebondir la balle 1 sur la barre
    if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre)  && (*xBalle>=xBarre-40) && (*xBalle<=xBarre-30) )
        {     
                *vxBalle = -8;
                *vyBalle = 2;      
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre)  && (*xBalle>=xBarre-30) && (*xBalle<=xBarre-20) )
        {     
                *vxBalle = -6;
                *vyBalle = 4;      
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre)  && (*xBalle>=xBarre-20) && (*xBalle<=xBarre-10) )
        {     
                *vxBalle = -5;
                *vyBalle = 5;      
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre)  && (*xBalle>xBarre-10) && (*xBalle<xBarre) )
        {
                *vxBalle = -3;
                *vyBalle = 7;                                    
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre)  && (*xBalle==xBarre) )
        {
                *vxBalle = *vxBalle;
                *vyBalle = *vyBalle;      
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre) && (*xBalle>xBarre) && (*xBalle<=xBarre+10) )
        {                               
                *vxBalle = 3;
                *vyBalle = 7; 
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre) && (*xBalle>xBarre+10) && (*xBalle<=xBarre+20) )
        {
                *vxBalle = 5;
                *vyBalle = 5; 
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre) && (*xBalle>xBarre+20) && (*xBalle<=xBarre+30) )
        {
                *vxBalle = 6;
                *vyBalle = 4; 
        }
    else if ((*yBalle <= (yBarre+19)) && (*yBalle >= yBarre) && (*xBalle>xBarre+30) && (*xBalle<=xBarre+40) )
        {
                *vxBalle = 8;
                *vyBalle = 2; 
        }

}



void rebondBarre2(int * vxBalle2, int * vyBalle2, int * xBalle2, int * yBalle2, int xBarre, int yBarre)
{

        // on fait rebondir la balle 2 sur la barre
    if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>=xBarre-40) && (*xBalle2<=xBarre-30) )
        {     
                *vxBalle2 = -8;
                *vyBalle2 = 2;      
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>=xBarre-30) && (*xBalle2<=xBarre-20) )
        {     
                *vxBalle2 = -6;
                *vyBalle2 = 4;      
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>=xBarre-20) && (*xBalle2<=xBarre-10) )
        {     
                *vxBalle2 = -5;
                *vyBalle2 = 5;      
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre)  && (*xBalle2>xBarre-10) && (*xBalle2<xBarre) )
        {
                *vxBalle2 = -3;
                *vyBalle2 = 7;                                    
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre)  && (*xBalle2==xBarre) )
        {
                *vxBalle2 = *vxBalle2;
                *vyBalle2 = *vyBalle2;      
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>xBarre) && (*xBalle2<=xBarre+10) )
        {                               
                *vxBalle2 = 3;
                *vyBalle2 = 7; 
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>xBarre+10) && (*xBalle2<=xBarre+20) )
        {
                *vxBalle2 = 5;
                *vyBalle2 = 5; 
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>xBarre+20) && (*xBalle2<=xBarre+30) )
        {
                *vxBalle2 = 6;
                *vyBalle2 = 4; 
        }
    else if ((*yBalle2 <= (yBarre+19)) && (*yBalle2 >= yBarre) && (*xBalle2>xBarre+30) && (*xBalle2<=xBarre+40) )
        {
                *vxBalle2 = 8;
                *vyBalle2 = 2; 
        }

}
