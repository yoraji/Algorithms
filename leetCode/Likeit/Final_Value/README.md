## Solution Approach
To solve this problem, we can iterate through the list of operations and update the value of X based on the type of operation. The key steps are:

Initialize X to 0.
For each operation in the list:
If the operation is "++X" or "X++", increment X by 1.
If the operation is "--X" or "X--", decrement X by 1.
Return the final value of X.
