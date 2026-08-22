bool checkDivisibility(int n) {
    int sum = 0;
    int product =1;
    int temp = n;
     while(temp!=0){
        int digits = temp % 10;
        sum += digits;
        product *= digits;
        temp /= 10;
     }

     int total = sum + product;
     return (n % total == 0);
}