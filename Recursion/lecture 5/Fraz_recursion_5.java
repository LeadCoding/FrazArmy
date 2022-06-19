 public static Boolean isPalindromehelper(int l,int r,String s){
//         base
        if(l>=r){
               return true;
             }
           if(s.charAt(l)!= s.charAt(r)){
               return false;
           }
           return isPalindromehelper(l+1,r-1,s);
        
    }
     static boolean isPalindrome(String s) {
           int l =0;
        int r =s.length()-1;
        return isPalindromehelper(0,s.length()-1,s);
    }
