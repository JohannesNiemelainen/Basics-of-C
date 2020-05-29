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

#include "ali1.h"
#include "ali2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

Tila *varaaMuistia(Tila *pAlku, char tilat[], long eEPOCH, int vVUOSI, int kkKK, int pvPV, int hhHH, int mmMM, int lLKM, Tila *pLoppu);


void kysyTIEDOSTO(char kysymys[] ,char nimi[]) {
    printf("%s", kysymys);
    scanf("%s", nimi);
}

 Tila* avaaTIEDOSTO(FILE* tiedosto, char nimiF[], Tila *pAlku) {
     char riviTALTEEN[MAX];
     char tilat[MAX];
     char *tilat2;
     Tila *pLoppu = pAlku;
     int lLKM = 0;
     int eEPOCH = 0;
     int vVUOSI = 0;
     int kkKK = 0;
     int pvPV = 0;
     int hhHH = 0;
     int mmMM = 0;
     int rivi = 0;
     
     if ((tiedosto = fopen(nimiF, "r")) != NULL) {
        fgets(riviTALTEEN, MAX, tiedosto);
            
            while (fgets(riviTALTEEN, MAX, tiedosto) != NULL) {
            
                    tilat2 = strtok(riviTALTEEN, ";");
                    strncpy(tilat, tilat2, MAX);
                
                    tilat2 = strtok(NULL, ";");
                    eEPOCH = atoi(tilat2);
                
                    tilat2 = strtok(NULL, ";");
                    pvPV = atoi(tilat2);
                
                    tilat2 = strtok(NULL, ";");
                    kkKK = atoi(tilat2);
                
                    tilat2 = strtok(NULL, ";");
                    vVUOSI = atoi(tilat2);
                
                    tilat2 = strtok(NULL, ";");
                    hhHH = atoi(tilat2);
                
                    tilat2 = strtok(NULL, ";");
                    mmMM = atoi(tilat2);
                
                    tilat2 = strtok(NULL, "\n");
                    lLKM = atoi(tilat2);
                
                    pLoppu = varaaMuistia(pAlku, tilat, eEPOCH, vVUOSI, kkKK, pvPV, hhHH, mmMM, lLKM, pLoppu);
                
                    if (pAlku == NULL) {
                        pAlku = pLoppu;
                }
                rivi++;
            }
            printf("Tiedosto '%s' luettu, %d riviä.\n", nimiF, rivi);
            fclose(tiedosto);
        
        return pAlku;
         
    } else {
        perror("Tiedoston lukeminen epäonnistui");
        exit(0);
    }
}


Tila* kirjoitaTIEDOSTO(FILE* tiedosto, char tiedostoF[], char nimiF[], Tila *pAlku) {
    if ((tiedosto = fopen(tiedostoF, "w")) != NULL) {
        fprintf(tiedosto, "Opetustila: %s\nPvm Klo Lkm\n", nimiF);
        Tila *pTemp = pAlku;
        while (pTemp != NULL) {
                if ((strcmp(pTemp->tilaNimi, nimiF) == 0)) {
                        fprintf(tiedosto, "%d.%d.%d %02d:%02d %d\n", pTemp->pv, pTemp->kk, pTemp->vuosi, pTemp->hh, pTemp->mm, pTemp->lkm);
                    }
                pTemp = pTemp->seuraava;
                }
            printf("Käyttödata tallennettu.\n");
            fclose(tiedosto);
        
        return pAlku;
        
    } else {
        perror("Tiedostoon kirjoittaminen epäonnistui");
        exit(0);
    }
}
