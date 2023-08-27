#include <bits/stdc++.h>
#include "Item.hpp"

#ifndef DEPURADOR_HPP
#define DEPURADOR_HPP

using namespace std;

class depurador
{
  public:
    depurador();

    void printHeap(vector<Item> heap);
    wchar_t* getText(const locale loc, string name);
    unordered_set<wstring> getStopWords(const locale loc);
};

#endif
