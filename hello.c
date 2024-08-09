#include<mpi.h>
#include<stdio.h>
void main(int argc,char **argv)
{ 
int rank;
int size;
MPI_Init(&argc, &argv);// communication word will be created
MPI_Comm_rank(MPI_COMM_WORLD, &rank);//process id...
MPI_Comm_size(MPI_COMM_WORLD, &size);//no. of process
printf(" I am printed %d out of %d \n", rank,size);
MPI_Finalize();// terminates
}
