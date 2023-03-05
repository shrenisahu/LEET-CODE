<h2><a href="https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/">2580. Count Ways to Group Overlapping Ranges</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given a 2D integer array <code style="user-select: auto;">ranges</code> where <code style="user-select: auto;">ranges[i] = [start<sub style="user-select: auto;">i</sub>, end<sub style="user-select: auto;">i</sub>]</code> denotes that all integers between <code style="user-select: auto;">start<sub style="user-select: auto;">i</sub></code> and <code style="user-select: auto;">end<sub style="user-select: auto;">i</sub></code> (both <strong style="user-select: auto;">inclusive</strong>) are contained in the <code style="user-select: auto;">i<sup style="user-select: auto;">th</sup></code> range.</p>

<p style="user-select: auto;">You are to split <code style="user-select: auto;">ranges</code> into <strong style="user-select: auto;">two</strong> (possibly empty) groups such that:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">Each range belongs to exactly one group.</li>
	<li style="user-select: auto;">Any two <strong style="user-select: auto;">overlapping</strong> ranges must belong to the <strong style="user-select: auto;">same</strong> group.</li>
</ul>

<p style="user-select: auto;">Two ranges are said to be <strong style="user-select: auto;">overlapping</strong>&nbsp;if there exists at least <strong style="user-select: auto;">one</strong> integer that is present in both ranges.</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">For example, <code style="user-select: auto;">[1, 3]</code> and <code style="user-select: auto;">[2, 5]</code> are overlapping because <code style="user-select: auto;">2</code> and <code style="user-select: auto;">3</code> occur in both ranges.</li>
</ul>

<p style="user-select: auto;">Return <em style="user-select: auto;">the <strong style="user-select: auto;">total number</strong> of ways to split</em> <code style="user-select: auto;">ranges</code> <em style="user-select: auto;">into two groups</em>. Since the answer may be very large, return it <strong style="user-select: auto;">modulo</strong> <code style="user-select: auto;">10<sup style="user-select: auto;">9</sup> + 7</code>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> ranges = [[6,10],[5,15]]
<strong style="user-select: auto;">Output:</strong> 2
<strong style="user-select: auto;">Explanation:</strong> 
The two ranges are overlapping, so they must be in the same group.
Thus, there are two possible ways:
- Put both the ranges together in group 1.
- Put both the ranges together in group 2.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> ranges = [[1,3],[10,20],[2,5],[4,8]]
<strong style="user-select: auto;">Output:</strong> 4
<strong style="user-select: auto;">Explanation:</strong> 
Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group. 
Thus, there are four possible ways to group them:
- All the ranges in group 1.
- All the ranges in group 2.
- Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
- Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= ranges.length &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">ranges[i].length == 2</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= start<sub style="user-select: auto;">i</sub> &lt;= end<sub style="user-select: auto;">i</sub> &lt;= 10<sup style="user-select: auto;">9</sup></code></li>
</ul>
</div>