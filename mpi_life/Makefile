
life.bin:
	mpicc life.c -o life.bin


run: life.bin
	mpiexec -n 2 ./life.bin -machinefile hosts



