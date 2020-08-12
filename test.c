/* This is a test file for mini C compiler*/
int fact(int n, int m){
	int temp;
    if(n==1)
        return n;
    else{
    	temp=(n*fact(1,n-1));
    	return temp;
    }
}


int main()
{
    int result,times;
    times=read();
    while(times){
    	int m = read();
    	if( m > 1) {
        	result=fact(1,m);
        }
        else {
            result = 1;
        }
        write(result);
	}
    times=times-1;
    return 0;
}

