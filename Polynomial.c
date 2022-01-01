/*
	Program to represent a polynomial in C
	Author : Benjamin Joseph
	Date : 13-12-2021
*/

#include<stdio.h>

int main()
{
	int deg;
	printf("Enter the highest degree: ");
	scanf("%d", &deg);
	int polynomial[deg+1];
	for(int i=deg; i>=0; --i)
	{
		printf("Input the power of x^%d: ",i);
		scanf("%d",&polynomial[i]);
	}
	printf("The polynomial you entered is:\n");
	for(int i=deg; i>=0; --i)
	{
		if(i>0)
			printf("%dx^%d + ",polynomial[i],i);
		else
			printf("%dx^%d",polynomial[i],i);
	}
	printf("\n");
	return 0;
}
