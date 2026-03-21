#ifndef ARAMA_H
#define ARAMA_H

#define MOD_KELIME 0
#define MOD_PARCACIK 1

// kelimeyi satirda arar, kac kez gectini dondurur, mod=0 ise tam kelime, mod=1 ise parcacik olarak arar.
int kelime_bul(const char *satir, const char *aranan,int mod);

#endif
