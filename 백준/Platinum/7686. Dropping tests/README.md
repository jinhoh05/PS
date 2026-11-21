# [Platinum V] Dropping tests - 7686 

[문제 링크](https://acmicpc.net/problem/7686) 

### 성능 요약

메모리: 2024 KB, 시간: 36 ms

### 분류

이분 탐색, 그리디, 매개 변수 탐색, 정렬

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>In a certain course, you take n tests. If you get \(a_i\) out of \(b_i\) questions correct on test i, your cumulative average is defined to be</p>

<p style="text-align:center">\(100 \cdot \dfrac{\sum_{i=1}^{n}{a_i}}{\sum_{i=1}^{n}{b_i}}\).</p>

<p>Given your test scores and a positive integer k, determine how high you can make your cumulative average if you are allowed to drop any k of your test scores.</p>

<p>Suppose you take 3 tests with scores of 5/5, 0/1, and 2/6. Without dropping any tests, your cumulative average is 100·(5+0+2)/(5+1+6) = 50. However, if you drop the third test, your cumulative average becomes 100·(5+0)/(5+1) ≈ 83.33 ≈ 83.</p>

### 입력 

 <p>4.3 Input The input test file will contain multiple test cases, each containing exactly three lines. The first line contains two integers, 1 ≤ n ≤ 1000 and 0 ≤ k < n. The second line contains n integers indicating \(a_i\) for all i. The third line contains n positive integers indicating \(b_i\) for all i. It is guaranteed that 0 ≤ \(a_i\) ≤ \(b_i\) ≤ 1, 000, 000, 000. The end-of-file is marked by a test case with n = k = 0 and should not be processed.</p>

### 출력 

 <p>For each test case, write a single line with the highest cumulative average possible after dropping k of the given test scores. The average should be rounded to the nearest integer.</p>

