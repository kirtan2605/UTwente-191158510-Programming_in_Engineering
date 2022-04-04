// Function to solve for solution array x, after LU Decomposition

float* Solve_LU_x_B(float * uppertriangle_ptr,float * lowertriangle_ptr,float * B, int n)
{
        int i,j;

        /**

                After the LU Decomposition, our system of equations, 
                the matrix      A.x = B   transforms into       L.U.x = B
                To find x, 
                1. we first use forward-substitution (from top to bottom) from L and B to find Y such that U.x = Y
                2. we then use backward-substitution (from bottom to top) from U and Y to find x.
         
        **/

        float Y[n];
        
        Y[0]=(*(B+0))/(*(lowertriangle_ptr+0*n+0));
        for(i=1; i<n; i++)
        {       
                Y[i]=(*(B+i));
                
                for(j=0;j<i;j++)
                {
                        Y[i]=(Y[i]-((*(lowertriangle_ptr+i*n+j))*Y[j]));
                }
                
                Y[i]=(Y[i]/(*(lowertriangle_ptr+i*n+j)));
        }

        float* x = new float[n];

        x[n]=Y[n]/(*(uppertriangle_ptr+(n-3)*n + (n-3)));

        for(i=n; i>=0; i--)
        {
                x[i]= Y[i];
                for(j=n-1; j>i; j--)
                {
                        x[i]=x[i]-(*(uppertriangle_ptr+i*n+j))*x[j];
                }

                x[i] = x[i]/(*(uppertriangle_ptr+i*n+i));
        }
        return x;
}
