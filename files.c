#include <stdio.h>
#include "files.h"

//Läs in datan från den fil som klienten efterfrågar
//file_path = sökvägen till filen
//buff = vart man skall spara ner datan
//buffsize = storleken på buff, d.v.s hur många byte man kan spara ner i buff
//Retunerar 0 om filen inte finns eller om den för stor för buff
//Retunerar storleken på filen om allting går som det ska
//size_t = en variant av int
size_t get_file(char * file_path, char * buff, size_t buffsize) {
    FILE * file; //En pekare till filen
    size_t nread; //Håller storleken på filen
    
    //Kolla om filen finns
    //Om fopen retunerar NULL betyder det att filen inte finns
    //Annars retunerar den en pekare till filen
    if((file = fopen(file_path, "r")) == NULL)
        return 0;
    
    //Spara ner datan i arrayen buff där varje objekt är 1 byte stort
    //Du får maximalt spara ner buffsize bytes i arrayen
    //Läs från filen file
    nread = fread(buff, 1, buffsize, file);
    
    //Kolla om man har nått slutet av filen
    //Om man inte har gjort det betyder det att filen är för stor för buff
    if(! feof(file))
        return 0;
    
    return nread; //Retunera storleken på filen
}

