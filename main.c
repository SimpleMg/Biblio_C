#include <stdio.h>
#include <unistd.h>


void gd_putchar(char c)
{
    write(1, &c, 1);
}

int gd_len_nombre(int nbr)
{
    if(nbr < 0)
    {
        nbr *= -1;
    }
    int longueur = 1;
    while(nbr > 10)
    {
        nbr /= 10;
        longueur *= 10;
    }
    return longueur;
}

void gd_putnbr(int nbr)
{
    int tmp = gd_len_nombre(nbr);
    if(nbr < 0)
    {
        gd_putchar('-');
        nbr *= -1;
    }
    while(tmp > 0)
    {
        gd_putchar(nbr / tmp + '0');
        nbr %= tmp;
        tmp /= 10;
        
    }
}

int gd_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

void gd_putstr(char *str)
{
    write(1 , str, gd_strlen(str));
}

int main()
{
    gd_putnbr(-254);
    gd_putchar('\n');
}
