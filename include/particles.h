/* 

All quantities in normalized units, see particles.h and docs/model.md. 


*/


#ifndef PARTICLES_H
#define PARTICLES_H



struct particle {

    double x; /*Particle's position, on the x axis'*/ 
    double v; /*Particle's speed, on the x axis'*/ 

};

struct specie {

    double q; /*Specie's charge, on the x axis'*/ 
    double m; /*Specie's mass, on the x axis'*/ 
    struct particle *p; /*pointer to the particles from said specie'*/ 
    int number; /*Number of particles inside the specie'*/ 

};



#endif