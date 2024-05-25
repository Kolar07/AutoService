#ifndef SERVICE_H_
#define SERVICE_H_

#include <iostream>
#include <vector>
#include <ostream>
#include "Date.h"

class Service {
private:

	static int counter;
	int id;
	//Type type;
	Date date;
	Date dueDate;
	int mileage;

public:
	/*enum Type {
		oil,
		finding,
		other
	};*/
	std::ostream& operator<<(const std::ostream& os);
	Service(/*Type type_,*/ int _mileage, int _day, int _month, int _year);
	Service();
	~Service();

	virtual void print()=0;

	Date getDate();
	Date getDueDate();
	int getMileage();
	int getID();
	//std::string getType();

	static int getCounter();


};


#endif