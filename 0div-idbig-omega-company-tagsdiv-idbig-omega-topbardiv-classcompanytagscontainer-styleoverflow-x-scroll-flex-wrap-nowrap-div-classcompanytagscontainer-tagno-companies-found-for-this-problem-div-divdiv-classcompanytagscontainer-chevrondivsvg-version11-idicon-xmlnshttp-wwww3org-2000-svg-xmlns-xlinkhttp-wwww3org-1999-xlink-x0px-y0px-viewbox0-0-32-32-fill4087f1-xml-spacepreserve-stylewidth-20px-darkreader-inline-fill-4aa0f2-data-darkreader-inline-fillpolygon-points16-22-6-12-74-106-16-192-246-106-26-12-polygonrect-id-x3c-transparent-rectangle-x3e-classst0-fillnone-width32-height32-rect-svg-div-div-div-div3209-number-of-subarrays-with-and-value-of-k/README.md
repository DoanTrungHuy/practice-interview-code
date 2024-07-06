<h2><a href="https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3209. Number of Subarrays With AND Value of K</a></h2><h3>Hard</h3><hr><div><p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return the number of <span data-keyword="subarray-nonempty">subarrays</span> of <code>nums</code> where the bitwise <code>AND</code> of the elements of the subarray equals <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>All subarrays contain only 1's.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,2], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>Subarrays having an <code>AND</code> value of 1 are: <code>[<u><strong>1</strong></u>,1,2]</code>, <code>[1,<u><strong>1</strong></u>,2]</code>, <code>[<u><strong>1,1</strong></u>,2]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>Subarrays having an <code>AND</code> value of 2 are: <code>[1,<b><u>2</u></b>,3]</code>, <code>[1,<u><strong>2,3</strong></u>]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>
</div>