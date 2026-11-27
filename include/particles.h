#ifndef PARTICLES_H
#define PARTICLES_H

/*

This code declares the structures for the PIC code.

Particle and species data structures.

All quantities are in normalized units (see docs/model.md):
  position x   in Debye lengths, lambda_D
  velocity v   in thermal velocities, v_th = sqrt(k_B T_e / m_e)
  time t       in inverse plasma frequencies, 1/omega_p
  field E      in E_0 = k_B T_e / (e lambda_D)
  charge q     in elementary charges, e
  mass m       in electron masses, m_e
 */

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