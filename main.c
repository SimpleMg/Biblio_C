#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void mg_putchar(char c)
{
    write(1, &c, 1);
}

int mg_strlen(const char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char* mg_strdup(char *str)
{
    char *ret = (char*)malloc(sizeof(char) * mg_strlen(str + 1));
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


int mg_len_nombre(int nbr)
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


int mg_len_tab(int *tab, int taille)
{
    return taille / sizeof(tab[0]);
}

int mg_atoi(char *str)
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


char* mg_strjoin(char const *s1, char const *s2)
{
    char *ret = (char*)malloc(sizeof(char) * (mg_strlen(s1) + mg_strlen(s2)) + 1);
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


void mg_putstr(char *str)
{
    write(1, str, mg_strlen(str));
}

char* mg_reverse_str(char *str)
{
    int len_str = mg_strlen(str);
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


void mg_putnbr(int nbr)
{
    char *tampon = (char*)malloc(sizeof(char) * 12);
    char* str_nbre = tampon;
    int i = 0;
    if(nbr < 0)
    {
        str_nbre[0] = '-';
        nbr *= -1;
    }
    int tmp = mg_len_nombre(nbr);
    while(tmp > 0)
    {
        char chiff = nbr / tmp + '0';
        str_nbre = mg_strjoin(str_nbre, &chiff);
        nbr %= tmp;
        tmp /= 10;
        i++;
    }
    str_nbre[mg_strlen(str_nbre)] = '\0';
    mg_putstr(str_nbre);
}

int *mg_tri_bulles(int* tab, int taille)
{
    int len_tab = mg_len_tab(tab, taille);
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

int mg_abs(int nbr)
{   
    return (nbr > 0) ? nbr : -nbr;
}

int mg_isdigit(char nbr)
{
    return (nbr >= '0' && nbr <= '9') ? 1 : 0;
}

int *mg_tri_insertion(int *tab_int, int taille)
{
    int i = 1;
    int cle = 0;
    int j = 0;
    int len_tab = mg_len_tab(tab_int, taille);
    while(i < len_tab)
    {
        cle = tab_int[i];
        j = i - 1;
        while(j >= 0 && tab_int[j] > cle)
        {
            tab_int[j + 1] = tab_int[j];
            j--;
        }
        tab_int[j + 1] = cle;
        i++;
    }
    return tab_int;
}

int mg_max_tab(int *tab, int taille)
{
    int len_tab = mg_len_tab(tab, taille);
    int i = 0;
    int max = tab[0];
    while(i < len_tab)
    {
        if(tab[i] > max)
        {
            max = tab[i];
        }
        i++;
    }
    return max;
    
}

int mg_min_tab(int *tab, int taille)
{
    int len_tab = mg_len_tab(tab, taille);
    int i = 0;
    int min = tab[0];
    while(i < len_tab)
    {
        if(tab[i] < min)
        {
            min = tab[i];
        }
        i++;
    }
    return min;
    
}

void mg_affiche_alphabet(void)
{
    char lettre = 'a';
    while(lettre <= 'z')
    {
        mg_putchar(lettre);
        lettre++;
    }
}

void mg_reverse_alphabet(void)
{
    char lettre = 'z';
    while(lettre >= 'a')
    {
        mg_putchar(lettre);
        lettre--;
    }
}

void mg_affiche_chiffre(void)
{
    char chiffre = '0';
    while(chiffre <= '9')
    {
        mg_putchar(chiffre);
        chiffre++;
    }
}

int mg_isneg(int nbr)
{
    return (nbr < 0) ? 1 : 0;
}

int mg_ispalindrome(char *str)
{
    char *duplique = mg_strdup(str);
    duplique = mg_reverse_str(duplique);
    int i = 0;
    while(i < mg_strlen(str))
    {
        if(str[i] != duplique[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(void)
{
    mg_putstr("putnbr : ");
    mg_putnbr(-25393943);
    mg_putchar('\n');
    mg_putstr("atoi : ");
    int gd = mg_atoi("nhjg129299284ddcdv");
    mg_putnbr(gd);
    mg_putchar('\n');
    char *copy_str = mg_strdup("Hello");
    printf("chaine copier : %s\n", copy_str);
    free(copy_str);
    char *str_join = mg_strjoin("Hello ", "World");
    printf("concatenation de deux chaines : %s\n", str_join);
    char *reverse_str = mg_reverse_str(str_join);
    printf("chaine reverse : %s\n", reverse_str);
    free(reverse_str);
    free(str_join);
    /*TRIS*/
    mg_putstr("TEST DES TRIS\n");
    int i = 0;
    int tab_int[6] = {1,0,3,9,8,3};
    int* trier_tab = mg_tri_insertion(tab_int, sizeof(tab_int));
    mg_putstr("Tri insertion\n");
    while(i < mg_len_tab(tab_int, sizeof(tab_int)))
    {
        printf("%d\n", trier_tab[i]);
        i++;
    }
    int tab_int2[5] = {5,1,4,2,8};
    int *tab_trier = mg_tri_bulles(tab_int2, sizeof(tab_int2));
    i = 0;
    mg_putstr("Tri bulle\n");
    while(i < mg_len_tab(tab_int2, sizeof(tab_int2)))
    {
        printf("%d\n", tab_trier[i]);
        i++;
    }
    /*fin test des tris*/
    mg_putstr("FIN TEST DES TRIS\n");
    int puissance_calc = puissance(2,8);
    printf("puissance de 2^8 : %d\n", puissance_calc);
    printf("valeur abs : %d\n", mg_abs(-8));
    char test_digit = '9';
    printf("%d is digit : \n", test_digit);
    (mg_isdigit(test_digit)) ? mg_putstr("oui\n") : mg_putstr("non\n");
    int tab_int3[5] = {1,8,10,182,2};
    printf("max : %d\n", mg_max_tab(tab_int3, sizeof(tab_int3)));
    printf("min : %d\n", mg_min_tab(tab_int3, sizeof(tab_int3)));
    mg_putstr("ALPHABET\n");
    mg_affiche_alphabet();
    mg_putchar('\n');
    mg_putstr("ALPHABET INVERSE\n");
    mg_reverse_alphabet();
    mg_putchar('\n');
    mg_putstr("CHIFFRES\n");
    mg_affiche_chiffre();
    mg_putchar('\n');
    int test_isneg = -9;
    printf("%d est négatif ?\n", test_isneg);
    (mg_isneg(test_isneg)) ? mg_putstr("OUI\n") : mg_putstr("NON\n");
    char *is_plaindrome = "kayak";
    printf("%s est un Palindrome\n", is_plaindrome);
    (mg_ispalindrome(is_plaindrome)) ? mg_putstr("oui\n") : mg_putstr("non\n");
    return 0;
    
}
