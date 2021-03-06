/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:30:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/29 13:28:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_FUNCTIONS_H
# define BASIC_FUNCTIONS_H

# define GNL_BUFFER_SIZE 20

void	ft_error(char *error_msg);
void	ft_warning(char *warning_msg);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_without(const char *str, char c);
bool	ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *src, int c);
char	*ft_strrchr(const char *src, int c);
char	*ft_strstr(const char *src, const char *word);
char	*ft_strnstr(const char *src, const char *word, size_t n);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **p);
void	ft_strdel(char **p);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
bool	ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfre(const char *s1, const char *s2,
			int free_s1, int free_s2);
char	*ft_strappend(const char *s1, const char *s2,
			int free_s1, int free_s2);
char	*ft_strprepend(const char *s1, const char *s2,
			int free_s1, int free_s2);

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

char	*ft_strcut_free(char **s1, char delim, int to_free);
char	*ft_strcut(char **s1, char delim);

int		ft_valid_base(char *base_str);
char	*ft_itoa(int n);
char	*ft_utoa_base(uintmax_t n, char *base);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_intlen(intmax_t nb);
size_t	ft_seglen(const char *s, size_t start, int c);
int		ft_tab_len(char **tab);

void	ft_tab_free(char **tab);

bool	ft_strisdigit(char *str);

size_t	ft_count_elems(char const *s, int c);
int		ft_is_white_space(char c);
char	*ft_strrev(char *str);

int		ft_ischar(const char *format, int c);
bool	ft_isonlycharset(const char *format, const char *charset);
bool	ft_isnotonlycharset(const char *format, const char *charset);

char	*ft_strndupfree(const char *src, size_t n, int free_src);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strdupfree(char *src, int free_src);
char	*ft_strdup_no_c(const char *s, char c);
char	*ft_strdup(const char *src);

size_t	ft_strnlen(const char *s, size_t maxlen);

char	*ft_padding(int size, char c);

float	ft_f_abs(float p_value);
float	ft_f_floor(float p_value);
float	ft_f_roof(float p_value);
float	ft_f_round(float p_value);
int		ft_i_abs(int p_value);
int		ft_i_roof(float p_value);

char	*ft_itoa_base(long long int nbr, char *base);
char	*ft_itoa_hexa(long long int nbr);
char	*ft_itoa_octa(long long int nbr);
char	*ft_itoa_unsigned_deci(unsigned int nbr);

size_t	ft_strskip(char *str, char to_skip);

#endif
