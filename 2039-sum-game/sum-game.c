bool sumGame(char* num) {
    int n = strlen(num);
    int half = n/2;
    int sum_diff = 0;
    int q_diff = 0;
    
    for(int i = 0; i < n; i++){
        int sign = (i<half) ? 1 : -1;

        if(num[i] == '?'){
            q_diff += sign;
        } else {
            sum_diff += sign * (num[i] - '0');
    }
}

if ((q_diff % 2) != 0){
    return true;
}

return (sum_diff + (q_diff/2)*9) != 0;
}

