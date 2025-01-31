##  Flip Equivalent Binary
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.
### Input:
Tree 1:
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8

Tree 2:
        1
       / \
      3   2
       \ / \
        6 5 4
         / \
        8   7
### Output:
Example 1: true

