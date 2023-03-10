#include "Random.h"
#include "Plane.h"
#include "Runway.h"
#include "Utility.h"
#include <string>
using namespace std;

void initialize4(int& end_time, int& queue_limit,
    double& arrival_rate, double& departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
          the maximal queue sizes permitted,
          and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
          end_time, queue_limit, arrival_rate, and departure_rate to
          the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport with three runways." << endl
        << "One runway is used for landings, "
        << "a second is for departures. " << endl
        <<"The third runway is for overflow traffic. It gives priority to arrivals.\nOne plane can land or depart on each runway in each unir of time."<< endl;
    cerr << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;

    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;

    bool acceptable;
    do {
        cerr << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cerr << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        /*if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " << endl;*/

    } while (!acceptable);
}
void run_idle4(string runway_id, int time) {
    cout << time << ": " << runway_id << " Runway is idle." << endl;
}

int main_4()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize4(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway arrivals(queue_limit); //Set up the two runways
    Runway departures(queue_limit);
    Runway overflow(queue_limit);
    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (arrivals.can_land(current_plane) != success)
                if (overflow.can_land(current_plane) != success)
                    current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (departures.can_depart(current_plane)!=success)
                if(overflow.arrival_size()==0)
                    if(overflow.can_depart(current_plane)!=success)
                        current_plane.refuse();     
        }

        Plane moving_plane;
        switch (arrivals.activity(current_time, moving_plane)) {
        case land:
            cout << "Landing runway: ";
            moving_plane.land(current_time);
            break;
        case takeoff:
            cout << "Landing runway: ";
            cout << "WARNING: catastophic failure!" << endl;
            break;
        case idle:
            run_idle4("Arrival", current_time);
        }
        switch (departures.activity(current_time, moving_plane)) {
        case takeoff:
            cout << "Takeoff runway: ";
            moving_plane.fly(current_time);
            break;
        case land:
            cout << "Takeoff runway: ";
            cout << "WARNING: catastophic failure!" << endl;
            break;
        case idle:
            run_idle4("Departure", current_time);
        }
        switch (overflow.activity(current_time, moving_plane)) {
        case takeoff:
            cout << "Overflow runway: ";
            moving_plane.fly(current_time);
            break;
        case land:
            cout << "Overflow runway: ";
            moving_plane.land(current_time);
            break;
        case idle:
            run_idle4("Overflow", current_time);
        }
    }
    cout << "\n\n----Arrival Runway statistics----\n " << endl;
    arrivals.shut_down(end_time);
    cout << "\n\n----Departure Runway statistics----\n " << endl;
    departures.shut_down(end_time);
    cout << "\n\n----Overflow Runway statistics----\n " << endl;
    overflow.shut_down(end_time);
    return 0;
}