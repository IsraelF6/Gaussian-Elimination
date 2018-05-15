#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void residual(int n, double A[20][21], double x[20])
{
	double b[20];
	double r[20];
	double AX[20];
	for (int i=0; i<n; i++)
	{
		b[i]=A[i][n];
		AX[i]=0;
		for (int j=0; j<n; j++)
			AX[i] = AX[i] + A[i][j] * x[j];
		r[i] = b[i] - AX[i];
	}

	cout << "r = ( ";
	for (int i=0; i<n; i++)
		cout << r[i] << " ";
	cout << ")" << endl;
}


void gauss(int n, double A[20][21], double x[20]) 
{
   double temp;
	
	for (int i=0; i<n; i++) 
	{
        // Search for maximum in this column
        double maxElement = abs(A[i][i]);
        int maxRow = i;

		for (int p=i+1; p<n; p++) 
		{			
			if (abs(A[p][i]) > maxElement) 
			{
                maxElement = abs(A[p][i]);
                maxRow = p;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<=n;k++) 
		{
            temp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = temp;
        }

        // Make all rows below this one 0 in current column
        for (int j=i+1; j<n; j++) 
		{
            double multiplier = A[j][i] / A[i][i];
            
			for (int k=i; k<n+1; k++) 
			{
                if (i==k)
                    A[j][k] = 0;
                else
                    A[j][k] = A[j][k] - (multiplier * A[i][k]);
            }
        }
    }

    // Solves equation 
	
    for (int i=n-1; i>=0; i--) 
	{
       temp = A[i][n]; 
		
	   for (int j=n-1; j>i; j--)
			temp = temp - (A[i][j] * x[j]);
    
		x[i] = temp / A[i][i];
	}

}

int main() 
{
	int n=5;

    double A[20][21];
	double G[20][21];   
	double x[20];
	

	//from exercise #1
    /* 
    A[0][0] = 4; 
    A[0][1] = -1; 
    A[0][2] = 1; 
    A[0][3] = 8;
 
    A[1][0] = 2; 
    A[1][1] = 5; 
    A[1][2] = 2; 
    A[1][3] = 3; 
 
    A[2][0] = 1; 
    A[2][1] = 2; 
    A[2][2] = 4; 
    A[2][3] = 11; 
	
	*/
	//tridiagonal 
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
		if (i==j)
			A[i][j] = 4;
		if (j==i+1 || j==i-1)
			A[i][j] = -1;
		if (j!=i && j!=i+1 && j!=i-1) 
			A[i][j] = 0;
		}
	}
		
	for (int i=0; i<n; i++)
	{
		if (i%2 == 1)
		A[i][n] = 0;
		if (i%2 == 0)
		A[i][n] = 1;
	}
	
	for (int i=0; i<n; i++) 
	{      
		for (int j=0; j<=n; j++)
		G[i][j] = A[i][j];
	}
    

	//call for gaussian funcion
	gauss(n,G,x);

    cout << "x = ( ";
	for (int i=0; i<n; i++) 
        cout << x[i] << " "; 
	cout << ")" << endl;

	//call for residual function
	residual(n,A,x);

	return 0;
}