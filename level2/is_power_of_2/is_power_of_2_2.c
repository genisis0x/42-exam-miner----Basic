int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
}
