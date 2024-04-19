<h2><a href="https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1835. Find XOR Sum of All Pairs Bitwise AND</a></h2><h3>Hard</h3><hr><div><p>The <strong>XOR sum</strong> of a list is the bitwise <code>XOR</code> of all its elements. If the list only contains one element, then its <strong>XOR sum</strong> will be equal to this element.</p>

<ul>
	<li>For example, the <strong>XOR sum</strong> of <code>[1,2,3,4]</code> is equal to <code>1 XOR 2 XOR 3 XOR 4 = 4</code>, and the <strong>XOR sum</strong> of <code>[3]</code> is equal to <code>3</code>.</li>
</ul>

<p>You are given two <strong>0-indexed</strong> arrays <code>arr1</code> and <code>arr2</code> that consist only of non-negative integers.</p>

<p>Consider the list containing the result of <code>arr1[i] AND arr2[j]</code> (bitwise <code>AND</code>) for every <code>(i, j)</code> pair where <code>0 &lt;= i &lt; arr1.length</code> and <code>0 &lt;= j &lt; arr2.length</code>.</p>

<p>Return <em>the <strong>XOR sum</strong> of the aforementioned list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,2,3], arr2 = [6,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [12], arr2 = [4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The list = [12 AND 4] = [4]. The XOR sum = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr1[i], arr2[j] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>