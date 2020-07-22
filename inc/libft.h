/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tris <tristan.kapous@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:53:57 by trikapou          #+#    #+#             */
/*   Updated: 2020/04/14 20:55:41 by tris             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <string.h>

# define L s_list
typedef struct	L
{
	void		*content;
	size_t		content_size;
	struct L	*next;
}				t_list;

/* File Descriptor */
int				ft_read(int fd, char **buff, int buff_size);
/* int				get_next_line(int const fd, char **line); */
int				ft_gnl(int const fd, char **line);

/* Print */
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbriter(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstrtab(char **s);
void			ft_putinttab(int *t, int size);
void			ft_putstrtab_delim(char **t, char delim);

/* ASCII check */
int				ft_isascii(int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isblank(int n);
int				ft_isprint(int c);
int				ft_isspace(int n);

/* Memory */
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_calloc(size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_memdel(void **ap);

/* Characters */
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_charswap(char *c1, char *c2);

/* Strings */
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
size_t			ft_strlen(const char *s);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strccpy(char *dst, const char *src, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcdup(const char *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, char const *s2, int n);
char			*ft_strjoin_free(char const *s1, char const *s2, char i);
char			*ft_strnjoin_free(char const *s1, char const *s2, char i, int n);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strchr_index(const char *s, char c);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

char			**ft_strsplit(char const *s, char c);
char			**ft_strnsplit(char const *s, char c, size_t n);
char			**ft_strrsplit(char const *s, char *c);
char			**ft_strrnsplit(char const *s, char *c, size_t n);

char			*ft_itoa(int n);
char			*ft_strrev(const char *s);
char			*ft_strtrim(char const *s);
char			*ft_chartrim(char const *s, char c);
char			*ft_strlinetrim(char const *s);

/* Arrays of strings */
char			**ft_tabstrnew(size_t size);
char			**ft_tabrealloc(char **tab, size_t size, size_t width);
void			ft_tabstrdel(char ***t);

/* Lists */
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **start, t_list *link);
void			ft_lstaddlink(t_list **start, void *content, size_t content_size);
void			ft_lstdel(t_list **link, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *list, void (*f)(t_list *elem));

/* Maths */
int				ft_abs(int n);
int				ft_sqrt(int n);
int				ft_atoi(const char *s);
int				ft_spacetoi(char *s);
int				ft_first_duplicate_tab(int *tab, int tab_len);
int				ft_intlen(int n);
void			ft_swap(int *a, int *b);

/* Sort */
int				ft_quicksort(int *t, int n);

/* /1* Hash *1/ */
/* unsigned int	ft_hash(const char *key); */
/* void			ft_ht_dump(t_ht *hashtable); */
/* void			ft_ht_del(t_ht *hashtable, const char *key); */
/* int				ft_ht_insert(t_ht *hashtable, const char *key, const char *value); */
/* char			*ft_ht_get(t_ht *hashtable, const char *key); */
/* t_ht			*ft_ht_create(void); */
/* t_entry			*ft_ht_pair(const char *key, const char *value); */

#endif
