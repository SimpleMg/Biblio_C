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

char* gd_strdup(char *str)
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

char* gd_strjoin(char const *s1, char const *s2)
{
    char *ret = (char*)malloc(sizeof(char) * (gd_strlen(s1) + gd_strlen(s2)) + 1);
    int i = 0;
    int j = 0;
    if(ret != NULL)
    {
        while(s1[i])
        {
            ret[i] = s1[i];
            i++;
        }
        while(s2[j])
        {
            ret[i+j] = s2[j];
            j++;
        }
        ret[i+j] = '\0';
        return ret;
    }
    else
    {
        return NULL;
    }
}

void gd_putstr(char *str)
{
    write(1, str, gd_strlen(str));
}

char* gd_reverse_str(char *str)
{
    int len_str = gd_strlen(str);
    char *reverse_str = (char*)malloc(sizeof(char) * len_str + 1);
    int i = 0;
    len_str--;
    while(str[i])
    {
        reverse_str[i] = str[len_str];
        i++;
        len_str--;
    }
    reverse_str[i] = '\0';
    return reverse_str;
}

void gd_putnbr(int nbr)
{
    char *tampon = (char*)malloc(sizeof(char) * 12);
    char* str_nbre = tampon;
    int i = 0;
    if(nbr < 0)
    {
        str_nbre[0] = '-';
        nbr *= -1;
    }
    int tmp = gd_len_nombre(nbr);
    while(tmp > 0)
    {
        char chiff = nbr / tmp + '0';
        str_nbre = gd_strjoin(str_nbre, &chiff);
        nbr %= tmp;
        tmp /= 10;
        i++;
    }
    str_nbre[gd_strlen(str_nbre)] = '\0';
    gd_putstr(str_nbre);
}

int main(void)
{
    gd_putnbr(-25393943);
    gd_putchar('\n');
    int gd = gd_atoi("nhjg129299284ddcdv");
    gd_putnbr(gd);
    gd_putchar('\n');
    char *copy_str = gd_strdup("Hello");
    printf("%s\n", copy_str);
    free(copy_str);
    char *str_join = gd_strjoin("Hello ", "World");
    printf("%s\n", str_join);
    char *reverse_str = gd_reverse_str(str_join);
    printf("%s\n", reverse_str);
    free(reverse_str);
    free(str_join);
}
