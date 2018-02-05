/* Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 5
Date: 2017 July 25
*/

// AmaProduct.h
#ifndef ICT_AMAPRODUCT_H
#define ICT_AMAPRODUCT_H
#include <iostream>
#include "Product.h"
#include "ErrorMessage.h"

namespace sict {
	class AmaProduct :public Product {
	private:
		char fileTag_;
		char unit_[11];
	protected:
		ErrorMessage err_;
	public:
		AmaProduct(char c = 'N');
		const char* unit() const;
		void unit(const char* value);
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);
	};
}
#endif

