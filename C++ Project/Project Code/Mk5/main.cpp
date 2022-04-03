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
uppertriangle[][] : stores the upper triangular matrix
lowertriangle[][] : stores the lower triangular matrix
***/

/***** Usage : Compile using 'g++ main.cpp -lm -o SysEqnSolver ' ********/
/***** Usage : enter "./SysEqnSolver ~number_of_eqns~ " *****/


//Header files and initial declarations
#include "iostream"
#include "fstream"

#include "LUDecomp.h"
#include "solve.h"

using namespace std;


int main(int argc,char *argv[])
{ 
        int i,j,k;

        // Reading Augmented Matrix from the Input File (in the same directory)

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


        /***
                Upper Triangular Matrix is what remains in A after the above LU Decomposition operations
                hence, we can just use the uppertriangle pointer to initially point to A
                After the LU decomposition, A transforms into an uppertriangle matrix, and hence the pointer is valid
                this is useful when the size of A starts increasing
                it is better to use a pointer, instead of creating a copy, which is an inefficient use of memory
         ***/


        float lowertriangle[n][n];
        
        float *uppertriangle_ptr,*lowertriangle_ptr,*B_ptr;

        lowertriangle_ptr = (float*)lowertriangle;
        uppertriangle_ptr = (float*)A;
        B_ptr = (float*)B;

        LUDecomposition(uppertriangle_ptr,lowertriangle_ptr,n);

        float* Soln_X = Solve_LU_x_B(uppertriangle_ptr,lowertriangle_ptr,B_ptr,n);
        
        for(i = 0; i < n; i++)
        {
                cout<< *(Soln_X + i) << endl;
        }
        
        return 0;
}