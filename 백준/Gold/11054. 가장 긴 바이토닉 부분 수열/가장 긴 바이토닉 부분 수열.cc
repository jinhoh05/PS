#include <bits/stdc++.h>

using namespace std;
int n;
int arr[1005], lis[1005], r_lis[1005];

void LIS(){
    for(int i=1;i<=n;i++){
		lis[i] = 1;
		for(int j=1;j<=i;j++){
			if(arr[j] < arr[i] && lis[i] < lis[j] + 1) lis[i]++;
        }
	}
}

void R_LIS(){
	for(int i=n;i>=1;i--){
		r_lis[i] = 1;
		for(int j=n;j>=i;j--){
            if(arr[j] < arr[i] && r_lis[i] < r_lis[j] + 1) r_lis[i]++;
		}
	}
}

int finding() {
	int ans = 0;
	for(int i=1;i<=n;i++){
        ans = max(ans, lis[i] + r_lis[i]);
	}
	return ans - 1;
}

int main(){

    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    LIS();
    R_LIS();

    printf("%d", finding());

    return 0;
}
