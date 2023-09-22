<h2><a href="https://leetcode.com/problems/longest-increasing-subsequence-ii/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2407. Longest Increasing Subsequence II</a></h2><h3>Hard</h3><hr><div><p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>Find the longest subsequence of <code>nums</code> that meets the following requirements:</p>

<ul>
	<li>The subsequence is <strong>strictly increasing</strong> and</li>
	<li>The difference between adjacent elements in the subsequence is <strong>at most</strong> <code>k</code>.</li>
</ul>

<p>Return<em> the length of the <strong>longest</strong> <strong>subsequence</strong> that meets the requirements.</em></p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,1,4,3,4,5,8,15], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong>
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [7,4,5,1,8,12,4,7], k = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong>
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,5], k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>
</div>