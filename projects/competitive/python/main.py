def productExceptSelf(nums):
    total = 1
    for i in nums:
        total *= i
    for i in range(len(nums)):
        nums[i] = int(total / nums[i]) if nums[i] != 0 else int(total)
    return nums


l = [0, 0]
# l = [1, 2, 3, 4]

print(productExceptSelf(l))
