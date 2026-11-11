# Notes about the sheath project (Draft)

## Objectives

This project aims to observe the evolution of the sheath, created on a grounded wall, due to a bounded plasma. Thus, I intend to measure it's size and evolution on a said timescale. 

### System

The system consist in a line where particles can travel onto, expanding on the x-axis from x=0 to x=L. It is bounded by a absorbing and grounded wall. 
The division of the system will be done on a constant space named $\Delta x$

## Model 

This project is based on a few assumptions: 

- [1] The plasma is a collisionless medium, where the average density of electron & ions does not exceed a certain value. (to check : no = 1e13 m^-3) This is true in low density plasma, such as electric propulsion.

- [2] We will neglect the creation of currents inside the plasma due to the displacement of electrons. We stay on a basic simulation. 

- [3] We assume that a particle touching the wall diseappears : if it's an electron, it goes into the "mass" and if it's an ion, it catches an electron and recombinate to get back into the plasma. Because our model is not focusing on neutral particles, we consider the ion deleted. 

- [4] We neglect any type of secondary emissions & mirror effect that could send back low-energy electrons into the plasma


### Equations 

To describe the evolutions of particle, we will use Lorentz's equation on a electrostatic environment (B is neglected due to assumption n.2): $ m  \frac{d\vec{v}}{dt} = qE  $ 



## Scales & Normalized values

in progress 

