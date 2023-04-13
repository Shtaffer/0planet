#include "CNumber.h"
#include <cmath>
#include <cstdio>

CNumber::CNumber(double seed)
{
    r = seed;
    //hashData[HASH_SIZE] = {0};
}

CNumber::~CNumber()
{

}

void CNumber::setSeed(double seed)
{
    r = seed;
}

double CNumber::Next()
{
    r = modf(r*11 + M_PI, &r);
    //printf("%f\n", r);
    return r;
}

double CNumber::NextSize(int planetType)
{
    r = modf(r*11 + M_PI, &r);
    double Result = r;
    switch(planetType)
    {
    //case HOT:
    case 0:
        while(Result < 3)
            Result += 0.5;
        while(Result > 5)
            Result -= 0.5;
        break;
    //case EARTH:
    case 1:
        while(Result < 4)
            Result += 0.5;
        while(Result > 6)
            Result -= 0.5;
        break;
    //case GAS:
    case 2:
        while(Result < 8)
            Result += 0.5;
        while(Result > 15)
            Result -= 0.5;
        break;
    //case COLD:
    case 3:
        while(Result < 3)
            Result += 0.5;
        while(Result > 6)
            Result -= 0.5;
        break;
    //case MOON:
    case 4:
        while(Result < 0.5)
            Result += 0.1;
        while(Result > 1.0)
            Result -= 0.1;
        break;
    }

    return Result;
}

int CNumber::NextInt(int Max)
{
    r =  modf(r*11+M_PI,&r);
    int result = fmod(r*1000000,Max);
    //printf("%d\n", result);
    return result;
}

char* CNumber::getHash()
{
    unsigned char *p = (unsigned char*)(&r);
    char a[] = "0123456789abcdef";
    for (int i = 0; i < HASH_SIZE; i++)
        hashData[i] = 0;
    for (unsigned int i = 0; i < sizeof(double); i++)
    {
        hashData[i*2] = a[p[i]/16];
        hashData[i*2+1] = a[p[i]%16];
    }
    return hashData;
}
