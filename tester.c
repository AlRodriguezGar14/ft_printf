#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	ft_printf("%%%c%%", 'x');
	printf("\n");
	ft_printf("dgs%Xxx", 10);
	printf("\n");

	return(0);
}

// int main (void)
// {
// 	int		total;
// 	char	*harry;
// 	char	caracter;
// 	int		i;
// 	int		j;


// 	printf("---------TEST %%u-POSITIVO----------\n");
// 	total = 120;
// 	i = printf("ORIGINAL: %u\n", total);
// 	j = ft_printf("MIO: %u\n", total);

// 	printf("---------TEST %%u-NEGATIVO----------\n");
// 	total = -120;
// 	i = printf("ORIGINAL: %u\n", total);
// 	j = ft_printf("MIO: %u\n", total);
	
// 	printf("\n");
// 	printf("---------TEST %%d-ORIGINAL----------\n");

// 	total = printf("hola\n");
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%d-MIO----------\n");

// 	total = ft_printf("hola\n");
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%i-ORIGINAL----------\n");

// 	total = printf("mundo\n");
// 	i = printf("ORIGINAL: %i\n", total);
// 	j = ft_printf("MIO: %i\n", total);

// 	printf("\n");
// 	printf("---------TEST %%i-MIO----------\n");

// 	total = ft_printf("mundo\n");
// 	i = printf("ORIGINAL: %i\n", total);
// 	j = ft_printf("MIO: %i\n", total);

// 	printf("\n");
// 	printf("---------TEST %%s-ORIGINAL-----------\n");

// 	harry = "believe";
// 	total = printf("%s\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%s-MIO-----------\n");

// 	total = ft_printf("%s\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%s-ORIGINAL-----------\n");

// 	harry = NULL;
// 	total = printf("%s\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%s-ORIGINAL-----------\n");

// 	total = ft_printf("%s\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%c-ORIGINAL-----------\n");

// 	caracter = 'a';
// 	total = printf("%c\n", caracter);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%c-MIO-----------\n");

// 	total = ft_printf("%c\n", caracter);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%p-ORIGINAL-----------\n");

// 	harry = "believe";
// 	total = printf("%p\n", harry);
// 	total = ft_printf("%p\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%p-MIO-----------\n");

// 	total = ft_printf("%p\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%p-ORIGINAL-----------\n");

// 	harry = NULL;
// 	total = printf("%p\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%p-MIO-----------\n");

// 	total = ft_printf("%p\n", harry);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%x-ORIGINAL-----------\n");

// 	total = 42;
// 	total = printf("%x\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%x-MIO-----------\n");

// 	total = 42;
// 	total = ft_printf("%x\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%x-ORIGINAL-----------\n");

// 	total = 0;
// 	total = printf("%x\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%x-MIO-----------\n");

// 	total = 0;
// 	total = ft_printf("%x\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%X-ORIGINAL-----------\n");

// 	total = 42;
// 	total = printf("%X\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%X-MIO-----------\n");

// 	total = 42;
// 	total = ft_printf("%X\n", total);
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%-ORIGINAL-----------\n");

// 	total = printf("%%\n");
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);

// 	printf("\n");
// 	printf("---------TEST %%-MIO-----------\n");

// 	total = ft_printf("%%\n");
// 	i = printf("ORIGINAL: %d\n", total);
// 	j = ft_printf("MIO: %d\n", total);
// }