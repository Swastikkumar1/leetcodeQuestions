class Solution {
public int[] searchRange(int[] nums, int target) {
int [] result = {-1,-1}; // declaring an array
int left = binarySearch(nums, target, true);
int right = binarySearch(nums, target, false);
result[0]= left;
result[1] = right;
return result;
}

int binarySearch(int[] nums, int target, boolean status){
int l = 0;
int r= nums.length-1;
int x = -1;
while(l<=r){
int mid = l+(r-l)/2;
if(nums[mid]>target){
r = mid-1;}
else if(nums[mid]<target){
l = mid+1;
}
else{
x = mid;
if(status){
r = mid-1;
}
else
{
l = mid+1;
}
}
}
return x;
}
}