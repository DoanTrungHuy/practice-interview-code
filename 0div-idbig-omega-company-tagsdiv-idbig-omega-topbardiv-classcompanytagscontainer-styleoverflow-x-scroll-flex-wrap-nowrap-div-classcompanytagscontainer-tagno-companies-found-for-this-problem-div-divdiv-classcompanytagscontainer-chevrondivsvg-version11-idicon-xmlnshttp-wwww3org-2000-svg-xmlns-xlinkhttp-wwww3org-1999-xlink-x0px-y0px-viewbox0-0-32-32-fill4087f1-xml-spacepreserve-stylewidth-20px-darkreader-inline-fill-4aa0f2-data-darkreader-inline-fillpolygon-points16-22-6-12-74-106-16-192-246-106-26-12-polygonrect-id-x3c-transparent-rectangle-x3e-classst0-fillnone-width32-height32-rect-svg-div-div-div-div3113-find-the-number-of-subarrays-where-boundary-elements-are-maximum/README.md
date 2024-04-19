<h2><a href="https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3113. Find the Number of Subarrays Where Boundary Elements Are Maximum</a></h2><h3>Hard</h3><hr><div><p>You are given an array of <strong>positive</strong> integers <code>nums</code>.</p>

<p>Return the number of <span data-keyword="subarray-nonempty">subarrays</span> of <code>nums</code>, where the <strong>first</strong> and the <strong>last</strong> elements of the subarray are <em>equal</em> to the <strong>largest</strong> element in the subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,4,3,3,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:</p>

<ul>
	<li>subarray <code>[<strong><u>1</u></strong>,4,3,3,2]</code>, with its largest element 1. The first element is 1 and the last element is also 1.</li>
	<li>subarray <code>[1,<u><strong>4</strong></u>,3,3,2]</code>, with its largest element 4. The first element is 4 and the last element is also 4.</li>
	<li>subarray <code>[1,4,<u><strong>3</strong></u>,3,2]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[1,4,3,<u><strong>3</strong></u>,2]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[1,4,3,3,<u><strong>2</strong></u>]</code>, with its largest element 2. The first element is 2 and the last element is also 2.</li>
	<li>subarray <code>[1,4,<u><strong>3,3</strong></u>,2]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
</ul>

<p>Hence, we return 6.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,3,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:</p>

<ul>
	<li>subarray <code>[<u><strong>3</strong></u>,3,3]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[3,<strong><u>3</u></strong>,3]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[3,3,<u><strong>3</strong></u>]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[<strong><u>3,3</u></strong>,3]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[3,<u><strong>3,3</strong></u>]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
	<li>subarray <code>[<u><strong>3,3,3</strong></u>]</code>, with its largest element 3. The first element is 3 and the last element is also 3.</li>
</ul>

<p>Hence, we return 6.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>There is a single subarray of <code>nums</code> which is <code>[<strong><u>1</u></strong>]</code>, with its largest element 1. The first element is 1 and the last element is also 1.</p>

<p>Hence, we return 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>