<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3229. Minimum Operations to Make Array Equal to Target</a></h2><h3>Hard</h3><hr><div><p>You are given two positive integer arrays <code>nums</code> and <code>target</code>, of the same length.</p>

<p>In a single operation, you can select any <span data-keyword="subarray">subarray</span> of <code>nums</code> and increment or decrement each element within that subarray by 1.</p>

<p>Return the <strong>minimum</strong> number of operations required to make <code>nums</code> equal to the array <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,5,1,2], target = [4,6,2,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We will perform the following operations to make <code>nums</code> equal to <code>target</code>:<br>
- Increment&nbsp;<code>nums[0..3]</code> by 1, <code>nums = [4,6,2,3]</code>.<br>
- Increment&nbsp;<code>nums[3..3]</code> by 1, <code>nums = [4,6,2,4]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,3,2], target = [2,1,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>We will perform the following operations to make <code>nums</code> equal to <code>target</code>:<br>
- Increment&nbsp;<code>nums[0..0]</code> by 1, <code>nums = [2,3,2]</code>.<br>
- Decrement&nbsp;<code>nums[1..1]</code> by 1, <code>nums = [2,2,2]</code>.<br>
- Decrement&nbsp;<code>nums[1..1]</code> by 1, <code>nums = [2,1,2]</code>.<br>
- Increment&nbsp;<code>nums[2..2]</code> by 1, <code>nums = [2,1,3]</code>.<br>
- Increment&nbsp;<code>nums[2..2]</code> by 1, <code>nums = [2,1,4]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>8</sup></code></li>
</ul>
</div>