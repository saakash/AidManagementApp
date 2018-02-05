/*Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 2
Date: 2017 July 09
*/

#ifndef _ERRORMESSAGE_HEADER_H_
#define _ERRORMESSAGE_HEADER_H_
namespace sict {
	class ErrorMessage {
	private:
		char* message_;
	public:
		//public member functions
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete; //deleted copy constructor
		ErrorMessage& operator=(const ErrorMessage& em) = delete;//deleted copy assignment operator
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
	};
	//non-member << operator overloading
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& E);
}
#endif