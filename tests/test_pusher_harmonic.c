#include "particles.h"
#include "pusher.h"
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/* 

PUSHER FOR HARMONIC OSCILLATIONS. 

We will have 3 electrons, each 

*/


int main(void){

    /* PARAMETERS DEFINITION */ 

    struct specie electron; 

    electron.q = -1 ;
    electron.m = 1 ;
    electron.number = 3 ;
    electron.p = calloc(electron.number,sizeof(struct Particle));

    return 0;
}

