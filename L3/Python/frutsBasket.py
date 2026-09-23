# Example 1:
#
# Input: fruits = [1,2,1]
# Output: 3
# Explanation: We can pick from all 3 trees.
# Example 2:
#
# Input: fruits = [0,1,2,2]
# Output: 3
# Explanation: We can pick from trees [1,2,2].
# If we had started at the first tree, we would only pick from trees [0,1].
# Example 3:
#
# Input: fruits = [1,2,3,2,2]
# Output: 4
# Explanation: We can pick from trees [2,3,2,2].
# If we had started at the first tree, we would only pick from trees [1,2].
def totalFruit(fruits):
    """
    :type fruits: List[int]
    :rtype: int
    """
    ans = {}
    for x in fruits:
        ans[x] = ans.get(x, 0) + 1
    sorteddict = dict(sorted(ans.items()))
    print(sorteddict)
    result = sum(list(sorteddict.values())[-2:])
    return result
fruits = [3,3,3,1,2,1,1,2,3,3,4]
ans =totalFruit(fruits)
print(ans)#5