#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s && *s++ != '\n')
		counter++;
	return (counter);
}

int	get_rows(char *map_path)
{
	int	count;
	int	fd;

	count = 0;
	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd))
		count++;
	return (count);
}

int	is_map_not_closed(char *map_path)
{
	int		fd;
	char	*str;
	int		count_rows;

	fd = open(map_path, O_RDONLY);
	count_rows = get_rows(map_path);
	str = get_next_line(fd);
	while (*str)
	{
		if (*str != '1' && *str != '\n')
			return (1);
		str++;
	}
	str = get_next_line(fd);
	while (count_rows-- > 2)
	{
		if ((*str != '1' || *(str + ft_strlen(str) - 1) != '1') && *str != '\n')
			return (1);
		str = get_next_line(fd);
	}
	while (*str)
	{
		if (*str != '1' && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

int	is_missing_item(char *map_path)
{
	int		fd;
	char 	c;
	int		count_collectible;
	int		count_exit;
	int		count_start_pos;

	fd = open(map_path, O_RDONLY);
	count_collectible = 0;
	count_exit = 0;
	count_start_pos = 0;
	while (read(fd, &c, 1))
	{
		if (c == 'C')
			count_collectible++;
		else if (c == 'E')
			count_exit++;
		else if (c == 'P')
			count_start_pos++;
	}
	if (count_collectible < 1 || count_exit < 1 || count_start_pos < 1)
		return (1);
	return (0);
}

int main()
{
	printf("%d\n", is_missing_item("./map.ber"));
}
