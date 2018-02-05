/* Name: Aakash Shrestha
   Student ID: 140051160
   OOP244 SDD
   Final Project: Milestone 1
   Date: 2017 July 07
*/

#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#include<iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3	
#define DAY_ERROR 4
namespace sict{
	class Date {
		private:
			//private data members
			int year_;
			int mon_;
			int day_;
			int readErrorCode_;
			//private member functions
			int value() const;
			void errCode(int errorCode);
	public:
		//public member functions
		Date();		
		Date(int year, int month, int date);
		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;
		int mdays() const;
		int errCode()const;
		bool bad()const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
	//non member IO operators
	std::istream& operator >> (std::istream& istr, Date& D);
	std::ostream& operator<<(std::ostream& ostr, const Date& D);
}
#endif