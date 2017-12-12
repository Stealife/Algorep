//
// Created by benjamin angelard on 03/12/2017.
//

#include "MemoryProcess.h"
#define NAME "MemoryProcess"
std::tuple<int, int> MemoryProcess::allocateMemory(int identifiant, int value)
{
    bool found = false;
    /** TODO rajouter la gestion de la taille max d'un processus **/
    int position = 0;
    for (bool freedom : freeArray)
    {
      if (freedom){ /* Si un espace memoire est dispo */

          myMemory.at(position) = std::make_tuple(identifiant,value);
          freeArray.at(position) = false;  /* Marque la case comme prise et occupée */
          return std::make_tuple(id, position);
      }
        position ++;
    }
    /** Si pas de memoire dispo, allouer  TODO gerer taille max **/
    myMemory.push_back(std::make_tuple(identifiant, value));
    freeArray.push_back(false);
    return std::make_tuple(id, position) ;
}

void MemoryProcess::printMemory() {
    int pos = 0;
    for (auto value : myMemory) {
        if (!freeArray[pos]) {
            std::cout << "Identifiant " << std::get<0>(value)
                      << " valeur " << std::get<1>(value) << std::endl;
        }
        pos++;
    }
}

void MemoryProcess::freeVariable(int position, int identifiants)
{

     /** TODO gerer si l'identifiant n'est pas le sien, rnenvoyer au bon **/
    if (freeArray.at(position))
    {
        LOG(NAME, "Invalid access : already freed memory")
        return;
    }
    freeArray.at(position) = true;

}

bool MemoryProcess::modifyMemory(int position, int id, int new_value)
{

    if (position >= myMemory.size())
    {
        LOG("MemoryProcessError", "Can't modify variables, position out of bound");
        return false;
    }
    int current_position = position;
    bool modified = false;

    int id_cu = std::get<0>(myMemory.at(current_position));
    if (id_cu == id)
    {
        myMemory.at(current_position) = std::make_tuple(id, new_value);
        modified = true;
    }
    return modified;
}

void MemoryProcess::freeMutlipleVariable(std::vector<int> vect_position, int identifiant)
{

    for (int position : vect_position)
    {
        freeVariable(position, identifiant);

    }
}

std::vector<std::tuple<int,int>>  MemoryProcess::allocateMultiMemory(int identifiant, std::vector<int> values)
{
    /** TODO gestion erreur **/
    std::vector<std::tuple<int , int>> res = std::vector<std::tuple<int, int>>();
    for (int i = 0; i < values.size(); i++)
    {
        int val = values.at(i);
        auto pos = allocateMemory(identifiant, val);
        res.push_back(pos);
    }
    return res;
}

int MemoryProcess::getCurrentSize() {
    int size = 0;
    for (auto val : freeArray)
    {
        if (!val)
            size++;
    }
    return size;
}