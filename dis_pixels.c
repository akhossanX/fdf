
	int		i =  0;
	int		j;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf("(%d, %d)\n", mlx->proj[i][j].x, mlx->proj[i][j].y);	
			j++;
		}
		i++;
	}
