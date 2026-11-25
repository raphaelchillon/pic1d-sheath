# Notes about the sheath project (Draft)

## Objectives

This project aims to observe the evolution of the sheath, created on a grounded wall, due to a bounded plasma. Thus, I intend to measure it's size and evolution on a said timescale. 

### System

The system consist in a line where particles can travel onto, expanding on the x-axis from x=0 to x=L. It is bounded by a absorbing and grounded wall. 
The division of the system will be done on a constant step $\Delta x$.

## Model 

This project is based on a few assumptions: 

- [1] The plasma is a collisionless medium, where the average density of electron & ions does not exceed a certain value. This is true in low density plasma, such as electric propulsion as long as $\lambda_{mfp} >> L$, where $\lambda_{mfp}$ is the mean free path, which is the case in electric propulsion (to be checked for the target plasma).

- [2] There is no magnetic field. No external magnetic field is applied, and the plasma cannot generate one in this geometry. All quantities depend on x only, and particles move along $x$ only, so the current density has an x component only: $J_y = J_z = 0$. Since $\nabla \cdot \vec{B} = 0$ gives $\partial_x B_x = 0$, $B_x$ is uniform. 
In one dimension, $\nabla \times \vec{B} = (0, -\partial_x B_z, \partial_x B_y)$, and the $y$ and $z$ components of Ampère's law give $\partial_x B_z = \partial_x B_y = 0$,because $J_y$, $J_z$, $E_y$ and $E_z$ are all zero. $\vec{B}$ is therefore uniform, equal to the applied field, that is zero. 
The model is exactly electrostatic. 

- [3] We assume that a particle touching the wall diseappears : if it's an electron, it goes into the ground and if it's an ion, it catches an electron and recombinate to get back into the plasma. Because our model is not focusing on neutral particles, we consider the ion deleted. 

- [4] We neglect any type of secondary emissions and mirror effect that could send back low-energy electrons from the wall into the plasma.

Because of assumption 1, we are not allowing any ionization. Thus, we need another assumption to inject ions & electrons otherwise the plasma will not be sustained. At the equilibrium, the losses from the walls are equals to the gains due to ionization. Due to various normalisation caracterics being dependent to the electron density (Debye length, plasma frequency,...), we will keep the total number of electron constant. Thus : 

- [5] For each electron lost in the walls, a pair will be created at the center of the system, far from the walls, to describe the ionization process. However if a ion touches the walls, we remove it as the creation of another pair would just result in the infinite augmentation of the particles density, which is not possible. 

- [6] For each pair created, the electrons will have a designated velocity chosen randomly according to a gaussian curve. (Open Question: are there any other possibilities to do that ? )




### Equations 

To describe the evolutions of particle, we will use Lorentz's equation on a electrostatic environment (B is neglected due to assumption n.2): $m  \frac{d\vec{v}}{dt} = q\vec{E}$ 

For electrons : $m_e  \frac{d\vec{v_{e}}}{dt} = -e\vec{E}$

For ions : $m_i  \frac{d\vec{v_{i}}}{dt} = +e\vec{E}$

Using the Gauss equation and E = - $\frac{d\phi}{dx}$, we arrive to : $\frac{\partial^{2}\phi(x,t)}{\partial^2x} = -\frac{\rho(x,t)}{\epsilon_0}$ with $\rho = e(n_i - n_e)$

The system is a second order differential equation with two conditions : $\phi(0) = \phi(L) = 0$



## Scales & Normalized values

To write our equations simplier, we can use multiple values to normalize our equations. Thus, let's us : 

- The Debye scale $\lambda_D$. This is the minimum length value the plasmas needs in order to "screen off" a charge differential inside the plasma. To get its expression, we use the boltzmann distribution on the electrons density coupled with the poisson equation. We then get $\lambda_D = \sqrt{\frac{\epsilon_0 k_b T_e}{n_0 e^2}}$. 


- The plasma frequency $\omega_p$. Let's imagine a plasma with an uniform density of electrons and ions and let's move a whole column of electron by a small quantity named $\delta_x$. The resulting potential caused by the density difference will create a electric field $\vec{E}$ that will push back the electrons. Using Newton's second law : 
$m_e \times \frac{d^2\delta_x}{dt^2} = -eE_x$ and Gauss's Theorem E = $\frac{n_0 \times e \times \delta_x}{\epsilon_0}$, we get $\frac{d^2\delta_x}{dt^2} + \underbrace{\frac{n_0 e^2}{m_e \epsilon_0}}_{\omega_p^2} \times \delta_x = 0$. The plasma frequency $\omega_p$ is just the frequency of electron's oscillations when displaced by a small position. 


- the thermal velocity $v_{th}$. Using a maxwellian distribution for the velocity distribution, it can be defined as the standard deviation, or the mean quadratic velocity of electrons. It is linked to $\lambda_D$ and $\omega_p$ : $v_{th}$ = $\lambda_D \times \omega_p$ = $\sqrt{\frac{k_b T_e}{m_e}}$

- the density $n_0$. Far from any disturbance, the electrons and the ions have an approximately uniform density due to the plasma properties. This density will be used as a normalization value. 

- e and m_e for the charges and the masses. 


### Normalizing our equations 

We will be fully using the values above. 


Thus, we will from now on, use : 

- $\frac{x}{\lambda_D}$ for the position of particles ; named $\xi$. 

- $\frac{v}{v_{th}}$ for the velocity of particles ; named u. 

- $t \times \omega_p$ for the timescale ; named $\tau$. 

- $\frac{n}{n_0}$ for the density of particles ; named $N_{specie}$. 

- $\frac{q}{e}$ & $\frac{m}{m_e}$ for the charge and mass of particles. 



Furthermore, for the potential, we will be using $\frac{\Phi}{k_b T_e/e}$. Indeed, using poisson : $\frac{d^2\phi}{dx^2} = -e \times \frac{(n_i - n_e)}{\epsilon_0}$, we get $\frac{d^2}{d\xi^2} \left( \frac{\phi}{k_b T_e/e} \right) = N_e - N_i$



This allows us to have Newton's equation rewritten as $\frac{du}{d\tau} = \frac{\tilde{q}}{\tilde{m}} \times \frac{E}{E_0}$ where $E_0 = \frac{k_b T_e}{e \lambda_D}$. 


> [!NOTE]
> From now on, we drop the normalization notation: $x$, $v$, $t$, $E$ and $\phi$
> denote the normalized quantities $\xi$, $u$, $\tau$, $E/E_0$ and $e\phi/(k_B T_e)$.






