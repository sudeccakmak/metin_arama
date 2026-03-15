#include <stdio.h>
#include "rapor.h"

void rapor_yazdir(const char *dosya_adi, const char *kelime, Sonuc *s) {
    int i;

    printf("\n--- Sonuclar ---\n");
    printf("Dosya: %s\n", dosya_adi);

    if (s->toplam == 0) {
        printf("'%s' kelimesi bulunamadi.\n", kelime);
        return;
    }

    printf("Toplam eslesme: %d\n", s->toplam);
    printf("Kac satirda bulundu: %d\n", s->satir_sayisi);

    printf("Satir numaralari: ");
    for (i = 0; i < s->satir_sayisi; i++) {
        printf("%d ", s->satirlar[i]);
    }
    printf("\n");
    printf("----------------\n");
}
