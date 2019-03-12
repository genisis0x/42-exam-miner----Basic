void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];

	tab[begin.y][begin.x] = 'F';
    begin.y++;
	if (begin.y < size.y && tab[begin.y][begin.x] == c)
		flood_fill(tab, size, begin);
	begin.y--;
    begin.y--;
	if (begin.y >= 0 && tab[begin.y][begin.x] == c)
		flood_fill(tab, size, begin);
    begin.y++;
    begin.x++;
	if (begin.x < size.x && tab[begin.y][begin.x] == c)
		flood_fill(tab, size, begin);
    begin.x--;
    begin.x--;
	if (begin.x >= 0 && tab[begin.y][begin.x] == c)
		flood_fill(tab, size, begin);
}
