#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arama.h"

// buyuk kucuk harf farketmesin diye her iki stringi de kucuk harfe cevirip karsilastiriyoruz
int kelime_bul(const char *satir, const char *aranan) {
    char s[1024];
    char k[100];
    int i = 0;
    int sayac = 0;

    // satiri kucuk harfe cevir
    while (satir[i] != '\0') {
        s[i] = tolower(satir[i]);
        i++;
    }
    s[i] = '\0';

    // aranan kelimeyi kucuk harfe cevir
    i = 0;
    while (aranan[i] != '\0') {
        k[i] = tolower(aranan[i]);
        i++;
    }
    k[i] = '\0';

    // satirda kelimeyi ara
    int klen = strlen(k);
    char *ptr = s;

    while ((ptr = strstr(ptr, k)) != NULL) {
        // tam kelime mi kontrol et
        int bas = (ptr == s) || !isalnum(*(ptr - 1));
        int son = !isalnum(*(ptr + klen));

        if (bas && son) {
            sayac++;
        }
        ptr++;
    }

    return sayac;
}
