/* Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 5
Date: 2017 July 25
*/

// AmaPerishable.h
#ifndef ICT_AMAPERISHABLE_H
#define ICT_AMAPERISHABLE_H
#include "AmaProduct.h"
#include "Date.h"

namespace sict {
	class AmaPerishable : public AmaProduct {
	private:
		Date expiry_;
	public:
		AmaPerishable();
		const Date& expiry() const;
		void expiry(const Date& value);
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);
	};
}

#endif