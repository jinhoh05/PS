# [Platinum V] Self Study - 24475 

[문제 링크](https://acmicpc.net/problem/24475) 

### 성능 요약

메모리: 14320 KB, 시간: 324 ms

### 분류

이분 탐색, 그리디, 수학, 매개 변수 탐색

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>In the third semester of the first grade of JOI High School, $N$ courses are given for $M$ weeks from the first week to the $M$-th week. The courses are numbered from $1$ to $N$. In each week, $N$ classes are given. The $i$-th class in each week is a class for Course $i$.</p>

<p>Bitaro is a student of the first grade. In each of the $N \times M$ classes, he takes one of the following actions.</p>

<ul>
	<li>Action 1: Bitaro attends the class. If he attends a class for Course $i$ ($1 ≤ i ≤ N$), the comprehension level of Course $i$ will be increased by $A_i$.</li>
	<li>Action 2: Bitaro does not attend the class. Instead, he chooses any one of the courses, and studies for the chosen course by himself. If he studies for Course $i$ ($1 ≤ i ≤ N$) by himself for the duration of a class, the comprehension level of Course $i$ will be increased by $B_i$.</li>
</ul>

<p>In the beginning, the comprehension level of every course is $0$. Since Bitaro wants to practice competitive programming after school, he will not study outside the duration of the classes. When all the classes in the third semester finish, the final examination will be held.</p>

<p>Bitaro does not want to get a failing grade. Therefore, he wants to maximize the minimum comprehension level of the courses at the moment of the final examination.</p>

<p>Given the length of the semester, the number of the courses, and the incremental values of the comprehension levels, write a program which calculates the maximum possible value of the minimum comprehension level of the courses at the moment of the final examination.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*} & N\,M \\ & A_1 \, A_2 \, \cdots \, A_N \\ & B_1 \, B_2 \, \cdots \, B_N\end{align*}$</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the maximum possible value of the minimum comprehension level of the courses at the moment of the final examination.</p>

