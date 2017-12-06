//
// Created by benjamin angelard on 06/12/2017.
//

#ifndef ALGOREP_HEADMEMORYPROCESS_H
#define ALGOREP_HEADMEMORYPROCESS_H
#include "MemoryProcess.h



class HeadMemoryProcess : public MemoryProcess {
private :
    int getCurrentSize();
    int allocateFirstFit(int identifiant, int value);
private :
    std::vector<MemoryProcess> listOfSons = new std::vector<MemoryProcess> ();
};


#endif //ALGOREP_HEADMEMORYPROCESS_H
