//3)   S= tg2 + tg4 +...+ tg(N*2); N = ввести с клавиатуры (при N=19 S=1)
#include <math.h>
#include <stdio.h>

int main()
{
 int n;
 float s = 0;
 printf("input\n");
 scanf("%d", &n);
 
 for (int i=2; i<=n*2; i += 2){
  s += tan(i);  
 }
 printf("s = %0.0f", s);
 return 0;
}
