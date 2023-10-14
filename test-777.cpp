#include <iostream>
using namespace std;
unsigned char *ss;
int main()
  {ss = (unsigned char *) malloc(12);
   cout << sizeof(* ss);
   return 0;     
  }