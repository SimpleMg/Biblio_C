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

int puissance(int nbr, int puissance)
{
    int i = 0;
    int nbr_puissance = 1;
    while(i<puissance)
    {
        nbr_puissance *= nbr;
        i++;
    }
    return nbr_puissance;
}


int gd_len_tab(int *tab, int taille)
{
    return taille / sizeof(tab[0]);
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

int *tri_bulles(int* tab, int taille)
{
    int len_tab = gd_len_tab(tab, taille);
    int i = len_tab - 1;
    int j = 0;
    int tmp = 0;
    while(i >= 1)
    {
        while(j < i)
        {
            if(tab[j+1] < tab[j])
            {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
            j++;
        }
        j = 0;
        i--;
    }
    return tab;
}

int gd_abs(int nbr)
{   
    return (nbr > 0) ? nbr : -nbr;
}

int *gd_tri_insertion(int *tab_int, int taille)
{
    int i = 2;
    int cle = 0;
    int j = 0;
    int len_tab = gd_len_tab(tab_int, taille);
    while(i < len_tab)
    {
        cle = tab_int[i];
        j = i - 1;
        while(j > 0 && tab_int[j] > cle)
        {
            tab_int[j + 1] = tab_int[j];
            j--;
        }
        tab_int[j + 1] = cle;
        i++;
    }
    return tab_int;
}


int main(void)
{
    gd_putstr("putnbr : ");
    gd_putnbr(-25393943);
    gd_putchar('\n');
    gd_putstr("atoi : ");
    int gd = gd_atoi("nhjg129299284ddcdv");
    gd_putnbr(gd);
    gd_putchar('\n');
    char *copy_str = gd_strdup("Hello");
    printf("chaine copier : %s\n", copy_str);
    free(copy_str);
    char *str_join = gd_strjoin("Hello ", "World");
    printf("concatenation de deux chaines : %s\n", str_join);
    char *reverse_str = gd_reverse_str(str_join);
    printf("chaine reverse : %s\n", reverse_str);
    free(reverse_str);
    free(str_join);
    /*TRIE*/
    gd_putstr("TEST DES TRIES\n");
    int i = 0;
    int tab_int[6] = {1,0,3,9,8,3};
    int* trier_tab = gd_tri_insertion(tab_int, sizeof(tab_int));
    gd_putstr("Trie insertion\n");
    while(i < gd_len_tab(tab_int, sizeof(tab_int)))
    {
        printf("%d\n", trier_tab[i]);
        i++;
    }
    int tab_int2[5] = {5,1,4,2,8};
    int *tab_trier = tri_bulles(tab_int2, sizeof(tab_int2));
    i = 0;
    gd_putstr("Trie bulle\n");
    while(i < gd_len_tab(tab_int2, sizeof(tab_int2)))
    {
        printf("%d\n", tab_trier[i]);
        i++;
    }
    /*fin test des trie*/
    gd_putstr("FIN TEST DES TRIES\n");
    int puissance_calc = puissance(2,8);
    printf("puissance de 2^8 : %d\n", puissance_calc);
    printf("valeur abs : %d\n", gd_abs(-8));
    return 0;
    
}
