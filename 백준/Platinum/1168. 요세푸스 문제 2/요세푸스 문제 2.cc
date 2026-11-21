#include <bits/stdc++.h>

using namespace std;

int N, K;
int num, people, idx = 1;
int tree[400005];

int init(int node, int s, int e)
{
  if(s == e) return tree[node] = 1;
  int mid = (s + e ) / 2;

  return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

int update(int node, int s, int e, int index) 
{
  tree[node]--;

  if(s == e) return 0;
  
  else
  {
    int mid = (s + e) / 2;
  
    if(index <= mid) return update(2 * node, s, mid, index);
    else return update(2 * node + 1, mid + 1, e, index);
  }
}

int query(int node, int s, int e, int index)
{
  if(s == e) return s;

  int mid = (s + e) / 2;

  if(index <= tree[node * 2]) return query(node * 2, s, mid, index);
  else return query(node * 2 + 1, mid + 1, e, index - tree[node * 2]);
}

int main()
{
  scanf("%d %d", &N, &K);
  
  init(1, 1, N);

  printf("<");

  for(int i = 0; i < N; i++)
  {
    int people = N - i;
    idx += K - 1;
    
    if(idx % people == 0) idx = people;
    else if(idx > people) idx %= people;

    num = query(1, 1, N, idx);

    update(1, 1, N, num);

    if(i == N - 1) cout << num;
    else cout << num << ", ";
  }

  printf(">");

  return 0;
}