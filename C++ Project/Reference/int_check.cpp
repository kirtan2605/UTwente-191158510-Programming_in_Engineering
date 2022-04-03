#include<stdio.h>
#include<math.h>

int main()
{
   double input;
   scanf("%lf",&input);

   int absulate = abs(input);
   printf( (input==absulate)? "It is integer\n" : "It is float");

   return 0;
}
