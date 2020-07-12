#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    switchCase();
}

void switchCase() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Entscheidungsbeispiel\n"
           "Option (2): Finanzierungsvergleich\n"
           "Option (3): KFZ-Rechner\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: entscheidung(); switchCase(); break;
        case 2: finanzierungsVergleich(); switchCase(); break;
        case 3: kfzRechner(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
    }
}

void entscheidung() {
    int zahl1, zahl2;

    printf("Geben Sie eine erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Geben Sie eine zweite Zahl ein: ");
    scanf("%d", &zahl2);

    if(zahl1 > zahl2) {
        printf("\nDie groessere Zahl ist: %d", zahl1);
    } else {
        printf("\nDie groessere Zahl ist: %d", zahl2);
    }
}

void finanzierungsVergleich() {
    float kostenKauf, kostenLeasing, kaufPreis, leasingRate;

    printf("Wie hoch ist die Leasingrate (Euro pro Monat)? ");
    scanf("%f", &leasingRate);
    printf("Wie hoch ist der Kaufpreis (Euro)? ");
    scanf("%f", &kaufPreis);

    kostenKauf = kaufPreis - 1500;
    kostenLeasing = leasingRate * 12 * 5;

    if (kostenKauf <= kostenLeasing) {
        printf("Der Kaufpreis ist um %.2f Euro guenstiger", kostenLeasing-kostenKauf);
    } else {
        printf("Der Leasingpreis ist um %.2f Euro guenstiger", kostenKauf-kostenLeasing);
    }
}

void kfzRechner() {
    int alterFahrer, fahrleistung;
    float grundbetrag, gesamtbetrag;
    char stellplatz[50]; // "ja" stellplatz[0]

    printf("Hier kommt der Grundbetrag rein: ");
    scanf("%f", &grundbetrag);
    printf("Wie alt ist der Fahrer? ");
    scanf("%d", &alterFahrer);
    printf("Wie hoch ist die jaehrliche Fahrleistung in KM? ");
    scanf("%d", &fahrleistung);
    printf("Steht das KFZ in einer Garage? ");
    scanf("%s", &stellplatz);
    fflush(stdin);

    for(int i = 0; stellplatz[i]; i++){
        stellplatz[i] = tolower(stellplatz[i]);
        printf("%d", i);
    }
//    printf("Grundbetrag:%f, Alter:%d, Leistung:%d, Stellplatz:%s \n", grundbetrag, alterFahrer, fahrleistung, stellplatz);
    if (alterFahrer >= 25) {
        gesamtbetrag = grundbetrag - 0.1 * grundbetrag;
    } else {
        gesamtbetrag = grundbetrag + 0.4 * grundbetrag;
    }
//    printf("\nDer Gesamtbetrag betraegt: %.2f", gesamtbetrag);
    if (fahrleistung > 15000) {
        gesamtbetrag += 0.2 * grundbetrag;
    } else {
        gesamtbetrag -= 0.1 * grundbetrag;
    }
//    printf("\nDer Gesamtbetrag betraegt: %.2f", gesamtbetrag);
    if (strcmp(stellplatz,"ja") == 0) {
        gesamtbetrag -= 0.05 * grundbetrag;
    } else {
        gesamtbetrag += 0.05 * grundbetrag;
    }

    printf("\nDer Gesamtbetrag betraegt: %.2f", gesamtbetrag);
}
