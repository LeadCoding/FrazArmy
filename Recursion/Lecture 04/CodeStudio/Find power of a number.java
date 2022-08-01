class Solution {

	public static long Pow(int X, int N) {
	// base condition
	if(N==0) return 1;

        long temp=Pow(X,N/2); // recursion call

        // if N is odd then we will have to multiply X 
        if(N%2==1) return temp*temp*X;
        return temp*temp;
	}
}


/*
    time complexity : O(log n)
    space complexity : O(log n)
*/
