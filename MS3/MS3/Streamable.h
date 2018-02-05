/* Name: Aakash Shrestha
Student ID: 140051160
OOP 244 SDD
Final Project: Milestone 3
Date: 2017 July 11
*/

#pragma once
#ifndef SICT_STREAMABLE_H_
#define SICT_STREAMABLE_H_
#include<fstream>
namespace sict {
	class Streamable {
	public:
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const =0;
		virtual std::fstream& load(std::fstream& file)=0;
		virtual std::ostream& write(std::ostream& os, bool linear)const=0;
		virtual std::istream& read(std::istream& is)=0;
	};
}
#endif