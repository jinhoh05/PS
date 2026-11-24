#include<stdio.h>
int n;
int x,y;
int mount[105][105];
int chk[105][105];
int head,tail,temp;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct data{
	int px,py;

}position[1000005];

int main()
{
	scanf("%d %d %d",&n,&x,&y);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mount[i][j]);
        }
    }

	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			if(chk[i][j] == 0){
				position[tail].px=i;
				position[tail].py=j;
				tail++;
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			chk[i][j]=0x7fffffff;
		}
	}

    while(1){
        if(head == tail) break;

        for(int i=0;i<4;i++){
            int tmpx=position[head].px+dx[i];
            int tmpy=position[head].py+dy[i];

            if(tmpx >= 1 && tmpy >= 1 && tmpx <= n && tmpy <= n){
                temp=mount[position[head].px][position[head].py] - mount[tmpx][tmpy];

                if(temp < 0) temp*=temp;
                temp+=chk[position[head].px][position[head].py];

				if(chk[tmpx][tmpy] > temp){
                    chk[tmpx][tmpy] = temp;
					position[tail].px = tmpx;
					position[tail].py = tmpy;
					tail++;
				}
            }
        }
        head++;
    }

    printf("%d",chk[x][y]);
}