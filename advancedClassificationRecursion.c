

#include <stdio.h>
#include <math.h>


int recReverse(int num){
    int temp;
    static int sum=0;
    if(num!=0){

            temp = num % 10;
            sum = sum * 10 + temp;
            recReverse(num / 10);
    }
        else
            return sum;
    return sum;
} 

int isPalindrome(int num){

    if (num == recReverse((num)))
    {
        return 1;
    }
    return 0;


}

int sumArm(int Number, int len)
{
  static int R, Sum = 0;
  
  if (Number > 0)
   {
     R = Number %10;
     Sum = Sum + pow(R, len);
     sumArm (Number /10, len);
     return Sum;
   }
   else
     return 0;
}

int lenArm(int num)
{
int temp=num;
int count=0;
while(temp!=0)
{
    temp=temp/10;
    count++;
}
return count;
}
int isArmstrong(int num)
{
    int len=lenArm(num);
    if(num==sumArm(num,len))
    {
        return 1;
    }
    return 0;
}


