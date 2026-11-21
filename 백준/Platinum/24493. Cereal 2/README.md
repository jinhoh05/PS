# [Platinum I] Cereal 2 - 24493 

[문제 링크](https://acmicpc.net/problem/24493) 

### 성능 요약

메모리: 10200 KB, 시간: 68 ms

### 분류

애드 혹, 이분 매칭, 깊이 우선 탐색, 그래프, 그래프 탐색

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>Farmer John's cows like nothing more than cereal for breakfast! In fact, the cows have such large appetites that they will each eat an entire box of cereal for a single meal.</p>

<p>The farm has recently received a shipment with $M$ different types of cereal $(2\le M\le 10^5)$. Unfortunately, there is only one box of each cereal! Each of the $N$ cows $(1\le N\le 10^5)$ has a favorite cereal and a second favorite cereal. When given a selection of cereals to choose from, a cow performs the following process:</p>

<ol>
	<li>If the box of her favorite cereal is still available, take it and leave.</li>
	<li>Otherwise, if the box of her second-favorite cereal is still available, take it and leave.</li>
	<li>Otherwise, she will moo with disappointment and leave without taking any cereal.</li>
</ol>

<p>Find the minimum number of cows that go hungry if you permute them optimally. Also, find any permutation of the $N$ cows that achieves this minimum.</p>

### 입력 

 <p>The first line contains two space-separated integers $N$ and $M.$</p>

<p>For each $1\le i\le N,$ the $i$-th line contains two space-separated integers $f_i$ and $s_i$ ($1\le f_i,s_i\le M$ and $f_i\neq s_i$) denoting the favorite and second-favorite cereals of the $i$-th cow.</p>

### 출력 

 <p>Print the minimum number of cows that go hungry, followed by any permutation of $1\ldots N$ that achieves this minimum. If there are multiple permutations, any one will be accepted.</p>

