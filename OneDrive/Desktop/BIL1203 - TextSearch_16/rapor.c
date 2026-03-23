#include <stdio.h>
#include <direct.h>
#include "rapor.h"
 
void rapor_yazdir(const char *dosya_adi, const char *kelime, Sonuc *s) {
    int i;
    char cwd[256];
 
    _getcwd(cwd, sizeof(cwd));
    printf("[BILGI] Calisma dizini: %s\n", cwd);
 
    FILE *rf = fopen("sonuc.txt", "a");
    if (rf == NULL) {
        perror("sonuc.txt acilamadi");
    } else {
        printf("[BILGI] sonuc.txt yaziliyor: %s\\sonuc.txt\n", cwd);
    }
 
    printf("\n--- Sonuclar ---\n");
    printf("Dosya: %s\n", dosya_adi);
 
    if (s->toplam == 0) {
        printf("'%s' kelimesi bulunamadi.\n", kelime);
        if (rf) fprintf(rf, "Dosya: %s | '%s' bulunamadi.\n", dosya_adi, kelime);
    } else {
        printf("Toplam eslesme: %d\n", s->toplam);
        printf("Kac satirda bulundu: %d\n", s->satir_sayisi);
        printf("Satir numaralari: ");
        for (i = 0; i < s->satir_sayisi; i++) printf("%d ", s->satirlar[i]);
        printf("\n");
 
        if (rf) {
            fprintf(rf, "Dosya: %s | Aranan: '%s' | Eslesme: %d | Satirlar: ", dosya_adi, kelime, s->toplam);
            for (i = 0; i < s->satir_sayisi; i++) fprintf(rf, "%d ", s->satirlar[i]);
            fprintf(rf, "\n");
        }
    }
 
    printf("----------------\n");
    if (rf) fclose(rf);
}