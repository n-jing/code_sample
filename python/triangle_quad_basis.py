from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
X = np.arange(0, 1, 0.01)
Y = np.arange(0, 1, 0.01)
X, Y = np.meshgrid(X, Y)
R = 1 - X - Y
# Z = np.exp(R) / (np.exp(X)+np.exp(Y)+np.exp(R))

################fig 1######################
ax = fig.add_subplot(1, 3, 1, projection='3d')
Z = (X**2) / (X**2+Y**2+R**2)
Z[X+Y>1.] = np.nan  # the diagonal slice
P = 0*R
P[X+Y>1.] = np.nan  # the diagonal slice
surf = ax.plot_surface(X, Y, P, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=1, antialiased=False, vmin=-1, vmax=1)
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=0, antialiased=False, vmin=0, vmax=1)
ax.set_zlim(0, 1.0)

# ax.zaxis.set_major_locator(LinearLocator(10))
# ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

# fig.colorbar(surf, shrink=0.5, aspect=5)
ax.grid(False)
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
plt.axis('off')
################fig 2######################
ax = fig.add_subplot(1, 3, 2, projection='3d')
Z = (Y**2) / (X**2+Y**2+R**2)
Z[X+Y>1.] = np.nan  # the diagonal slice
P = 0*R
P[X+Y>1.] = np.nan  # the diagonal slice
surf = ax.plot_surface(X, Y, P, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=1, antialiased=False, vmin=-1, vmax=1)
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=0, antialiased=False, vmin=0, vmax=1)
ax.set_zlim(0, 1.0)

# ax.zaxis.set_major_locator(LinearLocator(10))
# ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

# fig.colorbar(surf, shrink=0.5, aspect=5)
ax.grid(False)
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
plt.axis('off')
################fig 3######################
ax = fig.add_subplot(1, 3, 3, projection='3d')
Z = (R**2) / (X**2+Y**2+R**2)
Z[X+Y>1.] = np.nan  # the diagonal slice
P = 0*R
P[X+Y>1.] = np.nan  # the diagonal slice
surf = ax.plot_surface(X, Y, P, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=1, antialiased=False, vmin=-1, vmax=1)
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, rstride=1, cstride=1,
                       linewidth=0, antialiased=False, vmin=0, vmax=1)
ax.set_zlim(0, 1.0)

# ax.zaxis.set_major_locator(LinearLocator(10))
# ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

# fig.colorbar(surf, shrink=0.5, aspect=5)
ax.grid(False)
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
plt.axis('off')


plt.show()
