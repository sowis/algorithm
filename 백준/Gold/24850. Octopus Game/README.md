# [Gold II] Octopus Game - 24850 

[문제 링크](https://www.acmicpc.net/problem/24850) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 정수론, 유클리드 호제법

### 제출 일자

2026년 3월 22일 18:23:21

### 문제 설명

<p>The tournament of "Octopus Game" is held in some country.</p>

<p>This round the participants will deal with math puzzle. Each player has two cards, initially there are integers $a_0$ and $b_0$ at the cards, respectively. </p>

<p>Players make actions with their cards. Let the integers on player's cards be $a$ and $b$. The player first chooses an integer $k$, and then performs one of the following operations:</p>

<ol>
	<li>replace the integer on the first card with $a + kb$; </li>
	<li>replace the integer on the second card with $b + ka$.</li>
</ol>

<p>While playing, the absolute value of an integer written on a card must not exceed $10^{18}$, otherwise something bad might happen. Those players are winning the round, who get $0$ written on one of the cards, after performing at most $50$ actions.</p>

<p>You are going to play the game, and of course you would like to win!</p>

### 입력 

 <p>The only line of input contains two integers $a_0$ and $b_0$ --- the initial integers written on the cards ($-10^{18} \le a_0, b_0 \le 10^{18}$).</p>

### 출력 

 <p>The first line must contain $n$ --- the number of actions that the player is willing to perform to get 0 on one of the cards ($0 \le n \le 50$). Note that you need not minimize the number of actions, but it must not exceed $50$. </p>

<p>The following $n$ lines must contain two space separated integers each: $t_i$ and $k_i$ --- the type of the respective action and the chosen integer $k$.</p>

<p>If there are multiple valid solutions, it is allowed to output any of them, but note that during the game the integers on the cards must not exceed $10^{18}$ by their absolute values.</p>

