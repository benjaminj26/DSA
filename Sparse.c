/*
	Program to implement sparse matrix in C
	Author : Benjamin Joseph
	Date : 12-12-2021
*/

#include<stdio.h>

int main()
{
	int row,col,z_count=0;
	printf("Input the number of rows and columns: ");
	scanf("%d %d", &row, &col);
	int arr[row][col];
	printf("Enter %d elements:\n",row*col);
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j] != 0)
				z_count++;
		}
	}
	int sparse[z_count][3];
	int k=0;
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			if(arr[i][j] != 0)
			{
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = arr[i][j];
				k++;
			}
		}
	}
	printf("Sparse matrix representation is:\n%d  %d  %d\n", row, col, z_count);
	for(int i=0; i<z_count; ++i)
	{
		printf("%d  %d  %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
	}
	return 0;
}
