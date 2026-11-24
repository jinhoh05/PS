#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int square[105][105]={0};
int main(){

	int s[101][2];
	int a,b,c,d;
	scanf("%d",&a);

	int cnt=0;
	int sum=0;

	for(int i=0;i<a;i++){
		for(int j=0;j<=1;j++){
			scanf("%d",&s[i][j]);
		}
		cnt=s[i][0];
		sum=s[i][1];
		for(int f=0;f<10;f++){
			for(int k=0;k<10;k++){
					square[cnt][sum]=1;
					sum++;
			}
		cnt++;
		sum=s[i][1];
		}
	}

    /*for(int f=0;f<100;f++){
        for(int k=0;k<100;k++){
            printf("%d",square[f][k]);
        }
    printf("\n");
    }*/
	cnt=0;
    for(int f=0;f<100;f++){
        for(int k=0;k<100;k++){
            if(square[f][k] == 1 && square[f-1][k] == 0) cnt++;
            if(square[f][k] == 1 && square[f][k-1] == 0) cnt++;
            if(square[f][k] == 1 && square[f][k+1] == 0) cnt++;
            if(square[f][k] == 1 && square[f+1][k] == 0) cnt++;
        }
    }

    printf("%d",cnt);

}