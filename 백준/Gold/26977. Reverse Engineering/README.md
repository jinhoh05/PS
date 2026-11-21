# [Gold I] Reverse Engineering - 26977 

[문제 링크](https://acmicpc.net/problem/26977) 

### 성능 요약

메모리: 2032 KB, 시간: 8 ms

### 분류

애드 혹, 그리디, 구현

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>Elsie has a program that takes as input an array of $N$ ($1\le N\le 100$) variables $b[0],\dots,b[N-1]$, each equal to zero or one, and returns the result of applying a sequence of if / else if / else statements on the input. Each statement examines the value of at most one input variable, and returns either zero or one. An example of such a program might be:</p>

<pre class="prettyprint">if (b[1] == 1) return 1;
else if (b[0] == 0) return 0;
else return 1;
</pre>

<p>For example, if the input to the program above is "10" (that is, $b[0] = 1$ and $b[1] = 0$), then the output should be 1.</p>

<p>Elsie has told Bessie the correct output for $M$ ($1\le M\le 100$) different inputs. Bessie is now trying to reverse engineer Elsie's program. Unfortunately, Elsie might have lied; it may be the case that no program of the form above is consistent with what Elsie said.</p>

<p>For each of $T$ ($1\le T\le 10$) test cases, determine whether Elsie must be lying or not.</p>

### 입력 

 <p>The first line contains $T$, the number of test cases.</p>

<p>Each test case starts with two integers $N$ and $M$, followed by $M$ lines, each containing a string of $N$ zeros and ones representing an input (that is, the values of $b[0] \ldots b[N-1]$) and an additional character (zero or one) representing the output. Consecutive test cases are separated by newlines.</p>

### 출력 

 <p>For each test case, output "OK" or "LIE" on a separate line.</p>

