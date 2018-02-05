/* Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 5
Date: 2017 July 25
*/

#include<iostream>
#include "Date.h"
#include "general.h"
namespace sict{
	//this function returns a unique integer based on the date
	int Date::value() const {
		return year_ * 372 + mon_ * 31 + day_;
	}

	//this function sets the readErrorCode_ member variable 
	void Date::errCode(int errorCode) {
		readErrorCode_ = errorCode;
	}

	//no argument constructor
	Date::Date() {
		//assigning the object to safe empty state
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		errCode(NO_ERROR);
	}

	//three argument constructor
	Date::Date(int year, int month, int day) {
		bool valid = year >= MIN_YEAR && year <= MAX_YEAR && month >= 1 && month <= 12 && day >= 1 && day <= 32; //checks the validity of year, month and date
		if (valid) {
			//if valid, assigns the incoming values to member variables
			year_ = year;
			mon_ = month;
			day_ = day;
			errCode(NO_ERROR);
		}
		else {
			//if invalid, assigns to safe empty state by creating a temporary object of default constructor
			*this = Date();
		}
	}

	//overloaded operators
	bool Date::operator==(const Date& D)const {
		return this->value() == D.value() ? true : false;
	}

	bool Date::operator!=(const Date& D)const {
		return this->value() != D.value() ? true : false;
	}

	bool Date::operator>(const Date& D)const {
		return this->value() > D.value() ? true : false;
	}

	bool Date::operator<(const Date& D)const {
		return this->value() < D.value() ? true : false;
	}

	bool Date::operator>=(const Date& D)const {
		return this->value() >= D.value() ? true : false;
	}

	bool Date::operator<=(const Date& D)const {
		return this->value() <= D.value() ? true : false;
	}

	//returns the number of days in a month
	int Date::mdays() const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	//accessor member function, returns the readErrorCode_ of the object
	int Date::errCode()const {
		return readErrorCode_;
	}

	//returns true if readErrorCode_ is not equal to zero
	bool Date::bad()const {
		bool ret_value = 0;
		bool valid = readErrorCode_ != 0;
		if (valid) ret_value = 1;
		return ret_value;
	}

	//IO member function that reads the year, month and date
	std::istream& Date::read(std::istream& istr) {
		istr >> year_;
		istr.ignore();
		istr >> mon_;
		istr.ignore();
		istr >> day_;
		if (!istr.fail()) {//if cin does not fail, sets the readErrorCode_ according to it
			if (year_<MIN_YEAR || year_>MAX_YEAR) errCode(YEAR_ERROR);
			else if (mon_ < 1 || mon_ > 12) errCode(MON_ERROR);
			else if (day_ > mdays()) errCode(DAY_ERROR);
		}
		else {//if cin fails
			errCode(CIN_FAILED);
		}
		return istr;
	}

	//IO member function that displays the date
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year_ << "/"; //prints year
		ostr.width(2);  //sets width to 2 for displaying month
		ostr.fill('0'); 
		ostr << mon_ << "/"; //prints month
		ostr.width(2);
		ostr.fill('0');
		ostr<< day_ ; //prints day
		return ostr;
	}

	//Non-member IO operator overloading function, that calls read function to read the date
	std::istream& operator >> (std::istream& istr, Date& D) {
		D.read(istr);
		return istr;
	}

	//Non-member IO operator overloading function, that calls write function to display the date
	std::ostream& operator<<(std::ostream& ostr, const Date& D) {
		D.write(ostr);
		return ostr;
	}
}
