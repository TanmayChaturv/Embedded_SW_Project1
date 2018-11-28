    #include<stdio.h>
    #include<stdlib.h>
    int n=10;//change the number of fibonacci numbers

    int f(int);
     
    int main()
    {
      int i = 0, c;
            
      printf("Fibonacci series terms are:\n");
     
      for (c = 1; c <= n; c++)
      {
        printf("%d\n", f(i));
        i++;
      }
     
      return 0;
    }
     
    int f(int num)
    {
      if (num == 0 || num == 1)
        return num;
      else
        return (f(num-1) + f(num-2));
    }
