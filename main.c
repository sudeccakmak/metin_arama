#include <stdio.h>
#include <string.h>
#include "arama.h"
#include "dosya.h"
#include "rapor.h"

int main() {
    char kelime[100];
    char dosya_adi[256];
    Sonuc sonuc;
    int devam = 1;

    printf("=== Metin Arama Sistemi ===\n\n");

    // kullanicidan arancak kelimeyi al
    printf("Aranacak kelimeyi girin: ");
    scanf("%s", kelime);

    while (devam) {
        printf("Dosya adini girin (cikmak icin q): ");
        scanf("%s", dosya_adi);

        if (dosya_adi[0] == 'q' && dosya_adi[1] == '\0') {
            devam = 0;
        } else {
            // dosyayi tara
            if (dosyayi_tara(dosya_adi, kelime, &sonuc)) {
                // sonucu yazdir
                rapor_yazdir(dosya_adi, kelime, &sonuc);
            }
        }
    }

    printf("\nProgram bitti.\n");
    return 0;
}
