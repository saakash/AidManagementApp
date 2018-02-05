/* Name: Aakash Shrestha
   Student ID: 140051160
   OOP 244 SDD
   Final Project: Milestone 3
   Date: 2017 July 11 
*/

#ifndef SICT_MYFILE_H__
#define SICT_MYFILE_H__
#include "Streamable.h"
#include "Streamable.h"
#include "Streamable.h" // Streamable.h is included three times on purpose.
namespace sict{
  class MyFile : public Streamable {
    char fname_[256];
    char text_[10000];
  public:
    MyFile(const char* fname);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
    void print();
  };
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
  std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif