#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
int arr[100][100];
int A[100][100] = { 0 };
int pathdir[100];
int pathdirresult[100];
int X[4] = { -1,1,0,0};
int Y[4] = { 0,0,-1,1};
int count = 0;
int a,b,M,N;
int max=1;
int show(int arr[100][100]) 
{
	printf("\n");
	for( int i=1;i<=M;i++)
	{ 
		for (int j=1;j<=N;j++)
		{
			printf("%d ",arr[i][j]);
		};
		printf("\n");
	};
}
int showpathdir(int arr[100],int counts) 
{
	printf("\n");
		for (int i=1;i<=count;i++)
		{
			printf("%d ",arr[i]);
		};
		

}
void checkdir(int x, int y,int count)
{
		if( x==-1 && y==0 ) pathdir[count]=4;
		if( x==1 && y==0 ) pathdir[count]=3;
		if( x==0 && y==1 ) pathdir[count]=1;
		if(x==0 && y==-1 ) pathdir[count]=2;
}
void showdir(int pathdir[100])
{
	int dir;
	for( int i=0; i < max ;i++) 
	{ dir = pathdir[i];
	
	if (pathdir[i] == 1) printf("D");
	if (pathdir[i] == 2)  printf("T");
	if (pathdir[i] == 3)   printf("N");
	if (pathdir[i] == 4) 	printf("B");
	}
}	
void path(int x, int y) {
	
    ++count;
    A[x][y] = 1;
   	for ( int i=0; i<4;i ++ )
		{   
        int u = x + X[i];
        int v = y + Y[i];
        printf(" (%d, %d) arr=%d, a=%d\n ",u,v,arr[u][v],A[u][v]);
        if (u > 0 && u <= N && v > 0 && v <= N && A[u][v] == 0 && arr[u][v] == 0 && fabs( X[i])+fabs( Y[i]) == 1 )
        {
//        	printf(" (%d, %d) arr=%d, a=%d\n ",u,v,arr[u][v],A[u][v]);
			checkdir(X[i],Y[i],count);
			path(u, v);
			
//			
		} 
		printf("\n ------------- %d ",count)  ;
    	}
    if (count > max) 
	{
		max = count;
		showpathdir(pathdir,count);
		showdir(pathdir);
		show(A);
		for(int i=0;i<max;i++)
		{
			pathdirresult[i]=pathdir[i];
		}
	 }
	  
    --count;
   
    
    A[x][y] = 0;
}
int main() {
	FILE *f ;
	f= fopen("input.txt","r");
	fscanf(f,"%d",&M);
	fscanf(f,"%d",&N);	
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	printf("\n %d %d %d %d ", M, N, b, a);
	for( int i=1;i<=M;i++)
	{ 
		for (int j=1;j<=N;j++)
		{
			fscanf(f,"%d",&arr[i][j]);
		};
		printf("\n");
	};
	fclose(f);
	show(arr);
	if (arr[a][b] == 1 )
	{
		printf("%d",arr[a][b]);
		printf(" \n Robot duoc dua vao vi tri da co cay trong !");
		return 0;
	};
	show(arr);
    path(a,b);
    showpathdir(pathdir,count);
	showdir(pathdirresult);
    printf("\n so cay trong duoc nhieu nhat la = %d",max);
    printf( "Khong tim thay duong di.");
}
