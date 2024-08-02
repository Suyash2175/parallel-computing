#include<stdio.h>
#include<mpi.h>
void main(int argc, char **argv)
{
int rank;
int size;
int global_sum = 0;
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
MPI_Init(&argc, &argv);//communication word will be created
MPI_Comm_rank(MPI_COMM_WORLD, &rank);//process id..
MPI_Comm_size(MPI_COMM_WORLD, &size);//no of process
if(rank==0){
//
 
int sum=0;
for(int i=0;i<=2;i++){
sum+=arr[i];
}
printf("sum0: %d\n",sum);
//total sum...
global_sum = sum;
for( int i  = 1  ; i < size ; i++)
{
int temp = 0;
MPI_Recv(&temp ,1 ,MPI_INT  , i , 0 , MPI_COMM_WORLD,MPI_STATUS_IGNORE);
global_sum += temp;
}
printf("Sum of all no. %d\n",global_sum);
}

if(rank==1){
int sum=0;
for(int i=3;i<=5;i++){
sum+=arr[i];
}
printf("sum1: %d\n",sum);
MPI_Send(&sum, 1, MPI_INT,0,0,MPI_COMM_WORLD);
}


if(rank==2){
int sum=0;
for(int i=6;i<=8;i++){
sum+=arr[i];
}
printf("sum2: %d\n",sum);
MPI_Send(&sum, 1, MPI_INT,0,0,MPI_COMM_WORLD);
}

if(rank==3){
int sum=0;
for(int i=9;i<=11;i++){
sum+=arr[i];
}
printf("sum3: %d\n",sum);
MPI_Send(&sum, 1, MPI_INT,0,0,MPI_COMM_WORLD);
}


MPI_Finalize();//terminates..
}

