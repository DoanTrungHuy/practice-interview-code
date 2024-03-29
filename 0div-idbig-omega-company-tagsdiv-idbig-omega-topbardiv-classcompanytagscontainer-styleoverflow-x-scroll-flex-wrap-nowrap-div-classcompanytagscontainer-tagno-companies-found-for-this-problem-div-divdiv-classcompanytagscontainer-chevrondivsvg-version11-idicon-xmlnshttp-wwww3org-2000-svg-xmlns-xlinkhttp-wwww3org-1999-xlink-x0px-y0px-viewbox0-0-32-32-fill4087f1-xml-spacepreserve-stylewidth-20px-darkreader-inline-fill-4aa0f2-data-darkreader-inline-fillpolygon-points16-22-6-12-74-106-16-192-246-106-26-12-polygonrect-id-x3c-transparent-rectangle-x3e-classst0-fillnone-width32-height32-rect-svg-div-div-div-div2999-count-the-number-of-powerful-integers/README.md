<h2><a href="https://leetcode.com/problems/count-the-number-of-powerful-integers/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2999. Count the Number of Powerful Integers</a></h2><h3>Hard</h3><hr><div><p>You are given three integers <code>start</code>, <code>finish</code>, and <code>limit</code>. You are also given a <strong>0-indexed</strong> string <code>s</code> representing a <strong>positive</strong> integer.</p>

<p>A <strong>positive</strong> integer <code>x</code> is called <strong>powerful</strong> if it ends with <code>s</code> (in other words, <code>s</code> is a <strong>suffix</strong> of <code>x</code>) and each digit in <code>x</code> is at most <code>limit</code>.</p>

<p>Return <em>the <strong>total</strong> number of powerful integers in the range</em> <code>[start..finish]</code>.</p>

<p>A string <code>x</code> is a suffix of a string <code>y</code> if and only if <code>x</code> is a substring of <code>y</code> that starts from some index (<strong>including </strong><code>0</code>) in <code>y</code> and extends to the index <code>y.length - 1</code>. For example, <code>25</code> is a suffix of <code>5125</code> whereas <code>512</code> is not.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> start = 1, finish = 6000, limit = 4, s = "124"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit &lt;= 4, and "124" as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
It can be shown that there are only 5 powerful integers in this range.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> start = 15, finish = 215, limit = 6, s = "10"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The powerful integers in the range [15..215] are 110 and 210. All these integers have each digit &lt;= 6, and "10" as a suffix.
It can be shown that there are only 2 powerful integers in this range.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> start = 1000, finish = 2000, limit = 4, s = "3000"
<strong>Output:</strong> 0
<strong>Explanation:</strong> All integers in the range [1000..2000] are smaller than 3000, hence "3000" cannot be a suffix of any integer in this range.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= start &lt;= finish &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 9</code></li>
	<li><code>1 &lt;= s.length &lt;= floor(log<sub>10</sub>(finish)) + 1</code></li>
	<li><code>s</code> only consists of numeric digits which are at most <code>limit</code>.</li>
	<li><code>s</code> does not have leading zeros.</li>
</ul>
</div>