#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <string.h>
# include <unistd.h>

int			reader(char *filename);
int			checker(const char *piece);

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_putstr(const char *str);
size_t		ft_strlen(const char *str);

#endif
