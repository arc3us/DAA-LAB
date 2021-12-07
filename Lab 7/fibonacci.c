//Function creates an array with specified length and returns the last element as nth Fibonacci number
int fibonacciNumber(int n)
{
    int fibArray[n], i;
    fibArray[0] = 0, fibArray[1] = 1;
    for (i = 0; i < n; i++)
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    return fibArray[n - 1];
}

//The parameters in bracket may be ignored
//They are used to input command line arguments and are not necessary
int main(int argc, char *argv)
{
    int n;
    printf("Which number in series do you want?");
    scanf("%d", &n);
    printf(fibonacciNumber(n));
    return 0;
}
