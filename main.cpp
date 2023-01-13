#include "show_mains.h"
#include <iostream>
using namespace std;
int version_selector()
{
	int version_number;
	cout << "Select version of program to run. (1-5). Input 6 to quit" << endl;
	cout << "1. Run P1 version of Airport simulator \n"
		<< "2. Run P2 version of Airport simulator \n"
		<< "3. Run P3 version of Airport simulator \n"
		<< "4. Run P4 version of Airport simulator \n"
		<< "5. Run P5 version of Airport simulator \n"
		<< "6. Quit the program" << endl;
	cout << "Your choice: ";
	cin >> version_number;

	return version_number;
}

int main()     //  Airport simulation program
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

	int version;
	version = version_selector();

	switch (version) {
		//  Let at most one Plane onto the Runway at current_time.
	case 1:
		main_1();
		break;
	case 2:
		main_2();
		break;
	case 3:
		main_3();
		break;
	case 4:
		main_4();
		break;
	case 5:
		main_5();
		break;
	case 6:
		break;
	}
	system("pause");
}