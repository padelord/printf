#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>
#include <float.h>

int		ft_tst(char *s, ...)
{
	va_list	l;
	double n;

	va_start(l, s);
	n = va_arg(l, double);
	va_end(l);
	printf("sizeof(n) : %ld\n", sizeof(n));
	printf("n = \"%f\"\n", n);
	return (n == 0 ? 1 : 0);
}

void printnbits(void *p, int n)
{
	unsigned char	c;
	unsigned char	mask;

	while (n--)
	{
		c = *((unsigned char*)(p + n));
		mask = 128;
		while (mask)
		{
			ft_putchar((mask & c) ? '1' : '0');
			mask >>= 1;
		}
		ft_putchar('\n');
	}
}

unsigned long int	mpow(unsigned int n, unsigned int pow)
{
	unsigned long int r;

	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (n);
	r = n;
	while (--pow)
		r *= n;
	return (r);
}

void pfi(void *f)
{
	unsigned int i;
	int t;
	unsigned int p;

	printf("%3.15f\t", *(float*)f);
	p = *((unsigned int*)f);
	i = 0;
	while (i < 32)
	{
		printf("%c", (p & ((1U << 31) >> i) ? '1' : '0'));
		i++;
		if (i%4==0)
			printf(" ");
	}
	i = 0;
	t = ((p >> 23) & 0xFF) - 127;
	printf("sign\t:%c\texp\t:%d\t", ((1U << 31 & p) ? '-' : '+'), t);
	t = (p & 0b00000000001111111111111111111111);
	printf ("mantis\t:%x\n",t);
}

typedef struct		s_float
{
	unsigned int	mant : 23;
	unsigned int	exp : 8;
	unsigned int	sign : 1;
}					t_float;

typedef	union		u_cor
{
	t_float			data;
	float			f;
}					t_cor;

int main()
{
	float	t;
	t_cor	test;

	printf("sizeof float \t\t: %lu\nsizeof long float \t: %lu\nsizeof long double \t: %lu\n", sizeof(float), sizeof(double), sizeof(long double));

	t = 525.5;
	test.f = 525.5;
	printf("%f\n", test.f);
	printf("sign\t: %c\nexp\t: %d\nmant\t: %x\n",(test.data.sign ? '-' : '+'), (test.data.exp - 127), test.data.mant);
	pfi(&t);
	t = 0.051284;
	pfi(&t);

	t = 50;
	while (t < 33)
	{pfi(&t);
		t++;
	}

	return (0);
}
