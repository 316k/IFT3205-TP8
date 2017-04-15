/*------------------------------------------------------*/
/* Prog    : Tp10_IFT3205.c                              */
/* Auteur  : Nicolas Hurtubise, Guillaume Riou          */
/* Date    : --/--/2010                                 */
/* version :                                            */ 
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* FICHIERS INCLUS -------------------------------*/
/*------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "FonctionDemo10.h"

/*------------------------------------------------*/
/* DEFINITIONS -----------------------------------*/   
/*------------------------------------------------*/
#define NAME_VISUALISER_IMG "./display "
#define NAME_VISUALISER     "./ViewSig.sh "

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/

/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main(int argc,char **argv)
{
    int i,j,n;
    char BufSystVisuSig[100];
    int length;

    //=================================================
    //Question 2.1
    //------------
    //
    // Sample Rate = 11025 ech/sec
    // Frequence �chant= 11025
    //
    //  
    //=================================================

    float*  SignX=LoadSignalDat("SOUND_GoodMorningVietnam",&length);
    float*  SignY=fmatrix_allocate_1d(length);
    
    float*  b=fmatrix_allocate_1d(length);

    for(n=0;n<length;n++) {
        b[n] = (rand()/(float)RAND_MAX) * 2 - 1;
    }
    
    float SamplingRate=11025;

    float f0 = 0.3;
    float b0 = 0.9;
    float A = SamplingRate/100.0; // Chorus un peu plus subtile que /5.0
    int M;
    
    for(n=0;n<length;n++) {
        SignY[n] = SignX[n];

        M = A * sin(2 * PI * n * f0 / SamplingRate);
        
        if(n >= M)
            SignY[n] += b0 * SignX[n - M];
    }

    for(n=0;n<length;n++) {
        SignY[n] *= 0.5;
    }
    
    //Sauvegarde
    SaveSignalDatWav("SignalOut8",SignY,length,SamplingRate); 
    //SaveSignalDat("SOUND_GoodMorningVietnam1",SignY,length);
 
    //Visu
    //strcpy(BufSystVisuSig,NAME_VISUALISER);
    //strcat(BufSystVisuSig,"SOUND_GoodMorningVietnam1.dat&");
    //printf(" %s",BufSystVisuSig);
    //system(BufSystVisuSig);
       
 
    //==End=========================================================

    //retour sans probleme
    printf("\n C'est fini ... \n\n");
    return 0; 	 
}


