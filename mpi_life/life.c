#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mpi.h"

int main(int argc, char **argv)
{
  int myid, namelen, i;
  char computer_name[512]; // computer name
  int a[2];
  
  srandom(time(NULL));
  MPI_Status status;
  MPI_Init(&argc, &argv); 
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // my id
  
  MPI_Get_processor_name(computer_name, &namelen); // my name

  if (myid == 0) { // the main process
    a[0] = random();  
    MPI_Send(a, 1, MPI_INT, 1, 12, MPI_COMM_WORLD);
    fprintf(stderr, "Proces %d on %s says: %d\n",  myid, computer_name, a[0]);
  } else { // other process(es)
    MPI_Recv(a, 1, MPI_INT, 0, 12, MPI_COMM_WORLD, &status);
    a[0] += 1;
    fprintf(stderr, "Proces %d on %s says: %d\n",  myid, computer_name, a[0]);
  }
  
  MPI_Finalize();
  return 0;
}

