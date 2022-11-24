

#include <stdio.h>
#include <math.h>


int isPrime(int num){
    for (int i = 0; i < sqrt(num); i++)
    {
        if (num%i==0){
            return 0;
        }
        
    }
    return 1;
    
}


int factorial(int num)
{
    int sum=1;
    for(int i=1; i<=num; i++)
    {
        sum*=i;
    }
    return sum;
}
int isStrong(int num){

   int temp=num;
   int sum=0;
   while(temp!=0)
   {
    sum+=factorial(temp%10);
    temp/=10;
   }


   if(sum==num)
   {
    return 1;
   }
   return 0;
}





 

