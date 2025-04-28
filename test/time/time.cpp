#include <iomanip>
#include <iostream>
#include <ctime>
#include <ostream>
#include <string>

int	main(void) {
	std::time_t	timestamp = time(NULL);
	struct	tm	timedata = *localtime(&timestamp);

	
	std::cout	<< "["
				<< timedata.tm_year + 1900
				<< std::setfill('0') << std::setw(2) << timedata.tm_mon + 1
				<< std::setfill('0') << std::setw(2) << timedata.tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2) << timedata.tm_hour 
				<< std::setfill('0') << std::setw(2) << timedata.tm_min
				<< std::setfill('0') << std::setw(2) << timedata.tm_sec
				<< "]" << std::endl;
	return 0;
}
