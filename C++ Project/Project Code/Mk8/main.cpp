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
#include <iostream>
#include <fstream>
#include <math.h>
#include <typeinfo>

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




void Demo()
{
        // Demonstration of the working of Template Class

        cout << " " << endl;
        cout << "Demo Object Created to Show Class Template : initializing value as an integer" << endl;

        Variable var5("e",1);
        cout << " Type: "<< typeid(var5.Value).name() << "      Variable : " << var5.Name << " = " << var5.Value << endl;

        cout << " " << endl;
        cout << "Example Object Created to Show Class Template :  initializing value as a string" << endl;

        Variable var6("f","Value");
        cout << " Type: "<< typeid(var6.Value).name() << "      Variable : " << var6.Name << " = " << var6.Value << endl;

        delete var5;
        delete var6;
}




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
         *      Upper Triangular Matrix is what remains in A after the above LU Decomposition operations
         *      hence, we can just use the uppertriangle pointer to initially point to A
         *      After the LU decomposition, A transforms into an uppertriangle matrix, and hence the pointer is valid
         *      this is useful when the size of A starts increasing
         *      it is better to use a pointer, instead of creating a copy, which is an inefficient use of memory
         ***/


        float lowertriangle[n][n];
        
        float *uppertriangle_ptr,*lowertriangle_ptr,*B_ptr;

        lowertriangle_ptr = (float*)lowertriangle;
        uppertriangle_ptr = (float*)A;
        B_ptr = (float*)B;

        LUDecomposition(uppertriangle_ptr,lowertriangle_ptr,n);

        float* Soln_X = Solve_LU_x_B(uppertriangle_ptr,lowertriangle_ptr,B_ptr,n);


        /**
         *      declaring variables for 4 variable system of equations to demonstrate implementation of Classes
         *      thus assuming n = 4 for this snippet
         *      currently all values of solution are saved as float, even if they are integers (4.0, 3.0 etc)
         *      to implement Templates (Class Templates), I will now convert the integer solutions and save them in 'int'
         *      The Class Template is used to save the integer solutions as 'int', and the others as 'float' as before
        **/

        int Soln_X_int[4][1];

        for(i = 0; i < 4; i++)
        {
                float soln_val = *(Soln_X+i);
                int floor_val = floor(soln_val);
                if (soln_val - floor_val == 0)
                {       
                        Soln_X_int[i][0] = (int)(soln_val);
                }
        }


        /**
        for(i = 0; i < 4; i++)
        {
                cout << Soln_X_int[i][0] << endl;
        }
        **/

        Variable var1("a",((*(Soln_X) - floor(*(Soln_X)) == 0)? (int)(*(Soln_X)): *(Soln_X)));
        Variable var2("b",((*(Soln_X+1) - floor(*(Soln_X+1)) == 0)? (int)(*(Soln_X+1)): *(Soln_X+1)));
        Variable var3("c",((*(Soln_X+2) - floor(*(Soln_X+2)) == 0)? (int)(*(Soln_X+2)): *(Soln_X+2)));
        Variable var4("d",((*(Soln_X+3) - floor(*(Soln_X+3)) == 0)? (int)(*(Soln_X+3)): *(Soln_X+3)));

        /**
         *      Initially, the idea of the ternary operator was to initialize different Variable class objects with different dataypes.
         *      But the object is always created with datatype 'float', even though it is an integer (after explicit typecasting)
         *      This is because : 
         *  
         *      For a Ternary Operator with the following form : exp1 ? exp2 : exp3
         *      It is another interesting fact. The ternary operator has return type. 
         *      The return type depends on exp2, and convertibility of exp3 into exp2 as per usual\overloaded conversion rules. 
         *      If they are not convertible, the compiler throws an error.
         *      
         *      Source : https://www.geeksforgeeks.org/cc-ternary-operator-some-interesting-observations/
        **/

        // printing the solutions to the system of equations

        cout << "Solution to the System of Equations is" << endl;
        cout << "      Variable : " << var1.Name << " = " << var1.Value << endl;
        cout << "      Variable : " << var2.Name << " = " << var2.Value << endl;
        cout << "      Variable : " << var3.Name << " = " << var3.Value << endl;
        cout << "      Variable : " << var4.Name << " = " << var4.Value << endl;

        /**

        cout << "Solution to the System of Equations is" << endl;
        cout << " Type: "<< typeid(var1.Value).name() << "      Variable : " << var1.Name << " = " << var1.Value << endl;
        cout << " Type: "<< typeid(var2.Value).name() << "      Variable : " << var2.Name << " = " << var2.Value << endl;
        cout << " Type: "<< typeid(var3.Value).name() << "      Variable : " << var3.Name << " = " << var3.Value << endl;
        cout << " Type: "<< typeid(var4.Value).name() << "      Variable : " << var4.Name << " = " << var4.Value << endl;

        **/


        // freeing objects after they have been used
        delete var1;
        delete var2;
        delete var3;
        delete var4;

        return 0;
}
