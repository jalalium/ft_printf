/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:34:37 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 21:52:36 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data
{
	char			*str;
	long			adr;
	long long		val;
	long double		flt;
}					t_data;
int					ft_putstr_mod(char *str, int *tab);
int					ft_putchar_mod(int c);
int					ft_printf(const char *format, ...);
int					ft_hex_mod(unsigned long long nb, int *tab);
int					ft_hex_length_mod(unsigned long long nb, int *tab,
		int state);
int					ft_oct_mod(unsigned long long nb, int *tab);
int					ft_oct_length_mod(unsigned long long nb, int *tab,
		int state);
int					ft_putnbr_s_mod(long long nb, int *tab);
int					ft_length_s_mod(long long nb, int *tab, int state);
int					ft_putnbr_un_mod(unsigned long long n, int *tab);
int					ft_length_un_mod(unsigned long long nb, int *tab);
int					ft_lenunicode(int n);
int					ft_putunicode(int n);
int					ft_lenunistr(char *str, int *p);
int					ft_putunistr(char *str, int *p);
unsigned long long	**powsfive();
unsigned long long	pw_f(int x);
unsigned long long	pw_t(int x);
unsigned long long	pow_two(int x);
char				*pr_ldbl(long double x);
char				*pr_flt(float x);
char				*pr_dbl(double x);
unsigned long long	*ft_getfrac_dbl(double flo);
unsigned long long	*ft_getdouble(double flo);
int					ft_lendbl(double num, int prec);
int					ft_putdbl(double num, int prec);
unsigned long long	*ft_getfrac_ldbl(long double flo);
unsigned long long	*ft_getldouble(long double flo);
int					ft_putldbl(long double num, int prec);
int					ft_lenldbl(long double num, int prec);
int					ft_lenfloat_mod(long double nb, int *tab);
int					ft_putfloat_mod(long double nb, int *tab);
int					ft_putnbr_s(int n, int *tab);
int					ft_length_s(int n, int *tab, int state);
int					ft_putnbr_s_hh(char n, int *tab);
int					ft_length_s_hh(char n, int *tab, int state);
int					ft_putnbr_s_j(intmax_t n, int *tab);
int					ft_length_s_j(intmax_t n, int *tab, int state);
int					ft_length_s_h(short n, int *tab, int state);
int					ft_putnbr_s_h(short n, int *tab);
int					ft_putnbr_s_l(long n, int *tab);
int					ft_length_s_l(long n, int *tab, int state);
int					ft_putnbr_s_ll(long long n, int *tab);
int					ft_length_s_ll(long long n, int *tab, int state);
void				carrying(unsigned long long **tum);
void				geometric_sum_ldbl(char *s, unsigned long long **t);
void				nothingness_ldbl(char *s, unsigned long long **t);
int					ft_hex_hh(unsigned char nb, int *tab);
int					ft_hex_h(unsigned short nb, int *tab);
int					ft_hex_u(unsigned int nb, int *tab);
int					ft_hex_ll(unsigned long long nb, int *tab);
int					ft_hex_l(unsigned long nb, int *tab);
int					ft_hex_j(uintmax_t nb, int *tab);
int					ft_hex_length_hh(unsigned char n, int *tab, int state);
int					ft_hex_length_h(unsigned short n, int *tab, int state);
int					ft_hex_length_u(unsigned int n, int *tab, int state);
int					ft_hex_length_j(uintmax_t n, int *tab, int state);
int					ft_hex_length_ll(unsigned long long n, int *tab, int state);
int					ft_hex_length_l(unsigned long n, int *tab, int state);
int					ft_oct_hh(unsigned char nb, int *tab);
int					ft_oct_h(unsigned short nb, int *tab);
int					ft_oct_u(unsigned int nb, int *tab);
int					ft_oct_ll(unsigned long long nb, int *tab);
int					ft_oct_l(unsigned long nb, int *tab);
int					ft_oct_j(uintmax_t nb, int *tab);
int					ft_oct_length_hh(unsigned char n, int *tab, int state);
int					ft_oct_length_h(unsigned short n, int *tab, int state);
int					ft_oct_length_u(unsigned int n, int *tab, int state);
int					ft_oct_length_j(uintmax_t n, int *tab, int state);
int					ft_oct_length_ll(unsigned long long n, int *tab, int state);
int					ft_oct_length_l(unsigned long n, int *tab, int state);
int					ft_putnbr_un_hh(unsigned char n, int *tab);
int					ft_putnbr_un_h(unsigned short n, int *tab);
int					ft_putnbr_un(unsigned int n, int *tab);
int					ft_putnbr_un_j(uintmax_t n, int *tab);
int					ft_putnbr_un_l(unsigned long n, int *tab);
int					ft_putnbr_un_ll(unsigned long long n, int *tab);
int					ft_length_un_hh(unsigned char n, int prec);
int					ft_length_un_h(unsigned short n, int prec);
int					ft_length_un(unsigned int n, int prec);
int					ft_length_un_j(uintmax_t n, int prec);
int					ft_length_un_l(unsigned long n, int prec);
int					ft_length_un_ll(unsigned long long n, int prec);
int					ft_isconver(char c);
int					flags_det(int **tap, int i, const char *s);
int					minwidth_det(int **tap, int i, const char *s, va_list ap);
int					prec_det(int **tap, int i, const char *s, va_list ap);
int					convers_det(int **tap, int i, const char *s);
void				ft_same(int **t);
void				ft_adjust(int **t);
int					ft_strlen_mod(char *str, int *tab);
int					conv_data(int c);
int					ident(int *tab);
int					ft_id();
int					ft_space_left(int **t, int len, int state);
int					ft_space_right(int *tab, int len);
int					errors_det(int *tab, int state);
int					spec_cases(int conv);
t_data				get_data(va_list ap, int *tab, int s);
int					len_mod(int *tab, t_data data_p, int state);
int					get_state(int *tab);
int					count_skip(int *tab);
int					ft_putunicode_one(int n);
int					ft_putunicode_two(int n);
int					ft_putunicode_three(int n);
int					ft_putunicode_four(int n);
t_data				blank_node(void);
void				carryfracldbl(unsigned long long **t, int j);
int					ft_len_bin(int nb);
int					ft_binary(int nb);
char				**inport_spec_strings(void);
char				**inport_spec_lstrings(void);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_log(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(int n);
int					ft_pow(int r);
#endif
