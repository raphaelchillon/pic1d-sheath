#include "pusher.h"

/* 

This function aims to pushback the initial velocity to v(-dt/2) in order to fulfill the leapfrog method. 


 */
void velocity_setback(struct specie *sp, double *field, double dt){

for(int i=0; i<sp->number; i++){

    sp->p[i].v  -= (dt/2)*(sp->q/sp->m)*field[i]; /* Using v(end) - v(start) = dt*q/mE */

}

}

void push_particles(struct specie *sp, double *field, double dt){

for(int i=0; i<sp->number; i++){

    sp->p[i].v  += (dt)*(sp->q/sp->m)*field[i]; /* Using v(end) - v(start) = dt*q/mE */

    sp->p[i].x  += dt*sp->p[i].v; /* Using v(end) - v(start) = dt*q/mE */

}

}
