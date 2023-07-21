<h2><a href="https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">2035 </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Mảng phân vùng thành hai mảng để giảm thiểu chênh lệch tổng</font></font></a></h2><h3>Hard</h3><hr><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Bạn được cung cấp một mảng số </font></font><code>nums</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">nguyên </font></font><code>2 * n</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font><font style="vertical-align: inherit;">Bạn cần phân vùng </font></font><code>nums</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">thành </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">hai</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> mảng có độ dài </font></font><code>n</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">để </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">giảm thiểu chênh lệch tuyệt đối</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> của </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">tổng</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> các mảng. </font><font style="vertical-align: inherit;">Để phân vùng </font></font><code>nums</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">, hãy đặt từng phần tử của </font></font><code>nums</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">vào </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">một</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> trong hai mảng.</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Trả về </font></font><em><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">sự </font><font style="vertical-align: inherit;">khác biệt tuyệt đối </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">tối thiểu</font></font></strong><font style="vertical-align: inherit;"></font></em><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> có thể .</font></font></p>

<p>&nbsp;</p>
<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 1:</font></font></strong></p>
<img alt="ví dụ 1" src="https://assets.leetcode.com/uploads/2021/10/02/ex1.png" style="width: 240px; height: 106px;">
<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [3,9,7,3]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 2
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Một phân vùng tối ưu là: [3,9] và [7,3].</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
Sự khác biệt tuyệt đối giữa tổng của các mảng là abs((3 + 9) - (7 + 3)) = 2.</font></font><font></font>
</pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 2:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [-36,36]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 72
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Một phân vùng tối ưu là: [-36] và [36].</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
Sự khác biệt tuyệt đối giữa tổng của các mảng là abs((-36) - (36)) = 72.</font></font><font></font>
</pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 3:</font></font></strong></p>
<img alt="ví dụ-3" src="https://assets.leetcode.com/uploads/2021/10/02/ex3.png" style="width: 316px; height: 106px;">
<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [2,-1,0,4,-2,-9]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 0
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Một phân vùng tối ưu là: [2,4,-9] và [-1,0,-2].</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
Sự khác biệt tuyệt đối giữa tổng của các mảng là abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.</font></font><font></font>
</pre>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Hạn chế:</font></font></strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>
</div>