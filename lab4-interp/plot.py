import numpy as np
import matplotlib.pyplot as plt

data=np.genfromtxt('interpolacao.csv', delimiter=',')

plt.plot(data[0], label='funcao real')
plt.plot(data[1], label='regular')
plt.plot(data[2], label='chebyshev')
plt.legend()
plt.show()