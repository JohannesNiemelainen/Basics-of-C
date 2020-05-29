/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: Harjoitustyö
 * Tekijä: Johannes Niemeläinen
 * Opiskelijanumero: 0507360
 * Päivämäärä: 19.3.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Kurssimateriaali, internet, Piazza, HARKAT, loistavat tutorit
 *KAKKOSPALAUTUS
 */
/*******************************************************************/

#ifndef ali1_h
#define ali1_h

#define MAX 200
#include <stdio.h>

struct TILA {
    char tilaNimi[MAX];
    int lkm, vuosi, kk, pv, hh, mm;
    long epoch;
    struct TILA *seuraava;
};
typedef struct TILA Tila;

#endif /* ali1_h */
