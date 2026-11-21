#include <iostream>
#include <vector>
 
#define MAX 15
using namespace std;
 
int K, Sum;
int Arr[MAX];
vector<bool> Measure;
 
void input()
{
    cin >> K;
    for(int i = 0; i < K; i++) 
    {
        cin >> Arr[i];
        Sum += Arr[i];
    }
    Measure.resize(Sum + 1, false);
}
 
void DFS(int Idx, int Weight)
{
    if(Idx == K)
    {
        if(Weight >= 0) Measure[Weight] = true;
        return;
    }
 
    DFS(Idx + 1, Weight);
    DFS(Idx + 1, Weight + Arr[Idx]);
    DFS(Idx + 1, Weight - Arr[Idx]);
}
 
void Solution()
{
    DFS(0, 0);
 
    int answer = 0;
    for(int i = 1; i <= Sum; i++)
    {
        if(Measure[i] == false)
        {
            answer++;
        }
    }
    
    printf("%d", answer);
}
 
 
int main(void)
{ 
    input();
    Solution();

    return 0;
}