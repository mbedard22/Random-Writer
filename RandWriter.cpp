// Copyright
#include "RandWriter.h"

RandWriter::RandWriter(string text, int k) {
     order = k;
     int head = 0;
     string circle = text + text.substr(0, k);
     int len = text.length();
     char nextChar;
     size_t found;
     for (int i = 0; i < len; i++) {
          string tempGram = circle.substr(head, k);
          nextChar = circle[head + k];
          found = alphabet.find(nextChar);
          if (found == std::string::npos) {
               alphabet.append(1, nextChar);
          }
          if (symTable.count(tempGram) == 0) {
               map<char, int> inner;
               inner.insert(make_pair(nextChar, 1));
               symTable.insert(make_pair(tempGram, inner));
          } else if (symTable.at(tempGram).count(nextChar) == 0) {
               symTable.at(tempGram).insert((make_pair(nextChar, 1)));
          } else {
               symTable.at(tempGram).at(nextChar) += 1;
          }
               head += 1;
          }
}

int RandWriter::order_k() {
     return order;
}

int RandWriter::freq(string k_gram) {
     int size = k_gram.size();
     if (size != order) {
          throw (std::runtime_error("freq: string provided is not of length k\n"));//NOLINT
     }
     int count = 0;
     for (map<char, int>::iterator it = symTable.at(k_gram).begin(); it != symTable.at(k_gram).end(); ++it) {//NOLINT
          count += it->second;
     }
     return count;
}

int RandWriter::freq(string k_gram, char c) {
     int size = k_gram.size();
     if (size != order) {
          throw (std::runtime_error("freq: string provided is not of length k\n"));//NOLINT
     }
     return symTable.at(k_gram).at(c);
}

char RandWriter::k_Rand(string k_gram) {
     int size = symTable.at(k_gram).size();
     std::random_device rd;
     std::default_random_engine generator(rd());
     std::uniform_int_distribution<int> distribution(0, size - 1);
     int rand = distribution(generator);
     std::map<char, int>::iterator it = symTable.at(k_gram).begin();
     advance(it, rand);
     return it->first;
}

string RandWriter::generate(string k_gram, int L) {
     int size = k_gram.size();
     if (size != order) {
          throw (std::runtime_error("generate: string provided is not of length k\n"));//NOLINT
     }
     string output;
     output.append(k_gram);
     for (int i = 0; i < L - order; i++) {
          output.append(1, k_Rand(output.substr(i, order)));
     }
     return output;
}

ostream& operator<<(ostream &output, const RandWriter &RW) {
     output << "Order: " << RW.order << endl;
     output << "Alphabet: " << RW.alphabet << endl;
     output << "K-grams:" << endl;
     for (map<string, map<char,int>>::const_iterator outer_it = RW.symTable.begin(); outer_it != RW.symTable.end(); ++outer_it) {//NOLINT
          output << outer_it->first << "     ";
          for (map<char, int>::const_iterator inner_it = outer_it->second.begin(); inner_it != outer_it->second.end(); ++inner_it) {//NOLINT
               output << inner_it->first << " x" << inner_it->second << " ";
          }
          output << endl;
     }
     return output;
}
