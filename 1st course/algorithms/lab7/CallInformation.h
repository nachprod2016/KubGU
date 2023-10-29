#ifndef CALLINFORMATION_H

#define CALLINFORMATION_H

struct CallInformation
{
    char dateCall[11];//дата звонка
    int cityCode;//код города
    char nameCity[20];//название города
    int talkTime;//время разговора
    double rate;//тариф
    long int calledParty;//вызываемый абонент
    long int callingParty;//вызывающий абонент  
};

#endif