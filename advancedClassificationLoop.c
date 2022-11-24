#include <stdio.h>
#include <math.h>

int isArmstrong (int num){
    int counter = 0;
    int tempNum = num;
    while (tempNum != 0)
    {
        counter ++;
        tempNum/=10;
    }
    int sum = 0;
    int numLen = counter;
    int numCP = num;
    
    while (numLen != 0)
    {
        sum+= pow((numCP%10),counter);
        numCP /= 10;
        
        numLen--;
    }
    if (sum == num){
        return 1;
    }
    else {return 0;}

}


int isPalindrome(int num){

    int counter = 0;
    int tempNum = num;
    int numCP = num;
    while (tempNum != 0)
    {
        counter ++;
        tempNum/=10;
    }

    int counterCP = counter;
    int i;
    for ( i = 0; i < (counter/2); i++)
    {
        if (numCP / (pow(10,counterCP-1)) != numCP % 10)
        {
            return 0;
        }
        else {
            numCP = numCP % (int)(pow(10,counterCP-1));
            numCP /= 10;
            counter--;

        }
        
    }
    return 1;
    

}


