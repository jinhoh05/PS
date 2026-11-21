# [Platinum II] Rectangles - 16421 

[문제 링크](https://acmicpc.net/problem/16421) 

### 성능 요약

메모리: 13924 KB, 시간: 280 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑, 값 및 좌표 압축

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>You are working on a new graphics system, which has added a new feature. Whenever you draw a figure, all the pixels in that figure flip from white to black, or from black to white. This image is what happens when three overlapping rectangles are drawn on a white field:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 204px; height: 124px;"></p>

<p>Starting with a white field, given a series of axis-aligned rectangles, how many pixels end up black?</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs.</p>

<p>Each test case will begin with a line with a single integer n (1 ≤ n ≤ 100,000) indicating the number of rectangles.</p>

<p>Each of the next n lines will have four space-separated integers x1, y1, x2 and y2 (0 ≤ x1 < x2 ≤ 10<sup>9</sup>, 0 ≤ y1 < y2 ≤ 10<sup>9</sup>) which represent opposite corners of a rectangle. The rectangle consists of all pixels (x,y) such that x1 ≤ x < x2 and y1 ≤ y < y2, so the area of the rectangle is (x2 - x1) × (y2 - y1) pixels.</p>

### 출력 

 <p>Output a single integer, which is the number of pixels that are black after all of the rectangles are drawn on a white field.</p>

