<h2><a href="https://leetcode.com/problems/pass-the-pillow/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2582. Pass the Pillow</a></h2><h3>Easy</h3><hr><div><p>There are <code>n</code> people standing in a line labeled from <code>1</code> to <code>n</code>. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.</p>

<ul>
	<li>For example, once the pillow reaches the <code>n<sup>th</sup></code> person they pass it to the <code>n - 1<sup>th</sup></code> person, then to the <code>n - 2<sup>th</sup></code> person and so on.</li>
</ul>

<p>Given the two positive integers <code>n</code> and <code>time</code>, return <em>the index of the person holding the pillow after </em><code>time</code><em> seconds</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, time = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> People pass the pillow in the following way: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 3 -&gt; 2.
After five seconds, the 2<sup>nd</sup> person is holding the pillow.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, time = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> People pass the pillow in the following way: 1 -&gt; 2 -&gt; 3.
After two seconds, the 3<sup>r</sup><sup>d</sup> person is holding the pillow.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= time &lt;= 1000</code></li>
</ul>
</div>