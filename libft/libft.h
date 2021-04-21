/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:35:01 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/09 14:10:17 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__LIBFT_H
# define FT__LIBFT_H

# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 15
# define ABS(Value) ((Value > 0) ? (Value) : (-Value))
# define MASK0 0x0101010101010101UL
# define MASK1 0x8080808080808080UL
# define LONGMASK 7

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_str_is_alpha(char *str);
int				ft_str_is_digit(char *str);
t_list			*ft_list_last(t_list *begin_list);
int				ft_list_size(t_list *begin_list);
void			ft_list_push_back(t_list *begin_list, t_list *new);
int				ft_sum_w(char const *str, char c);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
char			**ft_strsplit(char const *str, char c);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char	(*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
char			*ft_strnew(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalpha(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
char			**ft_splitwhitespaces(char const *str);
void			ft_clean_mass(char **mass);
int				ft_isspace(int c);
size_t			ft_strspn(const char *s, const char *charset);
char			*ft_strndup(const char *s, size_t n);

int				get_next_line(const int fd, char **line);

typedef struct	s_print
{
	int			minus;
	int			plus;
	int			sharp;
	int			null;
	int			afterpoint;
	int			beforepoint;
	int			len;
	int			nullpoint;
	int			space;
	int			number;
	int			star;
	int			mode;
	char		*str;
	char		*str1;
}				t_print;

int				ft_find_null2(t_print *info);
int				ft_find_sharp3(t_print *info);
int				ft_find_plus2(t_print *info);
int				ft_find_minus2(t_print *info);
int				ft_find_space(char *str);

int				ft_printf(const char *restrict format, ...);
void			ft_putsrt(char const *str);
size_t			ft_srtlen(const char *str);
void			ft_make_info(t_print *info, char *str);

int				ft_char_comp(char c);
int				ft_understand(char *str);
char			*ft_type_d(va_list hello, t_print *info);
char			*ft_type_dd(va_list hello);
char			*ft_type_uu(va_list hello, char *str, int len);

int				ft_lets_check(char *str, va_list hello,
		char *surprise);
char			*ft_type_c(va_list hello, t_print *info);
char			*ft_type_o(va_list hello);
char			*ft_type_x(va_list hello);
char			*ft_type_u(va_list hello, t_print *info);
char			*ft_type_p2(va_list hello);
char			*ft_type_s(va_list hello);
void			ft_putnbr2(long long int nb);
char			*ft_itoa2(unsigned long long int n, int sign);

void			ft_print_null(t_print *info);
int				ft_find_null(char *str);
void			ft_find_sharp2(t_print *info);
int				ft_find_sharp(t_print *info, char c);
void			ft_print_sharp(t_print *info, char c);
void			ft_find_plus(t_print *info);
char			*ft_print_plus(char *str1, int plus, int flag);
int				ft_find_minus(char *str);
void			ft_swap_str(t_print *info);
void			ft_glue_space(t_print *info);

char			*ft_wide_diouxx(t_print *info, char c);
char			*ft_wide_f(t_print *info);

char			*ft_wide_s(t_print *info);
void			ft_find_a_and_b(t_print *info);
char			*ft_join_a(int afterpoint, char *str1, char *join, int a);
char			*ft_join_b(t_print *info, char *join);
char			*ft_join_b_junior(t_print *info, char *join, int k);
char			*ft_join_s_a(int afterpoint, char *str1);
char			*ft_join_s_b(int beforepoint, char *join);

char			*ft_conv_octal(unsigned long long int n);
char			*ft_conv_six(unsigned long long int n, char c);
char			*ft_strrev(char *str);
void			ft_print_memory(const void *addr, size_t size);
void			print_hex(unsigned char value, int index);
void			print_ascii(const char *addr, int i);
char			*print_address_hex(void *p0);
char			*ft_type_p(va_list hello, t_print *info);
char			*ft_join_a_for_p(int afterpoint, char *str1,
		char *join, int a);
char			*ft_type_f(va_list hello, t_print *info);
char			*ft_type_f_double(va_list hello, t_print *info);
char			*ft_itoa_float(double d, int z);
char			*ft_itoa_float_long(long double d, int z);
char			*ft_type_f_long_double(va_list hello, t_print *info);
char			*ft_approx(char *str, int a);
char			*ft_infinity(double d, t_print *info);
void			ft_read(t_print *info, va_list hello);
char			*ft_make_star2(t_print *info, char *str, va_list hello);
void			ft_sharp_o(t_print *info, char c);
char			*ft_not_only_null(char *str1, int plus);
int				ft_space_only(char *str);
char			*ft_twice_symb(t_print *info, char c, int i);
int				ft_k_4_u(va_list hello, const char *format, int *i);
void			ft_k_4_me(const char *format, int *j, int *return_value);
char			*ft_sputni_check(int n, char *format_i);
void			ft_k(const char *format, int *i,
		int *return_value, va_list hello);

#endif
