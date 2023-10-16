
#include "get_next_line.h"

char *merge_and_free(char *buffer, char *str)
{
    char *result;

    if (!str)
        return (NULL);
    if (!buffer)
        return ft_strjoin("", str);
    result = ft_strjoin(buffer, str);
    free (buffer);
    return (result);
}

static char *read_line(int fd, char *buffer)
{
    char *str;
    int  len;
    size_t i;

    if (!buffer)
        buffer = ft_calloc(1, 1); 
    str = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); 
    if (!str)
        return (NULL);
    while ((len = read(fd, str, BUFFER_SIZE)) > 0) 
    {
        buffer = merge_and_free(buffer, str);
        if (!buffer)
            free(str);
		if (!buffer)
            return (NULL);
        if (ft_strchr(str, '\n'))
            break ;
		i = 0;
        while (i < BUFFER_SIZE + 1)
            str[i++] = '\0';
    }
    free(str);
    return (buffer); 
}

static char *duplicate_line(char *buffer)
{
    char *str;
    size_t i;
	size_t len;

    if (!buffer || !buffer[0])
        return (NULL);
    len = 0;
    while (buffer[len] != '\n' && buffer[len] != '\0')
        len++;
    if (buffer[len] == '\n')
        len++;
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);
	i = 0;
    while (i < len)
	{
        str[i] = buffer[i];
		i++;
	}
	str[len] = '\0';
    return (str);
}

static char *update_buffer_after_newline(char *buffer)
{
    char *line_pos;
    char *new_buffer;
    size_t len;
	size_t i;

	i = -1;
    line_pos = ft_memchr(buffer, '\n', ft_strlen(buffer));
    if (!line_pos)
        free(buffer);
	if (!line_pos)
        return (NULL);
    line_pos++;
    len = ft_strlen(line_pos);
    new_buffer = ft_calloc(len + 1, sizeof(char));
    if (!new_buffer)
        free(buffer);
	if (!new_buffer)
        return NULL;
    while (++i < len)
        new_buffer[i] = line_pos[i];
    new_buffer[len] = '\0';
    free(buffer);
    return (new_buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *str = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer = read_line(fd, buffer);
    if (!buffer) 
        return (NULL);
    str = duplicate_line(buffer);
    buffer = update_buffer_after_newline(buffer);
    return (str);
}
