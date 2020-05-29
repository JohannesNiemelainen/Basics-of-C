/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: Harjoitustyö
 * Tekijä: Johannes Niemeläinen
 * Opiskelijanumero: 0507360
 * Päivämäärä:  19.3.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Kurssimateriaali, internet, Piazza, HARKAT, loistavat tutorit
 *KAKKOSPALAUTUS
 */
/*******************************************************************/

#include "ali1.h"
#include "ali2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//TÄSSÄ VARATAAN MUISTI KAIKKIA TIETOJA VARTEN JA TEHDÄÄN LINKITETTY LISTA;
Tila *varaaMuistia(Tila *pAlku, char tilat[], long eEPOCH, int vVUOSI, int kkKK, int pvPV, int hhHH, int mmMM, int lLKM, Tila *pLoppu) {
    Tila *pUusi;
     if ((pUusi = (Tila *)malloc(sizeof(Tila))) == NULL) {

         perror("Muistinvaraus epäonnistui");
         exit(1);
     }
        strncpy(pUusi->tilaNimi, tilat, MAX-1);
        pUusi->epoch = eEPOCH;
        pUusi->vuosi = vVUOSI;
        pUusi->kk = kkKK;
        pUusi->pv = pvPV;
        pUusi->hh= hhHH;
        pUusi->mm = mmMM;
        pUusi->lkm = lLKM;
        pUusi->seuraava = NULL;
        if (pAlku == NULL)
            pAlku = pUusi;
        else {
            pLoppu->seuraava = pUusi;
        }
        return pUusi;
    
}

//TÄSSÄ VAPAUTETAAN LOPUKSI MUISTI, ALIOHJELMA
void vapautaMuisti(Tila *pAlku) {
    if (pAlku != NULL) {
        Tila *pTemp=pAlku;
        while (pTemp != NULL) {
            pAlku = pTemp->seuraava;
            free(pTemp);
            pTemp = pAlku;
        }
    }
}



// TIETOJEN ANALYSOINTI, RIITTÄÄKÖ ETTÄ ON YHTEENSÄ / ALKIO
void analysoiTiedot(Tila *pAlku, char tarkistus[]) {
    int minimi = 8888, maksimi = 0;
    int yhteensa = 0;
    int alkio = 0;
    
    if (pAlku != NULL) {
        Tila *pTemp=pAlku;
        while (pTemp != NULL) {
            if ((strcmp(pTemp->tilaNimi, tarkistus) == 0)) {
            
                yhteensa = yhteensa + (pTemp->lkm);
                alkio++;
                if (maksimi < (pTemp->lkm)) {
                    maksimi = pTemp->lkm;
                }
                if (minimi > (pTemp->lkm)) {
                    minimi = pTemp->lkm;
                }
            } pTemp = pTemp->seuraava;
        }
        
        printf("Opetustilan %s käyttöanalyysi, %d alkiota:\n", tarkistus, alkio);
        printf("  Avg  Min  Max\n");
        printf("%5d%5d%5d\n", (yhteensa/alkio), minimi, maksimi);
        
    }
}
