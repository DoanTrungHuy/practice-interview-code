<h2><a href="https://leetcode.com/problems/maximum-odd-binary-number/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2864. Maximum Odd Binary Number</a></h2><h3>Easy</h3><hr><div><p>You are given a <strong>binary</strong> string <code>s</code> that contains at least one <code>'1'</code>.</p>

<p>You have to <strong>rearrange</strong> the bits in such a way that the resulting binary number is the <strong>maximum odd binary number</strong> that can be created from this combination.</p>

<p>Return <em>a string representing the maximum odd binary number that can be created from the given combination.</em></p>

<p><strong>Note </strong>that the resulting string <strong>can</strong> have leading zeros.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "010"
<strong>Output:</strong> "001"
<strong>Explanation:</strong> Because there is just one '1', it must be in the last position. So the answer is "001".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "0101"
<strong>Output:</strong> "1001"
<strong>Explanation: </strong>One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of <code>'0'</code> and <code>'1'</code>.</li>
	<li><code>s</code> contains at least one <code>'1'</code>.</li>
</ul>
</div>