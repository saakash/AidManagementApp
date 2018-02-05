/* Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 5
Date: 2017 July 25
*/

// AmaPersishable.cpp
#include "AmaPerishable.h"
using namespace std;
namespace sict {
	//default constructor which invokes parent's constructor with value 'P' for perishable
	AmaPerishable::AmaPerishable():AmaProduct('P') {
		
	}

	//getter function for member variable expiry_
	const Date& AmaPerishable::expiry() const {
		return expiry_;
	}

	//setter function for expiry_
	void AmaPerishable::expiry(const Date& value) {
		expiry_ = value;
	}

	//store function which calls the store function of it's parent to store the records in a file
	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine) const {
		AmaProduct::store(file, false); //calls the parent's store function to store the data without a new line
		file << "," << expiry_;			//adds a comma separated expiry date
		if (addNewLine) { file << endl; }
		return file;
	}

	//store function which calls the load function of it's parent to load the records from a file
	std::fstream& AmaPerishable::load(std::fstream& file) {	
		AmaProduct::load(file);	//calls the parent's load function to read the comma separated fields except expiry date
		file.ignore(1);			//ignores a comma
		expiry_.read(file);		//reads the expiry date
		return file;
	}

	//write function to display the data either in a linear or form format
	std::ostream& AmaPerishable::write(std::ostream& os, bool linear)const {
		AmaProduct::write(os, linear);	//displays the data linearly 
		if (err_.isClear()) {
			if (linear) {
				expiry_.write(os);		//displays the expiry date into the same line
			}
			else {
				os << endl;
				os << "Expiry date: ";	//displays in form format
				expiry_.write(os);
			}
		}
		return os;
	}

	//read function to read the user inputs
	std::istream& AmaPerishable::read(std::istream& is) {
		AmaProduct::read(is);		//reads the user inputs except expiry date calling parent's read function
		if (err_.isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";
			Date temp;		//temporary object of Date
			temp.read(is);	//reads the user input for date
			//sets the corresponding error messages according to the error code
			if (temp.errCode() == CIN_FAILED) {
				err_.message("Invalid Date Entry");
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) { 
				err_.message("Invalid Year in Date Entry"); 
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) { 
				err_.message("Invalid Month in Date Entry");
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) { 
				err_.message("Invalid Day in Date Entry");
				is.setstate(ios::failbit);
			}
			else { expiry_ = temp; }
		}
		return is;
	}
}