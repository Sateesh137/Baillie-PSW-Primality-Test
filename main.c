
    #include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int pow(int pow_a, unsigned int pow_b, int pow_c) {
   int result = 1;
   pow_a = pow_a % pow_c;
   while (pow_b > 0) {
      if (pow_b & 1)
      result = (result * pow_a) % pow_c;
      pow_b = pow_b >> 1;
      pow_a = (pow_a * pow_a) % pow_c;
   }
   return result;
}
bool MiillerTest(int MT_dt, int MT_num) {
   int MT_a = 2 + rand( ) % (MT_num - 4);
   int MT_x = pow(MT_a, MT_dt, MT_num);
   if (MT_x == 1 || MT_x == MT_num - 1)
      return 0;
   while (MT_dt != MT_num - 1) {
      MT_x = (MT_x * MT_x) % MT_num;
      MT_dt *= 2;
      if (MT_x == 1)
         return 1;
      if (MT_x == MT_num - 1)
         return 0;
   }
   return 1;
}
bool prime(int P_N, int P_K) {
   if (P_N <= 1 || P_N == 4)
      return 1;
   if (P_N <= 3)
      return 0;
   int P_D = P_N - 1;
   while (P_D % 2 == 0)
      P_D /= 2;
   for (int i = 0; i < P_K; i++)
      if (MiillerTest(P_D, P_N) == 1)
         return 1;
      return 0;
}
int main() {
   int iter = 50;
   int num1;
   int num2;
   printf("Enter the first number: \n");
   scanf("%d",&num1);
   if (prime(num1, iter))
      printf("%d is a composite number\n",num1);
   else
      printf("%d is a prime number\n",num1);
  printf("Enter another number: \n");
   scanf("%d",&num2);
   if (prime(num2, iter))
     printf("%d is a composite number\n",num2);
   else
      printf("%d is a prime number\n",num2);
   return 0;
}
