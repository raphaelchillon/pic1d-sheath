"""Plots of the pusher in harmonic electrostatic field"""
import numpy as np
import matplotlib.pyplot as plt

t, x_1, x_th1, W_1, W_th1, x_2, x_th2, W_2, W_th2, x_3, x_th3, W_3, W_th3 = np.loadtxt("output/harmonic.txt", unpack=True) 
fig, (ax1, ax2, ax3, ax4,ax5,ax6) = plt.subplots(6, 1, sharex=True, figsize=(8, 14))

ax1.plot(t, x_th1, "-", label="exact solution of particle 1")
ax1.plot(t, x_1, "-", markersize=3, label="leapfrog of particle 1")
ax1.set_ylabel("position x/λ_D")
ax1.legend()

ax2.plot(t, x_th2, "-", label="exact solution of particle 2")
ax2.plot(t, x_2, "-", markersize=3, label="leapfrog of particle 2")
ax2.set_ylabel("position x/λ_D")
ax2.legend()

ax3.plot(t, x_th3, "-", label="exact solution of particle 3")
ax3.plot(t, x_3, "-", markersize=3, label="leapfrog of particle 3")
ax3.set_ylabel("position x/λ_D")
ax3.legend()

ax4.plot(t, W_th1, "-", label="exact solution of particle 1")
ax4.plot(t, W_1, "-", markersize=3, label="leapfrog of particle 1")
ax4.set_ylabel("Energy W")
ax4.legend()

ax5.plot(t, W_th2, "-", label="exact solution of particle 2")
ax5.plot(t, W_2, "-", markersize=3, label="leapfrog of particle 2")
ax5.set_ylabel("Energy W")
ax5.legend()

ax6.plot(t, W_th3, "-", label="exact solution of particle 3")
ax6.plot(t, W_3, "-", markersize=3, label="leapfrog of particle 3")
ax6.set_ylabel("Energy W")
ax6.legend()

fig.tight_layout()
fig.savefig("output/harmonic.png", dpi=150)
print("Saved in output/harmonic.png")