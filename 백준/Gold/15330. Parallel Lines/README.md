# [Gold II] Parallel Lines - 15330 

[문제 링크](https://acmicpc.net/problem/15330) 

### 성능 요약

메모리: 2020 KB, 시간: 184 ms

### 분류

백트래킹, 브루트포싱, 기하학, 수학

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>Given an even number of distinct planar points, consider coupling all of the points into pairs. All the possible couplings are to be considered as long as all the given points are coupled to one and only one other point.</p>

<p>When lines are drawn connecting the two points of all the coupled point pairs, some of the drawn lines can be parallel to some others. Your task is to find the maximum number of parallel line pairs considering all the possible couplings of the points.</p>

<p>For the case given in the first sample input with four points, there are three patterns of point couplings as shown in Figure B.1. The numbers of parallel line pairs are 0, 0, and 1, from the left. So the maximum is 1.</p>

<p style="text-align:center"><img alt="" src="" style="height:193px; width:396px"></p>

<p style="text-align:center">Figure B.1. All three possible couplings for Sample Input 1</p>

<p>For the case given in the second sample input with eight points, the points can be coupled as shown in Figure B.2. With such a point pairing, all four lines are parallel to one another. In other words, the six line pairs (L<sub>1</sub>, L<sub>2</sub>), (L<sub>1</sub>, L<sub>3</sub>), (L<sub>1</sub>, L<sub>4</sub>), (L<sub>2</sub>, L<sub>3</sub>), (L<sub>2</sub>, L<sub>4</sub>) and (L<sub>3</sub>, L<sub>4</sub>) are parallel. So the maximum number of parallel line pairs, in this case, is 6.</p>

<p style="text-align:center"><img alt="" src="" style="height:343px; width:304px"></p>

<p style="text-align:center">Figure B.2. Maximizing the number of parallel line pairs for Sample Input 2</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>m
x<sub>1</sub> y<sub>1</sub>
.
.
.
x<sub>m</sub> y<sub>m</sub></pre>

<p>The first line contains an even integer m, which is the number of points (2 ≤ m ≤ 16). Each of the following m lines gives the coordinates of a point. Integers x<sub>i</sub> and y<sub>i</sub> (−1000 ≤ x<sub>i</sub> ≤ 1000, −1000 ≤ y<sub>i</sub> ≤ 1000) in the i-th line of them give the x- and y-coordinates, respectively, of the i-th point.</p>

<p>The positions of points are all different, that is, xi ≠ x<sub>j</sub> or y<sub>i</sub> ≠ y<sub>j</sub> holds for all i ≠ j. Furthermore, No three points lie on a single line.</p>

### 출력 

 <p>Output the maximum possible number of parallel line pairs stated above, in one line.</p>

