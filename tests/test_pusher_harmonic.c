#include "particles.h"
#include "pusher.h"
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/* 

PUSHER FOR HARMONIC OSCILLATIONS. 

We will have 3 electrons, each starting from x=0.5, x=1 and x=2. They will be having an initial velocity of 1 (Normalized value). 
The corresponding field will be E = x where x is the oscillation around their original position.

*/


int main(void){

    /* PARAMETERS DEFINITION */ 

    double dt = 0.1; 

    struct specie electron; 
    electron.q = -1 ;
    electron.m = 1 ;
    electron.number = 3 ;
    electron.p = calloc(electron.number,sizeof(struct particle));

    /* PARTICLES INITIALIZATION */ 
    
    double initial_pos[]= {0.5 , 1 , 2};
    double *E_field = calloc (electron.number, sizeof(double));

    for(int i=0; i<electron.number; i++){



        electron.p[i].x = initial_pos[i];
        electron.p[i].v = 1;

        E_field[i]= electron.p[i].x ;


    }

    velocity_setback(&electron, E_field, dt); 


    /* PARTICLES PUSH */ 



    return 0;
}

