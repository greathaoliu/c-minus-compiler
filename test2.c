int fact(int m, int n, int a, int b){
    	return m*n+a*b;
}


int main()
{
    int result;
    int m = read();
    int n = read();
    int a = read();
    int b = read();
    result=fact(m, n, a, b);
    write(result);
    return 0;
}

