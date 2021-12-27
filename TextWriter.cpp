// Copyright
#include "RandWriter.h"

int main(int argc, const char* argv[]) {
     int k = atoi(argv[1]);
     int L = atoi(argv[2]);
     string input;
     string temp;
     while (std::getline(cin, temp)) {
          input.append(temp);
          input.append(1, ' ');
     }
     RandWriter myModel(input, k);
     cout << myModel.generate(input.substr(0, k), L);
     return 0;
}
