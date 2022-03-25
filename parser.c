#include "parser.h"

int	main(int argc, char **argv)
{
	unsigned char	l_buf[3];
	unsigned char	*buffer;
	FILE			*from;
	FILE			*to;
	int				length;

	if (argc != 2)
	{
		write(1, "Wrong number of arguments\n", sizeof("Wrong number of arguments\n"));
		exit (EXIT_FAILURE);
	}

	from = fopen(argv[1], "rb");
	to = fopen(ft_strjoin("small_", argv[1]), "wb");

	if (from == NULL || to == NULL)
	{
		unlink(ft_strjoin("small_", argv[1]));
		perror("Error opening files");
		exit (2);
	}

	
	while(!feof(from))
	{
		//SKIP PRE
		fseek(from, 8, SEEK_CUR);

		//read category and size
		fread(l_buf, sizeof(l_buf), 1, from);
		length = l_buf[1] + l_buf[2];

		//alloc buffer size of length
		buffer = malloc((sizeof(unsigned char) * length));

		//reset read ptr and read length
		fseek(from, -3, SEEK_CUR);
		fread(buffer, length, 1, from);
	
		//write to new file
		fwrite(buffer, length, 1, to);

		free(buffer);
	}
	fclose(from);
	fclose(to);
	return 0;
}
