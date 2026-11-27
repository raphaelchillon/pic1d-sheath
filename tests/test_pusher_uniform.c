#include "particles.h"
#include "pusher.h"
#include <stdio.h> 
#include <stdlib.h>


/* 

PUSHER FOR UNIFORM FIELD. 

We will have 1 electron, starting from x=0 with v=1. 
The corresponding field will be E = Eo.

*/



int main(void){

    /* PARAMETERS DEFINITION */

    double dt = 0.1; 
    double field_value = 1; 

    double x0 = 0;
    double v0 = 1;

    struct specie electron;     //defining the electron specie 
        electron.q=-1; 
        electron.m=1; 
        electron.number = 1; 
        electron.p = calloc(electron.number,sizeof(struct particle));

    if (electron.p == NULL) {                   //checking whether the pointer to the particles array works 
    printf("Error : not enough memory\n");
    return 1;
    } 
    
    /* INITIAL CONDITIONS */

    for(int i=0; i<electron.number; i++){   //setting the particle's velocity & position to the initial values x=0 & v=1 

        electron.p[i].x = x0;                    
        electron.p[i].v = v0; 

    }

    double *E_field = calloc(electron.number,sizeof(double));   //initialisation of the field on each particles (here it's uniform)

    for(int i=0; i<electron.number; i++){

        E_field[i]=field_value; 

    }
    

    velocity_setback(&electron, E_field, dt); //Initial velocity stepback

    
    /* MAIN LOOP */

    printf("#   time,   xth,    x,     xth - x \n");


    for(int j=0; j<50; j++){

        double xth = (electron.q/electron.m)*field_value*1/2*((j+1)*dt)*((j+1)*dt) + v0*((j+1)*dt) + x0;
        double time = (j+1)*dt;

        push_particles(&electron, E_field, dt);

        double x = electron.p[0].x;
        printf("%f %f %f %e \n", time , xth , x, xth - x);

    } 


    free(E_field);
    free(electron.p);


    return 0;
}