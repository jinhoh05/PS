# [Platinum II] Balancing a Tree - 24976 

[문제 링크](https://acmicpc.net/problem/24976) 

### 성능 요약

메모리: 2684 KB, 시간: 72 ms

### 분류

애드 혹, 해 구성하기, 그리디, 트리

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>Farmer John has conducted an extensive study of the evolution of different cow breeds. The result is a rooted tree with $N$ ($2\le N\le 10^5$) nodes labeled $1\ldots N$, each node corresponding to a cow breed. For each $i\in [2,N]$, the parent of node $i$ is node $p_i$ ($1\le p_i<i$), meaning that breed $i$ evolved from breed $p_i$. A node $j$ is called an ancestor of node $i$ if $j=p_i$ or $j$ is an ancestor of $p_i$.</p>

<p>Every node $i$ in the tree is associated with a breed having an integer number of spots $s_i$. The "imbalance" of the tree is defined to be the maximum of $|s_i-s_j|$ over all pairs of nodes $(i,j)$ such that $j$ is an ancestor of $i$.</p>

<p>Farmer John doesn't know the exact value of $s_i$ for each breed, but he knows lower and upper bounds on these values. Your job is to assign an integer value of $s_i \in [l_i,r_i]$ ($0\le l_i\le r_i\le 10^9$) to each node such that the imbalance of the tree is minimized.</p>

### 입력 

 <p>The first line contains $T$ ($1\le T\le 10$), the number of independent test cases to be solved, and an integer $B\in \{0,1\}$.</p>

<p>Each test case starts with a line containing $N$, followed by $N-1$ integers $p_2,p_3,\ldots,p_N$.</p>

<p>The next $N$ lines each contain two integers $l_i$ and $r_i$.</p>

<p>It is guaranteed that the sum of $N$ over all test cases does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, output one or two lines, depending on the value of $B$.</p>

<p>The first line for each test case should contain the minimum imbalance.</p>

<p>If $B=1,$ then print an additional line with $N$ space-separated integers $s_1,s_2,\ldots, s_N$ containing an assignment of spots that achieves the above imbalance. Any valid assignment will be accepted.</p>

