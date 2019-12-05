int         get_size_nb(int nb)
{
    int     i = 0;
    if (nb == 1)
        return (1);
    while (nb)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

int         get_second_nb(int nb)
{
    return (nb % 10);
}

void         is_neg(int *nb, int *size, int *neg, int base)
{
    if (*nb < 0 && base == 10)
    {
        *nb *= 1;
        *size += 1;
        *neg = 1;
    }
}

char        *ft_itoa_base(int nb, int base)
{
    char        *result;
    int         size = 0;
    int         neg = 0;

    if (nb == INT_MIN)
        printf("%d", INT_MIN);
    is_neg(&nb, &size, &neg, base);
    size += get_size_nb(nb);
    result =  malloc(size + 1);
    if (neg == 1)
        result[0] = '-';
    result[--size] = '\0';
    while (size--)
    {
        if (nb % base > 9)
            result[size] = 'A' + get_second_nb(nb % base);
        else
            result[size] = nb % base + '0';
        nb /= base;
    }
    return (result);
}