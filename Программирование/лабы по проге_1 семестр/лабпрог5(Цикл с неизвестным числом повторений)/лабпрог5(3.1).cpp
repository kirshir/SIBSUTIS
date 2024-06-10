#include <stdio.h> 
 
int isPrime(int num) { 
    if (num <= 1) { 
        return 0;  
    } 
     
    int i = 2; 
    while (i * i <= num) { 
        if (num % i == 0) {   
            return 0;  
        } 
        i++; 
    } 
     
    return 1; 
} 
 
int main() { 
    int n; 
    printf("input n: "); 
    scanf("%d", &n); 
    int k = 0; int i = 2; 
     
    while (i <= n) { 
        if (isPrime(i)) { 
         k += 1; 
            printf("%d ", i); 
        } 
        i++; 
    } 
     
    printf("\n count: %d", k); 
     
    return 0; 
}
