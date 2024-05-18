<h2><a href="https://leetcode.com/problems/distribute-coins-in-binary-tree/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Amazon</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Apple</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>PhonePe</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>979. Distribute Coins in Binary Tree</a></h2><h3>Medium</h3><hr><div><p>You are given the <code>root</code> of a binary tree with <code>n</code> nodes where each <code>node</code> in the tree has <code>node.val</code> coins. There are <code>n</code> coins in total throughout the whole tree.</p>

<p>In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.</p>

<p>Return <em>the <strong>minimum</strong> number of moves required to make every node have <strong>exactly</strong> one coin</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/18/tree1.png" style="width: 250px; height: 236px;">
<pre><strong>Input:</strong> root = [3,0,0]
<strong>Output:</strong> 2
<strong>Explanation: </strong>From the root of the tree, we move one coin to its left child, and one coin to its right child.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/18/tree2.png" style="width: 250px; height: 236px;">
<pre><strong>Input:</strong> root = [0,3,0]
<strong>Output:</strong> 3
<strong>Explanation: </strong>From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= Node.val &lt;= n</code></li>
	<li>The sum of all <code>Node.val</code> is <code>n</code>.</li>
</ul>
</div>