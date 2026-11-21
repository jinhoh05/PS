# [Diamond IV] Copy and Paste 3 - 24945 

[문제 링크](https://acmicpc.net/problem/24945) 

### 성능 요약

메모리: 75692 KB, 시간: 704 ms

### 분류

다이나믹 프로그래밍, 조화수, 해싱, 문자열

### 제출 일자

2026년 11월 21일 10:38:38

### 문제 설명

<p>JOI, Ltd. is a company known for their “just odd inventions.” Recently, JOI, Ltd. developed a text editor called “Just Odd Editor.”</p>

<p>Using this text editor, we can input a string of characters by performing the following operations several times. Let $X$ be the string displayed on the screen of the text editor. Let $Y$ be the string saved in the clipboard. In the beginning, both of $X$ and $Y$ are the empty string.</p>

<ul>
	<li><strong>Operation A</strong> : We add one character in the end of the string. Namely, we choose a character $c$, and update $X$ to be $X + c$.</li>
	<li><strong>Operation B</strong> : We select all the characters and cut them. Namely, we update $Y$ to be $X$. After that, we set $X$ to be the empty string.</li>
	<li><strong>Operation C</strong> : We paste the string from the clipboard at the end of the string. Namely, we update $X$ to be $X + Y$.</li>
</ul>

<p>Here, for characters or strings $x$, $y$, the string $x + y$ means the string obtained by connecting $x$ with $y$ in this order. Performing an operation takes time. If we perform the operation $A$, $B$, $C$ once, it takes $A$, $B$, $C$ unit time, respectively.</p>

<p>You installed Just Odd Editor. You want to input a string $S$ of length $N$ as soon as possible. Performing operations, you want to make the string on the display be $S$ as soon as possible.</p>

<p>Write a program which, given the length $N$, the string $S$, and the amount of unit time needed to perform an operation, calculates the least amount of time needed to input the string $S$.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<p>$\begin{align*} & N \\ & S \\ & A \\ & B \\ & C\end{align*}$</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the least amount of time needed to input the string $S$.</p>

