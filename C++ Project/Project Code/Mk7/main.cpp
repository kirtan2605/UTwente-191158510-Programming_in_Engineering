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
#include <math.h>
#include "typeinfo"

#include "LUDecomp.h"
#include "solve.h"

using namespace std;

// creating a template class to store solution variables
template <typename T>
class Variable
{
public:
        string Name;
        T Value;

        Variable(string name, T value)
        {
                Name = name;
                Value = value;
        }
};


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


        // declaring variables for 4 variable system of equations to demonstrate implementation of Classes
        // thus assuming n = 4 for this snippet
        // currently all values of solution are saved as float, even if they are integers (4.0, 3.0 etc)
        // to implement Templates (Class Templates), I will now convert the integer solutions and save them in 'int'
        // The Class Template is used to save the integer solutions as 'int', and the others as 'float' as before

        for(i = 0; i < 4; i++)
        {
                float soln_val = *(Soln_X+i);
                int absolute_val = abs(soln_val);
                if (soln_val == absolute_val)
                {       
                        *(Soln_X+i)=absolute_val;
                }
        }

        Variable var1("a",*(Soln_X));
        Variable var2("b",*(Soln_X + 1));
        Variable var3("c",*(Soln_X + 2));
        Variable var4("d",*(Soln_X + 3));

        // printing the system of equations

        cout << "Solution to the System of Equations is" << endl;
        cout << " Type: "<< typeid(var1.Value).name() << "      Variable : " << var1.Name << " = " << var1.Value << endl;
        cout << " Type: "<< typeid(var2.Value).name() << "      Variable : " << var2.Name << " = " << var2.Value << endl;
        cout << " Type: "<< typeid(var3.Value).name() << "      Variable : " << var3.Name << " = " << var3.Value << endl;
        cout << " Type: "<< typeid(var4.Value).name() << "      Variable : " << var4.Name << " = " << var4.Value << endl;

        return 0;
}
