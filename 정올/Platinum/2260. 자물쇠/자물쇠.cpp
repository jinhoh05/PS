#include <bits/stdc++.h>

using namespace std;
int n, l1, l2, p, q, s, en;
int arr[1005], a[505];

void recover(){
	for(int i=1;i<=n;i++) arr[i] = a[i];
}

int check(){
	for(int i=1;i<=n;i++){
		if(arr[i] != i) return 1;
	}
	return 0;
}

void first_push(int k){
	for(int i=n;i>=1;i--) arr[i+k] = arr[i];
	for(int i=1;i<=k;i++) arr[i] = arr[i+n];
}

int second_push(){
	int x = p, y = q;

	while(x <= y){
		swap(arr[x], arr[y]);
		x++, y--;
	}
	if(check() == 0) return 0;

	int l=arr[1] - 1;
	first_push(l);

	if(check()) return 0;
	return l;
}

int down(int x, int k){
	if(x == 1 && arr[x] + 1 == arr[n]) return 2;

	if(arr[x] == arr[x-1] - 1 || arr[x] == arr[x-1] + n - 1){
		if(p != 0) return 2;

		p = x - 1;
		while(arr[x] == arr[x-1] - 1 || arr[x] == arr[x-1] + n - 1){
			x++;
			if(x > n) break;
		}
		q = s = x - 1;

		if(p == 1 && q == n){
			printf("%d\n2 %d\n%d",k, n, k);
			en=1;
		}

		return 1;
	}

	return 0;
}

int divide(int k){
	int br;

	for(int i=1;i<=n;i++){
		br = down(i, k);
		if(en == 1) return 1;
		if(br == 1) i=s;
		else if(br == 2) return 0;
	}

	return 1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        a[i]=arr[i];
    }
    l1=l2=n;

    int h=0;
	for(int i=2;i<=n;i++){
		if(arr[i] + 1 == arr[i-1]) h++;
	}
	if(h == n - 1){
		printf("1\n1 %d\n1",n);
	}

    for(int k=1;k<n;k++){
		l1 = l2 = p = q = 0;

		recover();
		first_push(k);
		if(check() == 0) continue;

		if(divide(k) == 0) continue;
		else l2=k;

		if(en == 1) return 0;
		l1=second_push();

		if(p == q || p > q || p < 1 || q < 1 || p > n || q > n || l1 == 0) continue;

		printf("%d\n%d %d\n%d",l1, p, q, l2);
		return 0;
    }

    return 0;
}