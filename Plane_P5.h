#pragma once

enum Plane_status { null, arriving, departing,emergency };

class Plane_P5 {
public:
	Plane_P5();
	Plane_P5(int flt, int time, Plane_status status);
	void refuse() const;
	void land(int time) const;
	void fly(int time) const;
	int started() const;
	Plane_status get_status() const;
private:
	int flt_num;
	int clock_start;
	Plane_status state;
	int fuel;
};