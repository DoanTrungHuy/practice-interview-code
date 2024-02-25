<h2><a href="https://leetcode.com/problems/greatest-common-divisor-traversal/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2709. Greatest Common Divisor Traversal</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>, and you are allowed to <strong>traverse</strong> between its indices. You can traverse between index <code>i</code> and index <code>j</code>, <code>i != j</code>, if and only if <code>gcd(nums[i], nums[j]) &gt; 1</code>, where <code>gcd</code> is the <strong>greatest common divisor</strong>.</p>

<p>Your task is to determine if for <strong>every pair</strong> of indices <code>i</code> and <code>j</code> in nums, where <code>i &lt; j</code>, there exists a <strong>sequence of traversals</strong> that can take us from <code>i</code> to <code>j</code>.</p>

<p>Return <code>true</code><em> if it is possible to traverse between all such pairs of indices,</em><em> or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -&gt; 2 -&gt; 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 &gt; 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 &gt; 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,9,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,12,8]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>