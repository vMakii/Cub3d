/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:40:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 14:45:51 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// struct
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// libft
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t n, size_t size);
void		ft_freetab(char **tab);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isnum(char *str);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strdup(const char *src);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
char		*ft_strrchr(const char *str, int c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
void		*ft_memchr(const void *block, int c, size_t n);
void		*ft_memset(void *ptr, int value, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void		ft_print_tab(char **tab);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_tabcpy(char **src);
int			ft_tablen(char **tab);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_count_word(char const *s, char sep);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
// bonus
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf
int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putvoid(void *ptr);
int			ft_putunbr(unsigned int n);
int			ft_puthexa(unsigned int n, const char type);

// get_next_line
char		*get_next_line(int fd, int n);
char		*ft_strjoin_free(char *s1, char const *s2);
// bonus
char		*get_next_line_bonus(int fd);
#endif
