
#include "Utility.h"
#include "Queue_P5.h"
enum Runway_activity { idle, land, takeoff };

class Runway_P5 {
public:
	Runway_P5(int limit);
	Error_code can_land(const Plane_P5& current);
	Error_code can_depart(const Plane_P5& current);
	Runway_activity activity(int time, Plane_P5& moving);
	void shut_down(int time) const;
	int arrival_size();//part P3
	int departure_size(); //part P3

private:
	Extended_queue_P5 landing;
	Extended_queue_P5 takeoff;
	int queue_limit;
	int num_land_requests;        //  number of planes asking to land
	int num_takeoff_requests;     //  number of planes asking to take off
	int num_landings;             //  number of planes that have landed
	int num_takeoffs;             //  number of planes that have taken off
	int num_land_accepted;        //  number of planes queued to land
	int num_takeoff_accepted;     //  number of planes queued to take off
	int num_land_refused;         //  number of landing planes refused
	int num_takeoff_refused;      //  number of departing planes refused
	int land_wait;                //  total time of planes waiting to land
	int takeoff_wait;             //  total time of planes waiting to take off
	int idle_time;                //  total time runway is idle
};

