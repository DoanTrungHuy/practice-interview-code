<h2><a href="https://leetcode.com/problems/maximum-deletions-on-a-string/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2430. Maximum Deletions on a String</a></h2><h3>Hard</h3><hr><div><p>You are given a string <code>s</code> consisting of only lowercase English letters. In one operation, you can:</p>

<ul>
	<li>Delete <strong>the entire string</strong> <code>s</code>, or</li>
	<li>Delete the <strong>first</strong> <code>i</code> letters of <code>s</code> if the first <code>i</code> letters of <code>s</code> are <strong>equal</strong> to the following <code>i</code> letters in <code>s</code>, for any <code>i</code> in the range <code>1 &lt;= i &lt;= s.length / 2</code>.</li>
</ul>

<p>For example, if <code>s = "ababc"</code>, then in one operation, you could delete the first two letters of <code>s</code> to get <code>"abc"</code>, since the first two letters of <code>s</code> and the following two letters of <code>s</code> are both equal to <code>"ab"</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of operations needed to delete all of </em><code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcabcdabc"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- Delete the first 3 letters ("abc") since the next 3 letters are equal. Now, s = "abcdabc".
- Delete all the letters.
We used 2 operations so return 2. It can be proven that 2 is the maximum number of operations needed.
Note that in the second operation we cannot delete "abc" again because the next occurrence of "abc" does not happen in the next 3 letters.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaabaab"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- Delete the first letter ("a") since the next letter is equal. Now, s = "aabaab".
- Delete the first 3 letters ("aab") since the next 3 letters are equal. Now, s = "aab".
- Delete the first letter ("a") since the next letter is equal. Now, s = "ab".
- Delete all the letters.
We used 4 operations so return 4. It can be proven that 4 is the maximum number of operations needed.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aaaaa"
<strong>Output:</strong> 5
<strong>Explanation:</strong> In each operation, we can delete the first letter of s.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 4000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>