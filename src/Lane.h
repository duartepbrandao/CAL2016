/*
 * Lane.h
 *
 *  Created on: Apr 8, 2017
 *      Author: ShoterXX
 */

#ifndef SRC_LANE_H_
#define SRC_LANE_H_

#include <vector>

#define LANE_OBSTRUCTED 1
#define LANE_OK 0
#define LANE_FULL 2
#define CAR_NOT_FOUND -1

class Exit;
class Car;


class Lane {
private:

	int capacity;
	std::vector<Car *> load;
	int status;
	Exit * destination;

public:
	Lane();
	virtual ~Lane();

	int getCapacity();
	int getLoad();
	int getStatus();
	int getDestID();
	std::vector<Car *> getVehicles();

	int enterLane(Car * vehicle);
	int exitLane(Car * vehicle);
	void setObstructed();
	void clearObstrucion();
};

#endif /* SRC_LANE_H_ */
