#include <stdio.h>
#include <string.h>
#include "dosya.h"
#include "arama.h"

int dosyayi_tara(const char *dosya_adi, const char *kelime, Sonuc *s, int mod) {
    FILE *f;
    char satir[1024];
    int satir_no = 0;
    int adet;

    // baslangicta sifirla
    s->toplam = 0;
    s->satir_sayisi = 0;

    f = fopen(dosya_adi, "r");
    if (f == NULL) {
        printf("Dosya acilamadi: %s\n", dosya_adi);
        return 0;
    }

    // dosyayi satir satir oku
    while (fgets(satir, sizeof(satir), f) != NULL) {
        satir_no++;
        adet = kelime_bul(satir, kelime,mod);

        if (adet > 0) {
            s->toplam += adet;
            s->satirlar[s->satir_sayisi] = satir_no;
            s->satir_sayisi++;
        }
    }

    fclose(f);
    return 1;
}
