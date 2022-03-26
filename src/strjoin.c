#include "parser.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		f;
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p)
	{
		i = 0;
		f = 0;
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		while (s2[f])
		{
			p[i] = s2[f];
			i++;
			f++;
		}
		p[i] = 0;
		return (p);
	}
	return (0);
}
