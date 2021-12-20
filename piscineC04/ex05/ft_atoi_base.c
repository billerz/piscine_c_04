/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatthan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:01:46 by npatthan          #+#    #+#             */
/*   Updated: 2021/11/03 20:13:13 by npatthan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_base_check(char *str, int nb)
{
	int	i;
	int	j;

	i = 1;
	if (nb <= 1 || str[0] == '+' || str[0] == '-' || str[0] == ' ')
		return (0);
	if (nb <= 1 || str[0] < 32 || str[0] > 126)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			return (0);
		if (str[i] < 32 || str[i] > 126)
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_match(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	if (ft_base_check(base, ft_strlen(base)))
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (check_match(str[i], base) >= 0)
		{
			value = value * ft_strlen(base) + check_match(str[i], base);
			i++;
		}
	}
	value = value * sign;
	return (value);
}
