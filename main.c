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

//TARVITTAVAT ALIOHJELMAT
//#include "program.h"
#include "ali1.h"
#include "ali2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

//ENSIN TEHDÄÄN NÄISTÄ KUTSUTTAVIA
int valikko(void);
void kysyTIEDOSTO(char kysymys[], char nimi[]); //TIEDOSTON NIMEN KYSYMINEN
Tila* avaaTIEDOSTO(FILE* tiedosto, char nimiF[], Tila *pAlku);
Tila* kirjoitaTIEDOSTO(FILE* tiedosto, char tiedostoF[], char nimiF[], Tila *pAlku);
Tila* varaaMuistia(Tila *pAlku, char [], int, int, int, int, int, int, int);
void vapautaMuisti(Tila *pAlku);
int analysoiTiedot(Tila *pAlku, char tarkistus[]);


//PÄÄOHJELMA
int main(void) {
    printf("Tämä ohjelma analysoi tilan käyttö -tiedostoja.\n");
    
    Tila *pAlku = NULL;
    char nimiF[MAX];
    int nValinta;
    FILE *tiedosto = NULL;
    
    do {
        nValinta = valikko();
        if (nValinta == 0) {
            vapautaMuisti(pAlku);
            break;
        }
        
        //SEURAAVA HAARA VALIKOSSA
        else if (nValinta == 1) {
            vapautaMuisti(pAlku);
            kysyTIEDOSTO("Anna luettavan tiedoston nimi: ", nimiF);
            printf("Luetaan tiedosto '%s'\n", nimiF);
            
            pAlku = avaaTIEDOSTO(tiedosto, nimiF, pAlku);
            
            
    //SEURAAVA HAARA VALIKOSSA
        }
        else if (nValinta == 2) {
            
            if (pAlku != NULL) {
                kysyTIEDOSTO("Anna opetustilan nimi: ", nimiF); 
                pAlku = kirjoitaTIEDOSTO(tiedosto, "tulostiedot.txt", nimiF, pAlku);
                
            } else {
            printf("Ei tallennettavaa, lue ensin käyttötiedosto.\n");
            }
            
        }
        //SEURAAVA HAARA VALIKOSSA
        else if (nValinta == 3) {
            if (pAlku != NULL) {
                kysyTIEDOSTO("Anna opetustilan nimi: ", nimiF);
                analysoiTiedot(pAlku, nimiF);
            } else {
                printf("Ei analysoitavaa, lue ensin käyttötiedosto.\n");
            }
            
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        
    } while (nValinta != 0);

    printf("Kiitos ohjelman käytöstä.\n\n");
    return 0;

    
}


int valikko() {
    int i;
    printf("\nValitse haluamasi toiminto alla olevasta valikosta:\n");
    printf("1) Lue tilan käyttö -tiedosto\n");
    printf("2) Tallenna listan tiedot\n");
    printf("3) Analysoi tiedot\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &i);
    return i;
}
