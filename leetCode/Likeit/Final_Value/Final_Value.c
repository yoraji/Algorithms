int finalValueAfterOperations(char** operations, int operationsSize) {
    int res = 0;
    for(int i = 0; i < operationsSize; i++)
    {
        if(operations[i][0] == '+' || operations[i][2] == '+')
            res++;
        else if(operations[i][0] == '-' || operations[i][2] == '-')
            res--;
    }
    return res;
}

