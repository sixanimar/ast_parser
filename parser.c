#include "parser.h"

void	to_close(FILE **from, FILE **to)
{
	fclose(*from);
	fclose(*to);
}

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
		if (fseek(from, 8, SEEK_CUR) != 0)
		{
			perror("Error seeking file");
			to_close(&from, &to);
			exit (EXIT_FAILURE);
		}

		//read category and size
		if (fread(l_buf, 1, sizeof(l_buf), from) != 3)
		{
			if (ferror(from))
				perror("Error reading");
			else if (feof(from))
				perror("End of file reached");
			to_close(&from, &to);
			exit (EXIT_FAILURE);
		}
		length = l_buf[1] + l_buf[2];

		//alloc buffer size of length
		buffer = malloc((sizeof(unsigned char) * length));
		if (buffer == NULL)
		{
			perror("Error allocating memory");
			to_close(&from, &to);
			exit (EXIT_FAILURE);
		}

		//reset read ptr and read length
		if (fseek(from, -3, SEEK_CUR) != 0)
		{
			perror("Error seeking file");
			to_close(&from, &to);
			free(buffer);
			exit (EXIT_FAILURE);
		}
		if (fread(buffer, 1, length, from) != length)
		{
			if (ferror(from))
				perror("Error reading2");
			else if (feof(from))
				perror("End of file reached2");
			to_close(&from, &to);
			free(buffer);
			exit (EXIT_FAILURE);
		}
	
		//write to new file
		if (fwrite(buffer, 1, length, to) != length)
		{
			perror("Error writing to a file");
			to_close(&from, &to);
			free(buffer);
			exit (EXIT_FAILURE);
		}
		free(buffer);
	}
	fclose(from);
	fclose(to);
	return 0;
}
