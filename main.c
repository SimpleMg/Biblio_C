#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gd_putchar(char c)
{
    write(1, &c, 1);
}

int gd_strlen(const char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char* str_dup(const char *str)
{
    char *ret = (char*)malloc(sizeof(char) * gd_strlen(str + 1));
    if(ret != NULL)
    {
        int i = 0;
        while(str[i])
        {
            ret[i] = str[i];
            i++;
        }
        ret[i] = '\0';
        return ret;
    }
    else
    {
        return NULL;
    }
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
    int nega = 1;
    int nbr = 0;
    i = 0;
    while(str[i])
    {
        i++;
        if(str[i] >= '0' && str[i] <= '9')
        {
            nbr = (nbr * 10) + (str[i] - '0');
            
        }
        else if(str[i] == '-')
        {
            nega = -1;
        }
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
    int gd = gd_atoi("nhjg129299284ddcdv");
    gd_putnbr(gd);
    gd_putchar('\n');
    char *copy_str = str_dup("Hello World");
    printf("%s\n", copy_str);
    free(copy_str);
    
}
