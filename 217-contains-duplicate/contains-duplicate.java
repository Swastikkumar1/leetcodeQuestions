class Solution {
public boolean containsDuplicate(int[] nums) {

    Set<Integer> s1 = new HashSet<>();
    for(int n: nums){
        if(s1.contains(n)){
            return true;
        }
        s1.add(n);
    }
    return false;
    }

}