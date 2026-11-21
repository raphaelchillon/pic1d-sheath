"""Plots of the pusher in uniform electrostatic field"""
import numpy as np
import matplotlib.pyplot as plt

t, x_th, x, diff = np.loadtxt("output/uniform.txt", unpack=True)

fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True, figsize=(7, 6))

ax1.plot(t, x_th, "-", label="exact solution")
ax1.plot(t, x, "o", markersize=3, label="leapfrog")
ax1.set_ylabel("position x ")
ax1.legend()

ax2.plot(t, diff, ".-")
ax2.set_xlabel("time t")
ax2.set_ylabel("x_th − x")

fig.tight_layout()
fig.savefig("output/uniform.png", dpi=150)
print("Saved in output/uniform.png")