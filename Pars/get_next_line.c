#include "get_next_line.h"

char			*ft_new(char *str, char **line)
{
	int			i;
	char		*new;
	char		*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	new = tmp;
	tmp = ft_strsub(str, i + 1, ft_strlen(&str[i]));
	(*line) = ft_strsub(str, 0, i);
	ft_strdel(&new);
	ft_strdel(&str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[8192];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while ((!ft_strchr(str[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		tmp = str[fd];
		buf[ret] = '\0';
		str[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (*str[fd] != '\0')
	{
		str[fd] = ft_new(str[fd], line);
		return (1);
	}
	return (0);
}
