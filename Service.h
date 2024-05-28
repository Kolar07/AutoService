#ifndef SERVICE_H_
#define SERVICE_H_

#include <iostream>
#include <vector>
#include <ostream>
#include "Date.h"
#include "Interval.h"

class Service {
private:

	static int counter;

	int id;
	Date date;
	Date dueDate;
	int mileage;

public:
	//std::ostream& operator<<(const std::ostream& os);
	Service(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService, int _daysToNextService, int _monthsToNextService, int _yearsToNextService);
	//constructor with date of the service and time to next service (e.g. 6 months) 

	Service(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService);
	// constructor with date of the service
	Service();
	~Service();
	
	bool operator==(const Service& obj);

	virtual void print()=0;

	Date getDate();
	Date getDueDate();
	int getMileage();
	int getID();
	void setDueDate(int _days, int _months, int _years);
	void setDueDate(Date _date);
	void setDueDateByInterval(Interval _interval);

	virtual std::unique_ptr<Service> clone() const = 0;

	static int getCounter();


};


#endif