#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	star;
	int	type;
}		t_flags;

int		ft_printf(const char *str, ...);

int		is_type(char c);
int		is_flag(char c);

void	set_dot(t_flags *flags, va_list ap, char *input, int *i);
void	set_minus(t_flags *flags);
void	set_star(t_flags *flags, va_list ap);
void	set_width(t_flags *flags, char *input, int *i);

int		process_types(t_flags *flags, va_list ap, int c);
int		process_char(t_flags *flags, char c);
int		process_str(t_flags flags, char *str);
int		process_point(t_flags flags, unsigned long long addr);
int		process_int(t_flags flags, int i);
int		process_uint(t_flags flags, unsigned int num);
int		process_hex(t_flags flags, unsigned int num, int mode);
int		process_percent(t_flags flags);
int		process_width(int width, int slen, int zero_pad);

int		putstr_max(char *str, int max);
char	*str_tolower(char *str);
char	*ull_to_base(unsigned long long ull, int base);
char	*ui_to_base(unsigned int uint, int base);
char	*ft_ltoa(long n);
char	*ft_uitoa(unsigned int n);

#endif