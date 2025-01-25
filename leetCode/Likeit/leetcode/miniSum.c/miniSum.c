void    ft_sort_int_tab(int *tab)
{
    int    i;
    int    j;
    int    temp;

    i = 0;
    while (i < 4)
    {
        j = i + 1;
        while (j < 4)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}
int minimumSum(int num)
{
    int arr[4];
    int num1 ,num2;
    int i = 3;
    while (i >= 0)
    {
        arr[i] = num % 10;
        num /= 10;
        i--;
    }
    ft_sort_int_tab(arr);
    num1 = arr[0] * 10 + arr[2];
    num2 = arr[1] * 10 + arr[3];
    return (num1 + num2);
}
