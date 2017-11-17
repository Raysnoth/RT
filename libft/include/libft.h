/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:20:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/31 13:30:16 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strdup(const char *s1);
void				ft_putnbr(int n);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memset(void *b, int c, size_t len);
int					ft_tolower(int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_itoa(int n);
char				*ft_strnstr(const char *big, const char *little, size_t \
																		len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_isescape(int c);
int					ft_nbrlen(int n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
char				*ft_strduptoc(char *str, int c);
char				*ft_freestrjoin(char *s1, char *s2, int mod);
char				*ft_putlinefeed(char *str);
int					ft_cw(const char *s, int c);
int					ft_pow(int nb, int pow);
int					ft_hex_to_dec(char *str);
t_rgb				ft_hex_to_rgb(char *color);
char				*ft_itoa_base(int value, int base);
char				*ft_rgb_to_hex(t_rgb rgb);
int					ft_rgb_to_dec(t_rgb rgb);
void				ft_tabdel(char ***tab);
void				ft_inttabdel(int ***tab, int size);
char				*ft_get_digits(char *str);
int					ft_cw_m(char *str, char *del);
char				**ft_strsplit_m(char *s, char *del);
int					ft_tablen(char **tab);

#endif
