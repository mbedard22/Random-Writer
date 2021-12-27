// Copyright
#ifndef RANDWRITER_H//NOLINT
#define RANDWRITER_H//NOLINT

#include <iostream>
#include <string>
#include <map>
#include <random>
#include <utility>
using namespace std;//NOLINT
class RandWriter{
 public:
     RandWriter(string text, int k);
     int order_k();
     int freq(string k_gram);
     int freq(string k_gram, char c);
     char k_Rand(string k_gram);
     string generate(string k_gram, int L);
     friend ostream &operator<<(ostream &output, const RandWriter &RW);
 private:
     int order;
     string alphabet;
     std::map <string, map<char, int>> symTable;
};


#endif//NOLINT
