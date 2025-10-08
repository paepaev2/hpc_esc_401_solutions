import matplotlib.pyplot as plt

cpus = [1, 2, 4, 8, 16]
times = [1.126, 0.8896, 0.4831, 0.387, 0.3374]

speedup = [times[0]/t for t in times]

plt.plot(cpus, speedup, marker='o')
plt.xlabel('Number of CPUs')
plt.ylabel('Speedup')
plt.title('Speedup of sum_parallel')
plt.savefig('plot_speedup.png')
