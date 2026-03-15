#ifndef DOSYA_H
#define DOSYA_H

// arama sonuclarini tutan yapi
typedef struct {
    int toplam;
    int satir_sayisi;
    int satirlar[500]; // max 500 satir olabilir
} Sonuc;

// dosyayi tarayip sonuclari dolduruyor
int dosyayi_tara(const char *dosya_adi, const char *kelime, Sonuc *s);

#endif
