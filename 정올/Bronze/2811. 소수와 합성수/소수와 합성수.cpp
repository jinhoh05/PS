#include <iostream>
#include <stdio.h>

using namespace std;
bool isPrime(int n){
    if(n < 2) return false;
    for (int i=2;  i <= n / i ; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;

    for(int i=0;i<5;i++){
        scanf("%d",&n);

        if (n < 2) printf("number one\n");
        else if (isPrime(n)) printf("prime number\n");
        else printf("composite number\n");
    }



    return 0;
}