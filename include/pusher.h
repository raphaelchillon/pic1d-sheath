#ifndef PUSHER_H
#define PUSHER_H

/* 

This code declares the functions for the pusher.

All quantities in normalized units, see particles.h and docs/model.md. 


*/

#include "particles.h"

void velocity_setback(struct specie *sp, double *field, double dt);

void push_particles(struct specie *sp, double *field, double dt);


#endif