
#include "libft.h"

static int		ft_verif_base(int base)
{
	if (base >= 2 && base <= 16)
		return (0);
	return (1);
}

static int		nb_ofnb(long long nb, int base)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static void		is_neg(long long *nb, int *neg, int *size, int base)
{
	if (base == 10 && *nb < 0)
	{
		*nb *= -1;
		*neg = 1;
		*size += 1;
	}
}

char		*ft_itoa_base(int nb, int base)
{
	char				*result;
	long long			nb_long;
	int					size;
	int					neg;

	nb_long = (long long)nb;
	if (ft_verif_base(base))
		return (ft_strdup(""));
	is_neg(&nb_long, &neg, &size, base);
	size += nb_ofnb(nb_long, base) + 1;
	if ((result = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result[--size] = '\0';
	while (size--)
	{
		if (nb_long % base > 9)
			result[size] = 65 + ((nb_long % base) % 10);
		result[size] += ((nb_long % base) + '0');
		nb_long /= base;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
