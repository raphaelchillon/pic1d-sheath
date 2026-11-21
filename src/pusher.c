#include "pusher.h"

/* 

This function aims to pushback the initial velocity to v(-dt/2) in order to fulfill the leapfrog method. 


 */
void velocity_setback(struct specie *sp, double *field, double dt){

for(int i=0; i<sp->number; i++){

    sp->p[i].v  -= (dt/2)*(sp->q/sp->m)*field[i]; /* Using v(end) - v(start) = dt*q/mE */

}

}




/* 

PUSHING PARTICLES USING LEAPFROG METHOD 

time:       n-1/2           n               n+1/2               n + 1

x :                        x[n]                                 x[n+1]

v:         v[n-1/2]                        v[n+1/2]         

This method follows the following scheme : we first update the velocity at n-1/2 to n+1/2 using the field at the nth time. 
Then, we update the position from x[n] to x[n+1] using the velocity at the time n+1/2. 

                
*/
void push_particles(struct specie *sp, double *field, double dt){

for(int i=0; i<sp->number; i++){

    sp->p[i].v  += (dt)*(sp->q/sp->m)*field[i]; /* Updating the velocity */

    sp->p[i].x  += dt*sp->p[i].v; /* Using v(end) - v(start) = dt*q/mE */

}

}
