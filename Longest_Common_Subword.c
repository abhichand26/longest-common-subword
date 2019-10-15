#include<stdio.h>
#include<string.h>
#define N 20
#define inf 9999

/*
** Program to find longest common sub-words using Dynamic Programming
** Made by - Abhishek Chand
*/

int L[N][N];
char X[N],Y[N],tempX[N],tempY[N];

void printLCW(int i, int j)
{
	if(L[i][j]==0)
		return;
	printLCW(i-1,j-1);
	printf("%c",X[i]);
}

void LCW(int m, int n)
{
	int i,j,maxl,maxi,maxj;
	maxl=maxi=maxj=0;
	for(j=0;j<=n;j++)
		L[0][j]=0;
	for(i=1;i<=m;i++)
		L[i][0]=0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i]==Y[j])
				L[i][j]=1+L[i-1][j-1];
			else
				L[i][j]=0;
			
			if(L[i][j]>maxl)
			{
				maxl=L[i][j];
				maxi=i;
				maxj=j;
			}
		}
	}
	printf("\nLongest Common Word of length %d is ",maxl);
	printLCW(maxi,maxj);
}

int main()
{
	int i,m,n;
	
	printf("Enter 1st String: ");
	gets(tempX);
	m=strlen(tempX);
	
	printf("Enter 2nd String: ");
	gets(tempY);
	n=strlen(tempY);
	
	for(i=1;i<=m;i++)
	{
		X[i]=tempX[i-1];
	}
		
	for(i=1;i<=n;i++)
	{
		Y[i]=tempY[i-1];
	}
	
	LCW(m,n);
	return 0;
}
