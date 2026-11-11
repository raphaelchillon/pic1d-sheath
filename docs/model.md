# Notes about the sheath project (Draft)

## Objectives

This project aims to observe the evolution of the sheath, created on a grounded wall, due to a bounded plasma. Thus, I intend to measure it's size and evolution on a said timescale. 

### System

The system consist in a line where particles can travel onto, expanding on the x-axis from x=0 to x=L. It is bounded by a absorbing and grounded wall. 
The division of the system will be done on a constant step $\Delta x$.

## Model 

This project is based on a few assumptions: 

- [1] The plasma is a collisionless medium, where the average density of electron & ions does not exceed a certain value. (to check : no = 1e13 m^-3) This is true in low density plasma, such as electric propulsion.

- [2] We will neglect the creation of currents inside the plasma due to the displacement of electrons. We stay on a rather simple simulation at first.

- [3] We assume that a particle touching the wall diseappears : if it's an electron, it goes into the "mass" and if it's an ion, it catches an electron and recombinate to get back into the plasma. Because our model is not focusing on neutral particles, we consider the ion deleted. 

- [4] We neglect any type of secondary emissions and mirror effect that could send back low-energy electrons into the plasma.

Because of assumpt. 4 & 1, we are not allowing any ionization. Thus, we need another assumption to inject ions & electrons otherwise the plasma will not be sustained. At the equilibrium, the losses from the walls are equals to the gains due to ionization. Due to various normalisation caracterics being dependent to the electron density (Debye length, plasma frequency,...), we will keep the total number of electron constant. Thus : 

- [5] For each electron lost in the walls, a pair will be created at the center of the system, far from the walls, to describe the ionization process. However if a ion touches the wall, we remove it as the creation of another pair would just result in the infinite augmentation of the plasma's potential, which is not possible. 

- [6] For each pair created, the electrons will have a designated velocity chosen randomly according to a gaussian curve. (Open Question: are there any other possibilities to do that ? )


Open question : 

- Macro particles due to particle-in-cell simulation -> What are they representing? 


### Equations 

To describe the evolutions of particle, we will use Lorentz's equation on a electrostatic environment (B is neglected due to assumption n.2): $ m  \frac{d\vec{v}}{dt} = qE  $ 



## Scales & Normalized values

in progress 

