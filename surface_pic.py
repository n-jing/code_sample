#! /usr/bin/python3

import math
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

fig = plt.figure(figsize=(40,30))  #定义新的三维坐标轴
ax3 = plt.axes(projection='3d')
ax3._axis3don = False

#定义三维数据
xx = np.arange(-20,20,0.2)
yy = np.arange(-20,20,0.2)
X, Y = np.meshgrid(xx, yy)#将两个一维数组变为二维矩阵
Z = -X*X - Y*Y + 11*11

xxp = np.arange(-10,10, 19)
yyp = np.arange(-10,10, 19)
XP, YP = np.meshgrid(xxp, yyp)#将两个一维数组变为二维矩阵
ZP = 11*11 + 0*XP*XP - 0*YP*YP

#作图
#ax3.plot_surface(X,Y,Z,rstride = 1, cstride = 1)

ax3.plot_wireframe(X, Y, Z, rstride=1, cstride=1, color='deepskyblue', alpha=0.001)
ax3.plot_surface(X,Y,Z,rstride = 1, cstride = 1,color='deepskyblue', alpha=0.6) 
ax3.plot_surface(XP,YP,ZP,rstride = 1, cstride = 1,color='turquoise', alpha=0.75, linewidth=0, antialiased=False)
# ax3.quiver(0, 0, 11*11+10, 0, 0, 10)

plt.savefig('1.png',dpi=80)
plt.show()
