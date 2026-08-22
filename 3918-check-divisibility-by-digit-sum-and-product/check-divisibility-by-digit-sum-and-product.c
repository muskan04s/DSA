bool checkDivisibility(int n) {
    int sum = 0,product = 1;
    for(int temp = n; temp > 0; temp /= 10){
        sum += temp%10;
        product *= temp%10;
     }
     return (n % (sum+product) == 0);
}