#include "particles.h"
#include "pusher.h"
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/* 

PUSHER FOR HARMONIC OSCILLATIONS. 

We will have 3 electrons, each starting from x=0.5, x=1 and x=2. They will be having an initial velocity of 1 (Normalized value). 
The corresponding field will be E = x where x is the oscillation around the origin.

*/


int main(void){

/* PARAMETERS DEFINITION */ 

    double dt = 0.1; 

    struct specie electron; 
    electron.q = -1 ;
    electron.m = 1 ;
    electron.number = 3 ;
    electron.p = calloc(electron.number,sizeof(struct particle));

    int periods = 100;





/* PARTICLES INITIALIZATION */ 
    
    double initial_pos[]= {0.5 , 1 , 2}; // Initial condition for position
    double initial_vel[]= {1 , 1 , 1}; // Initial condition for velocity

    double temp_pos[electron.number]; // temporary position for W -> x^n when at time n+1 
    double temp_vel[electron.number]; // temporary velocity for W -> v^n-1/2 when at time n+1

    double W_th[electron.number]; //theorical energy (it is conserved)

    double *E_field = calloc (electron.number, sizeof(double)); //initialization of the field

    if (E_field == NULL || electron.p == NULL){     //checking whether the pointers works 
                           
        printf("Error : not enough memory\n");
        return 1;
        
    } 

    for(int i=0; i<electron.number; i++){ //initialization of position, velocity, field & calcul of energy 



        electron.p[i].x = initial_pos[i];
        electron.p[i].v = initial_vel[i];

        E_field[i]= electron.p[i].x ; 

        W_th[i] = 0.5 * electron.m * initial_vel[i]*initial_vel[i]  + initial_pos[i] * initial_pos[i] * 0.5 ; // theorical solution for energy.


    }
    

    velocity_setback(&electron, E_field, dt); //setback velocity for leapfrog. 





/* PARTICLES PUSH -> We push x & v, then we compute the new field &  the energy (simulated & theorical)*/ 

    printf("#   time,   x(1),    x_th(1),     W(1),    Wth(1),      x(2),    x_th(2),     W(2),    Wth(2)   x(3),    x_th(3),     W(3),    Wth(3) \n");


    for(int j = 0; j<ceil(M_PI*2*periods* (1/dt)); j++){ 
        
        for(int i=0; i<electron.number; i++){

            temp_pos[i]=electron.p[i].x; //saving the position x at time n 
            temp_vel[i]=electron.p[i].v; //saving the velocity v at time n-1/2 

        }




        push_particles(&electron, E_field, dt); //updating x & v to n+1 and n + 1/2




        for(int i=0; i<electron.number; i++){


            E_field[i]= electron.p[i].x ; // Recalculation of the field with each iteration at time n+1 


        }




        double xth[electron.number]; // theorical position 
        double time = (j)*dt; // time 
        double W[electron.number];  // Simulated energy



        
        printf(" %f", time);



        for(int i=0; i<electron.number; i++){ //iteration for printing data

            xth[i]=initial_pos[i]*cos(time) + initial_vel[i]*sin(time); // theorical solution for harmonic oscillator with x0 & v0 as initial values. 

            double mean_velocity = ( electron.p[i].v + temp_vel[i] ) * 0.5; // average of v(n-1/2) and v(n+1/2): x and v must be taken at the same time

            W[i] = 0.5 * electron.m * mean_velocity * mean_velocity + (temp_pos[i])*(temp_pos[i]) * 0.5 ; // simulated solution for energy at time n 
            
            
            printf(" %f  %f  %.10e %f ", temp_pos[i], xth[i], W[i], W_th[i]);
        }

        printf(" \n");


        

        
    }

        
    free(E_field);
    free(electron.p);
    
    


    return 0;
}

