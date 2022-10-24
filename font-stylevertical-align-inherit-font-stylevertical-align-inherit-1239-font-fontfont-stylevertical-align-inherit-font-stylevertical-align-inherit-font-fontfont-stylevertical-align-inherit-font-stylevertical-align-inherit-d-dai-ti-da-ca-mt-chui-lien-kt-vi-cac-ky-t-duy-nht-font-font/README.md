<h2><a href="https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">1239 </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Độ dài tối đa của một chuỗi liên kết với các ký tự duy nhất</font></font></a></h2><h3>Medium</h3><hr><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Bạn được cung cấp một mảng các chuỗi </font></font><code>arr</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font><font style="vertical-align: inherit;">Một chuỗi </font></font><code>s</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">được hình thành bằng cách </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">nối</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> một dãy con của </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">chuỗi</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> đó </font></font><code>arr</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">có </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">các ký tự duy nhất</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> .</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Trả về </font></font><em><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">độ </font><font style="vertical-align: inherit;">dài </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">tối đa</font></font></strong><font style="vertical-align: inherit;"></font></em><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> có thể của </font></font><code>s</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">.</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Một </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">dãy</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> con là một mảng có thể được dẫn xuất từ ​​một mảng khác bằng cách xóa một số hoặc không có phần tử nào mà không thay đổi thứ tự của các phần tử còn lại.</font></font></p>

<p>&nbsp;</p>
<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 1:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> arr = ["un", "iq", "ue"]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 4
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Tất cả các từ nối hợp lệ là:</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- ""</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- "un"</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- "chỉ số thông minh"</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- "ue"</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- "uniq" ("un" + "iq")</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
- "ique" ("iq" + "ue")</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
Chiều dài tối đa là 4.</font></font><font></font>
</pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 2:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> arr = ["cha", "r", "act", "ers"]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 6
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Các từ nối hợp lệ dài nhất có thể có là "chaers" ("cha" + "ers") và "acters" ("act "+" ers ").
</font></font></pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Ví dụ 3:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu vào:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> arr = ["abcdefghijklmnopqrstuvwxyz"]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Đầu ra:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 26
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Giải thích:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> Chuỗi duy nhất trong arr có tất cả 26 ký tự.
</font></font></pre>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Hạn chế:</font></font></strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">chỉ chứa các chữ cái tiếng Anh viết thường.</font></font></li>
</ul>
</div>