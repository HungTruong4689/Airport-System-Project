#include <iostream>
#include "Random.h"
#include "Plane_P5.h"

using namespace std;
int crashes;
Random dice;

Plane_P5::Plane_P5(int flt, int time, Plane_status status)
/*
Post:  The Plane data members flt_num, clock_start,
       and state are set to the values of the parameters flt,
       time and status, respectively.
*/

{
    flt_num = flt;
    clock_start = time;
    state = status;
    if (status == arriving) {
        fuel = dice.random_integer(0, 20);
        if (fuel <= 1) status = state = emergency;
    }
    cout << "Plane number " << flt << " ready to ";
    if (status == arriving)
        cout << "land." << endl;
    else if (status == departing)
        cout << "take off." << endl;
    else if (status == emergency)
        cout << "land in a fuel EMERGENCY." << endl;
}

Plane_P5::Plane_P5()
/*
Post:  The Plane data members flt_num, clock_start,
       state are set to illegal default values.
*/
{
    flt_num = -1;
    clock_start = -1;
    state = null;
}

void Plane_P5::refuse() const
/*
Post: Processes a Plane wanting to use Runway, when
      the Queue is full.
*/

{
    cout << "Plane number " << flt_num;
    if (state == arriving || state == emergency)
        cout << " directed to another airport" << endl;
        if (fuel <= 3) {
            cout << "Unfortunately it didn't have enough fuel and crashed.";
            cout << endl;
            cout << "plane CRASH \n\n";
            crashes++;
        }
    else
        cout << " told to try to takeoff again later" << endl;
}


void Plane_P5::land(int time) const
/*
Post: Processes a Plane that is landing at the specified time.
*/

{
    int wait = time - clock_start;
    if (wait > fuel) {
        cout << "\n plane CRASH \n";
        cout << time << ": Plane number " << flt_num
            << "ran out of fuel crashed after "
            << wait << " time unit " << ((wait == 1) ? "" : "s")
            << " in the landing queue. " << endl;
    }
    else cout << time << ": Plane number " << flt_num << " landed after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}

void Plane_P5::fly(int time) const
/*
Post: Process a Plane that is taking off at the specified time.
*/

{
    int wait = time - clock_start;
    cout << time << ": Plane number " << flt_num << " took off after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}

int Plane_P5::started() const
/*
Post: Return the time that the Plane entered the airport system.
*/
{
    return clock_start;
}

Plane_status Plane_P5::get_status() const
{
    return state;
}
