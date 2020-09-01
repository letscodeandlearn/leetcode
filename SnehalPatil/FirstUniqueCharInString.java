class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> countMap = new HashMap<>();
        
        int total = s.length();
        
        for(int i=0; i < total; i++) {
            char c = s.charAt(i);
            if(s.indexOf(c) == s.lastIndexOf(c)) {
                return i;
            }
        }
        /*for(int i=0; i < total; i++) {
            char c = s.charAt(i);
            countMap.put(c, countMap.getOrDefault(c, 0) +1 );
        }
        
        for(int i=0; i <total; i++) {
            if(countMap.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        */
        return -1;
    }
}
