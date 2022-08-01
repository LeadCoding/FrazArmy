long long Pow(int X, int N)
{
    // base condition
	if(N==0) return 1;

    // return type is long long & as we are returning temp therefore it also has to be a long long datatype
	long long temp=Pow(X,N/2); // recursion call

    // if N is odd then we will have to multiply X 
	if(N%2==1) return temp*temp*X;
	return temp*temp;
}

/*
    time complexity : O(log n)
    space complexity : O(log n)
*/
