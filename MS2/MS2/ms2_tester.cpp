/*Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 2
Date: 2017 July 09
*/

#include <iostream>
#include "ErrorMessage.h"
using namespace std;
using namespace sict;
int main() {
   ErrorMessage T("Testing Error Message");
   ErrorMessage e;
   cout << T  << endl << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "failed!") << endl;
   cout << "===========|\r";
   for (int i = 0; i < 10000000; i++) {
      if (i % 1000000 == 0) {
         cout << "*";
         cout.flush();
      }
      e = "Some error message that is really long long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long";
   }
   cout << '*' << endl;
   cout << e << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   e.message("Short Message");
   cout << e << endl << e.message() << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   e.clear();
   cout << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
   return 0;
}