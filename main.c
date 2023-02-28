#include <stdio.h>
#include <unistd.h>

void gd_putchar(char c)
{
    write(1, &c, 1);
}

int gd_len_nombre(int nbr)
{
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
    if(nbr<0)
    {
        gd_putchar('-');
        nbr *= -1;
    }
    int tmp = gd_len_nombre(nbr);
    while(tmp > 0)
    {
        gd_putchar(nbr/tmp + '0');
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

int puissance_10(int nbr)
{
    int i = 1;
    int res = 1;
    while(i<nbr)
    {
        res *= 10;
        i++;
    }
    return res;
}
int gd_atoi(char *str)
{

    int i = 0;
    int nbr = 0;
    int nega = 1;
    while((str[i] == '-') || (str[i] >= '0' && str[i] <= '9'))
    {
        if(str[i] == '-')
        {
            nega = -1;
        }
        i++;
    }
    int j = 0;
    if(nega == -1)
    {
        i--;
        j = 1;
    }
    int len;
    len = puissance_10(i);
    while(str[j] >= '0' && str[j] <= '9')
    {
        nbr += (str[j] - '0') * len;
        len /= 10;
        j++;
    }
    return nbr * nega;
}

void gd_putstr(char *str)
{
    write(1, str, gd_strlen(str));
}

int main()
{
    gd_putnbr(-254);
    gd_putchar('\n');
    int gd = gd_atoi("-129299284ddcdv");
    gd_putnbr(gd);
    gd_putchar('\n');
}
