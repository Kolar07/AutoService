#ifndef SERVICE_H_
#define SERVICE_H_

#include <iostream>
#include <vector>
#include <ostream>

class Service {
public:
	/*enum Type {
		oil,
		finding,
		other
	};*/
	std::ostream& operator<<(const std::ostream& os);
	Service(/*Type type_,*/ int mileage_);
	Service();
	~Service();

	virtual void print()=0;

	time_t getDate();
	int getMileage();
	int getID();
	//std::string getType();

	static int getCounter();

private:
	
	static int counter;
	int id;
	//Type type;
	time_t date;
	int mileage;


};


#endif