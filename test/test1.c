#include <unistd.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	j = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			while (av[i][j])
			{
				c = (char)toupper(av[i][j]);
				write(1, &c, 1);
				j++;
			}
			j = 0;
			i++;
			if (av[i])
				write(1, " ", 1);
		}
	}
	else
		write (1, "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 36);
	write(1, "\n", 1);
	return (0);
}
