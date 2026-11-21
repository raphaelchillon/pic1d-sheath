#ifndef PUSHER_H
#define PUSHER_H

#include "particles.h"

void velocity_setback(struct specie *sp, double *field, double dt);

void push_particles(struct specie *sp, double *field, double dt);


#endif