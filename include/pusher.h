#ifndef PUSHER_H
#define PUSHER_H

#include "particles.h"

void speed_setback(struct specie A, double field, double timestep);

void pusher(struct specie A, double field, double timestep);


#endif