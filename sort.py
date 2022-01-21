from random import randint
from timeit import default_timer
import sys

def createList(length):
    randomList=[]
    for i in range(length):
        randomList.append(randint(0,length))
    return randomList

def mergeSort(nums):
    if len(nums)>1:
        mid=len(nums)//2
        left=nums[:mid]
        right=nums[mid:]
        mergeSort(left)
        mergeSort(right)

        leftIndex = 0
        rightIndex = 0
        listIndex = 0
        while (leftIndex < len(left) and rightIndex < len(right)):
            if left[leftIndex] < right[rightIndex]:
                nums[listIndex]=left[leftIndex]
                leftIndex += 1
            else:
                nums[listIndex]=right[rightIndex]
                rightIndex += 1
            listIndex+=1

        while (leftIndex < len(left)):
            nums[listIndex]=left[leftIndex]
            leftIndex += 1
            listIndex += 1
        while (rightIndex < len(right)):
            nums[listIndex]=right[rightIndex]
            rightIndex += 1
            listIndex += 1

def timing():
    length=int(sys.argv[1])
    nums=createList(length)
    start = default_timer()
    mergeSort(nums)
    stop = default_timer()
    print(sys.argv[1]+": ",stop - start)

timing()
