# [Platinum II] Connecting Supertrees - 19934 

[문제 링크](https://acmicpc.net/problem/19934) 

### 성능 요약

메모리: 70076 KB, 시간: 116 ms

### 분류

많은 조건 분기, 해 구성하기, 자료 구조, 분리 집합, 그래프

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>Gardens by the Bay is a large nature park in Singapore. In the park there are $n$ towers, known as supertrees. These towers are labelled $0$ to $n-1$. We would like to construct a set of <strong>zero or more</strong> bridges. Each bridge connects a pair of distinct towers and may be traversed in <strong>either</strong> direction. No two bridges should connect the same pair of towers.</p>

<p>A path from tower $x$ to tower $y$ is a sequence of one or more towers such that:</p>

<ul>
	<li>the first element of the sequence is $x$,</li>
	<li>the last element of the sequence is $y$,</li>
	<li>all elements of the sequence are <strong>distinct</strong>, and</li>
	<li>each two consecutive elements (towers) in the sequence are connected by a bridge.</li>
</ul>

<p>Note that by definition there is exactly one path from a tower to itself and the number of different paths from tower $i$ to tower $j$ is the same as the number of different paths from tower $j$ to tower $i$.</p>

<p>The lead architect in charge of the design wishes for the bridges to be built such that for all $0 \leq i, j \leq n-1$ there are exactly $p[i][j]$ different paths from tower $i$ to tower $j$, where $0 \leq p[i][j] \leq 3$.</p>

<p>Construct a set of bridges that satisfy the architect's requirements, or determine that it is impossible.</p>

### 입력 

 Empty

### 출력 

 Empty

