// Function to display the Upper and Lower Triangular Matrices


void Display(float * uppertriangle_ptr,float * lowertriangle_ptr, int n)
{
        int i,j;
        std::cout<<""<<std::endl;
        std::cout<<"Upper-Triangular Matrix"<<std::endl;

        // Display upper-triangular matrix

        for(i = 0; i< n; i++)
        {
                for(j = 0; j< n; j++)
                {
                        std::cout<< *(uppertriangle_ptr+i*n+j) <<"   ";
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
                        std::cout<< *(lowertriangle_ptr+i*n+j) <<"   ";
                }

                std::cout<<std::endl;
        }

}