// Function to decompose a matrix in Lower and Upper Triangular parts

void LUDecomposition(float * A,float * lowertriangle_ptr, int n)
{
        int ctr1,ctr2;
        int row,column;
        int i,j,k;
        
        for(row=0;row<n;row++)
        {       for(column=0;column<n;column++)
                {
                        if(row<column)          //initialise all elements of lower triangle in lower triangular matix as 0
                                *(lowertriangle_ptr+row*n+column)=0.0;
                        if(row==column)         //initialise all diagonal elements of lower triangular matrix as 1
                                *(lowertriangle_ptr+row*n+column)=1.0;
                }
        }

        ctr2 = 0;
        int m = 1;
        while(ctr2 < n)         //loop for LU decomposition of the matrix
        {       
                for(ctr1 = m; ctr1<n;ctr1++)
                {
                        float mul[n];
                        mul[ctr1] = *(A+ctr1*n+ctr2)/ *(A+ctr2*n+ctr2);
                        *(lowertriangle_ptr+ctr1*n+ctr2) = mul[ctr1];
                        row = ctr1;
                        for(column = ctr2;column<n;column++)
                                *(A+row*n+column) = *(A+row*n+column) - mul[ctr1]*(*(A+ctr2*n+column));
                }
                m++;
                ctr2++;
        }

}