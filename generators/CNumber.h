#ifndef _C_NUMBER_H_
#define _C_NUMBER_H_

#define HASH_SIZE 21

class CNumber
{
public:
    CNumber(double seed = 0);
    ~CNumber();

    void setSeed(double seed);
    double Next();
    double NextSize(int planetType);
    int NextInt(int Max);
    char hashData[HASH_SIZE];
    char* getHash();

private:
    double r;
};

#endif // _C_NUMBER_H_
