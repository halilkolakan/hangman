#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_HATALAR 7

const char *adamAsmacaCizim[MAX_HATALAR] = {
    "  -----\n  |   |\n      |\n      |\n      |\n=========\n",
    "  -----\n  |   |\n  O   |\n      |\n      |\n=========\n",
    "  -----\n  |   |\n  O   |\n  |   |\n      |\n=========\n",
    "  -----\n  |   |\n  O   |\n /|   |\n      |\n=========\n",
    "  -----\n  |   |\n  O   |\n /|\\  |\n      |\n=========\n",
    "  -----\n  |   |\n  O   |\n /|\\  |\n /    |\n=========\n",
    "  -----\n  |   |\n  O   |\n /|\\  |\n / \\  |\n=========\n"
};

int main()
{
    char kelime[20]= "AMPARATOR";
    char gorunen[20];
    char tahmin;

    int uzunluk = strlen(kelime);
    int dogrutahminler = 0 ,hatalar = 0;
    int i,dogruMu;

    for (i = 0; i < uzunluk; i++)
    {
        gorunen[i] = '_';
    }
    gorunen[uzunluk] = '\0';

    printf("----- Adam Asmaca -----\n");
    printf("Kelime: %s\n",gorunen);

    while (hatalar < MAX_HATALAR && dogrutahminler < uzunluk)
    {
        dogruMu = 0;

        printf("Bir harf tahmin edin: ");
        scanf(" %c",&tahmin);
        tahmin  = toupper(tahmin);

        for (i = 0; i < uzunluk; i++)
        {
            if (kelime[i] == tahmin && gorunen[i] == '_')
            {
                gorunen[i] = tahmin;    
                dogrutahminler++;
                dogruMu=1;
            }
            
        }
        
        if (!dogruMu)
        {
            hatalar++;
        }
        
        printf("\n%s",adamAsmacaCizim[hatalar]);
        printf("Kelime: %s\n",gorunen);

    }
    
    if (dogrutahminler == uzunluk)
    {
        printf("Tebrikler kelimeyi bildiniz: %s\n", kelime);
    }
    else
    {
        printf("kaybettiniz! kelime: %s\n",kelime);
    }
    
    return 0;
}