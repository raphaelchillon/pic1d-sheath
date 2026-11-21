#include "particles.h"
#include "pusher.h"
#include <stdio.h> 
#include <stdlib.h>


int main(void){

    /* PARAMETERS DEFINITION */

    double dt = 0.1; 
    double dx = 50;
    double field = 1; 

    struct specie electron;     //defining the electron specie 
        electron.q=-1; 
        electron.m=1; 
        electron.number = 1; 
        electron.p = calloc(electron.number,sizeof(struct particle));

    if (electron.p == NULL) {                   //checking whether the pointer to the particles array works 
    printf("Error : not enough memory\n");
    return 1;
    } 

    for(int i=0; i<electron.number; i++){   //setting the particle's velocity & position to the initial values x=0 & v=1 

        electron.p[i].x = 0;                    
        electron.p[i].v = 1; 

    }
        
    /* INITIAL CONDITIONS */

    



    return 0;
}