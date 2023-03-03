#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

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
    /*TEST TRIS*/
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
    int tab_int2[5] = {5,1,4,2,4};
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
    mg_putstr("LIST CHAINE\n");
    List *list1 = mg_initialisation_liste();
    i = 0;
    while(i < mg_len_tab(tab_int2, sizeof(tab_int2)))
    {
        list1 = mg_ajouter_element(list1, tab_trier[i]);
        i++;   
    }

    mg_putList(list1);
    list1 = mg_freeList(list1);
    
    return 0;
    
}
