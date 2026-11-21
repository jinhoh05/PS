#include <bits/stdc++.h>
 
using namespace std;
int n,up,down,num;
int arr[1005],a[1005],ans[5][5],seq[1005];
 
void recover(){ ///초기화
    for(int i=1;i<=n;i++) a[i]=arr[i];
}
 
void print(){ ///결과 출력
    for(int i=1;i<=3;i++){
        if(ans[i][1] == 0) printf("1 1\n");
        else printf("%d %d\n",ans[i][1], ans[i][2]);
    }
}
 
void change(int i, int j, int k){ ///숫자 바꿔주는 함수
    ans[k][1]=i, ans[k][2]=j;
 
    while(i<=j){
        swap(a[i], a[j]);
        i++, j--;
    }
}
 
int check(){ ///완성됐는지 확인
    for(int i=1;i<=n;i++){
        if(a[i] != i) return 0;
    }
    return 1;
}
 
void for_ward(int k){ ///앞에서 볼때
    for(int i=1;i<=n;i++){
        if(a[i] != i){
            for(int j=i;j<=n;j++){
                if(a[j] == i){
                    change(i, j, k);
                    return;
                }
            }
        }
    }
}
 
void back_ward(int k){ ///뒤에서 볼때
    for(int i=n;i>=1;i--){
        if(a[i] != i){
            for(int j=i;j>=1;j--){
                if(a[j] == i){
                    change(j, i, k);
                    return;
                }
            }
        }
    }
}
 
int find_ans(int k){ ///두번 뒤집기
    if(check()) return 1;
 
    if(k == 1){
        for_ward(2);
        if(check()) return 1;
        back_ward(3);
        if(check()) return 1;
    }
 
    else{
        back_ward(2);
        if(check()) return 1;
        for_ward(3);
        if(check()) return 1;
    }
 
    return 0;
}
 
int main()
{
    int cnt=1;
 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        if(i > 1 && abs(arr[i]-arr[i-1]) == 1) cnt++;
        else if(i > 1){
            num++;
            seq[num] = seq[num-1] + cnt;
            cnt=1;
        }
 
        if(i == n && cnt > 0){
            num++;
            seq[num] = seq[num-1] + cnt;
        }
        a[i]=arr[i];
    }
 
    if(check()){
        print();
        return 0;
    }
 
    for(int i=1;i<=num;i++){
        for(int j=i;j<=num;j++){
            change(seq[i-1]+1, seq[j], 1);
            if(find_ans(1)){
                print();
                return 0;
            }
            recover();
            memset(ans,0,sizeof(ans));
 
            change(seq[i-1]+1, seq[j], 1);
            if(find_ans(0)){
                print();
                return 0;
            }
            recover();
            memset(ans,0,sizeof(ans));
        }
    }
 
    return 0;
}