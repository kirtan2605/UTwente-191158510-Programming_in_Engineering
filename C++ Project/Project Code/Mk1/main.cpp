/***********************************
Purpose : Solving System of Linear Equations using LU Decomposition
Authors : Kirtan Patel(s2935848)
Date    : 02/04/2022
Input   : Data File
Output  : Values of Variables
*************************************/

/******
 This code takes the Augmented Matrix as the input [A|B], and solves for x in the equation A.x = B 
 n is the size of the matrix A : nXn.
 ****/

/***
argc : saves the number of arguements input by the user in the command line
argv : saves the arguements input by the user in the command line
d
h[],b[],v[],u[],k[]: Arrays used in calculation of LU Decomposition
mat[][]: Stores the Matrix to be decomposed
ro
e_squared : stores the value of squared error
i,j,row,column: loop variables
ctr1,ctr2,m : control variables used for LU decomposition
Y[] : Used to store (U*K) in the L*U*K=u
Q[] : temporary array  used to store values of k[]
mul[] : array used in LU Decomposition
uppertriangle[][] : stores the upper triangular matrix
lowertriangle[][] : stores the lower triangular matrix
***/

/***** Usage : Compile using 'g++ main.cpp -lm -o SysEqnSolver ' ********/
/***** Usage : enter "./SysEqnSolver ~number_of_eqns~ " *****/


//Header files and initial declarations
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[])
{ 
        int i,j,k;

        std::ifstream fileIn("input.txt");

        if (!fileIn.is_open() ) 
        {
                std::cerr << "Cannot open file" << std::endl;
                std::exit(-1);
        }

        int n = atoi(argv[1]);

        // std::cout<< n <<std::endl;

        float A[n][n];
        float B[n][1];

        for (i = 0; i < n; i++) 
        {
                for (j = 0; j < n+1; j++) 
                {
                        if(j==n)
                        {
                                fileIn >> B[i][0];
                        }
                        else
                        {
                                fileIn >> A[i][j];
                        }

                }
        }


/**
        // Display matrix A

        for(int i = 0; i< n; i++)
        {
                for(int j = 0; j< n; j++)
                {
                        std::cout<<A[i][j]<<"   ";
                }

                std::cout<<std::endl;
        }
**/

/**

        // Display matrix B

        for(int i = 0; i< n; i++)
        {
                        std::cout<<B[i][0]<<std::endl;
        }
**/


        // LU Decomposition of mat[n-2][n-2] matrix

        int ctr1,ctr2;
        int row,column;

        // matrices for lower and uppper triangle
        float lowertriangle[n][n];
        float uppertriangle[n][n];

        
        for(row=0;row<n;row++)
        {       for(column=0;column<n;column++)
                {
                        if(row>column)          //initialise all elements of lower triangle in upper triangular matrix as 0
                                uppertriangle[row][column]=0.0;
                        if(row<column)          //initialise all elements of upper triangle in lower triangular matix as 0
                                lowertriangle[row][column]=0.0;
                        if(row==column)         //initialise all diagonal elements of lower triangular matrix as 1
                                lowertriangle[row][column]=1.0;
                }
        }

        ctr2 = 0;
        int m = 1;
        while(ctr2 < n)         //loop for LU decomposition of the matrix
        {       
                for(ctr1 = m; ctr1<n;ctr1++)
                {
                        float mul[n];
                        mul[ctr1] = A[ctr1][ctr2]/A[ctr2][ctr2];
                        lowertriangle[ctr1][ctr2] = mul[ctr1];
                        row = ctr1;
                        for(column = ctr2;column<n;column++)
                                A[row][column] = A[row][column] - mul[ctr1]*A[ctr2][column];
                }
                m++;
                ctr2++;
        }

        //UPPER TRIANGULAR MATRIX
        for(row=0;row<n;row++)
        {
        for(column=0;column<n;column++)
                        uppertriangle[row][column] = A[row][column];
        }


        std::cout<<""<<std::endl;
        std::cout<<"Upper-Triangular Matrix"<<std::endl;

        // Display upper-triangular matrix

        for(i = 0; i< n; i++)
        {
                for(j = 0; j< n; j++)
                {
                        std::cout<<uppertriangle[i][j]<<"   ";
                }

                std::cout<<std::endl;
        }

        std::cout<<""<<std::endl;
        std::cout<<"Lower-Triangular Matrix"<<std::endl;

        // Display lower-triangular matrix

        for(i = 0; i< n; i++)
        {
                for(j = 0; j< n; j++)
                {
                        std::cout<<lowertriangle[i][j]<<"   ";
                }

                std::cout<<std::endl;
        }





        // Verification of LU Decomposition

        float verify[n][n];

        cout<<"Verification Matrix :"<<endl;
        cout<<"\n";  

        for(i=0;i<n;i++)    
        {    
                for(j=0;j<n;j++)    
                {    
                        verify[i][j]=0;    
                        for(k=0;k<n;k++)    
                        {    
                                verify[i][j]+=lowertriangle[i][k]*uppertriangle[k][j];    
                        }    
                }    
        }

        //for printing result    
        
        for(i=0;i<n;i++)    
        {    
                for(j=0;j<n;j++)
                {    
                        cout<<verify[i][j]<<" ";    
                }    
                
                cout<<"\n";    
        }    


        cout<<"\n";  













/**

        //loops to find the constants of the cubicspline
        float Y[n];
        
        Y[0]=u[0]/lowertriangle[0][0];
        for(i=1; i<n-2; i++)
        {       Y[i]=u[i];
                for(int j=0;j<i;j++)
                        Y[i]=(Y[i]-(lowertriangle[i][j]*Y[j]));
                Y[i]=(Y[i]/lowertriangle[i][i]);
        }

        float Q[n-2]; //temporary matrix to avoid index confusion in k

        Q[n-3]=Y[n-3]/uppertriangle[n-3][n-3];
        for(i=n-3; i>=0; i--)
        {
        Q[i]= Y[i];
        for(j=i+1; j<=n-3; j++)
                        Q[i]=Q[i]-uppertriangle[i][j]*Q[j];

                Q[i] = Q[i]/uppertriangle[i][i];
        }

        for(i=0;i<=n-3;i++)
                k[i+1]=Q[i];
**/

        /**

        //CODE TO FIND Y_INTERPOLATED

        for(j=0;j<size;j++)
    {
                for(i =0; i < n;i++)
                {       
                if((x_ds[i] < x_true[j])&&(x_true[j] < x_ds[i+1]))
                {
                        y_interpolated[j] = (k[i]/6)*(((pow((x_true[j]-x_ds[i+1]),3))/(h[i])) - ((x_true[j]-x_ds[i+1])*h[i])) - (k[i+1]/6)*(((pow((x_true[j]-x_ds[i]),3))/(h[i])) - ((x_true[j]-x_ds[i])*h[i])) + (((y_ds[i]*(x_true[j]-x_ds[i+1]))-y_ds[i+1]*(x_true[j]-x_ds[i]))/h[i]);
                }
                }
        }


        ***/

        
        return 0;
}