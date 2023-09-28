<h2><a href="https://leetcode.com/problems/kth-smallest-instructions/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1643. Kth Smallest Instructions</a></h2><h3>Hard</h3><hr><div><p>Bob is standing at cell <code>(0, 0)</code>, and he wants to reach <code>destination</code>: <code>(row, column)</code>. He can only travel <strong>right</strong> and <strong>down</strong>. You are going to help Bob by providing <strong>instructions</strong> for him to reach <code>destination</code>.</p>

<p>The <strong>instructions</strong> are represented as a string, where each character is either:</p>

<ul>
	<li><code>'H'</code>, meaning move horizontally (go <strong>right</strong>), or</li>
	<li><code>'V'</code>, meaning move vertically (go <strong>down</strong>).</li>
</ul>

<p>Multiple <strong>instructions</strong> will lead Bob to <code>destination</code>. For example, if <code>destination</code> is <code>(2, 3)</code>, both <code>"HHHVV"</code> and <code>"HVHVH"</code> are valid <strong>instructions</strong>.</p>

<p>However, Bob is very picky. Bob has a lucky number <code>k</code>, and he wants the <code>k<sup>th</sup></code> <strong>lexicographically smallest instructions</strong> that will lead him to <code>destination</code>. <code>k</code> is <strong>1-indexed</strong>.</p>

<p>Given an integer array <code>destination</code> and an integer <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> <strong>lexicographically smallest instructions</strong> that will take Bob to </em><code>destination</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex1.png" style="width: 300px; height: 229px;"></p>

<pre><strong>Input:</strong> destination = [2,3], k = 1
<strong>Output:</strong> "HHHVV"
<strong>Explanation:</strong> All the instructions that reach (2, 3) in lexicographic order are as follows:
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex2.png" style="width: 300px; height: 229px;"></strong></p>

<pre><strong>Input:</strong> destination = [2,3], k = 2
<strong>Output:</strong> "HHVHV"
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex3.png" style="width: 300px; height: 229px;"></strong></p>

<pre><strong>Input:</strong> destination = [2,3], k = 3
<strong>Output:</strong> "HHVVH"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>destination.length == 2</code></li>
	<li><code>1 &lt;= row, column &lt;= 15</code></li>
	<li><code>1 &lt;= k &lt;= nCr(row + column, row)</code>, where <code>nCr(a, b)</code> denotes <code>a</code> choose <code>b</code>​​​​​.</li>
</ul>
</div>