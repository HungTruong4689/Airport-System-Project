# Airport-System-Project

Airport simulation project
Introduction
1.Program compilation

- Visual Studio 2022 Preview
- C++ environment

3. Installation

- Install g++
- Download file airport simulation project from Moodle.
- Find the code from Moodle
- Set up the code from all file

4. Running

- Compile every file from the directory
- Type command g++ \*cpp – o p to begin the program
- There are two modes to run the program

1. Step-by step:
   Type p -p
2. Directing according to the point requirements
   The details will shown in the next part of this report.

Testing- Compilation proof

- Type p.exe on CMD
- 1.Run P1 version of Airport simulation

The result:

Replied to some question in this part:

- The maximum size of each queue is increased  the resulting values will be larger.
- The maximum size of each queue is decreased  the resulting values will be smaller.
- The size of the queue is increased  more planes can wait.
  2.Run P2 version of Airport simulation

The results:

Compare the number of planes between the two methods:
• The total of planes is equal to the two methods.
• The number of planes served successfully will be slightly less than double that of the basic one-runway airport, because, depending on the input parameters, one of the runways will sometimes be idle.
• The time when we implement the simulation 2 method is less than when we implement simulation 1.
3.Run P3 version of Airport simulation

The results:

4.Run P4 version of Airport simulation

The results:

5.Run P5 version of Airport simulation

The result:

Conclusion

1. There are 24 files in my project.

2. The main idea:

Main_1: P1 version of Airport simulation
Main_2: P2 version of Airport simulation
Main_3: P3 version of Airport simulation
Main_4: P4 version of Airport simulation
Main_5: P5 version of Airport simulation

Random is the file that imported into each main files.

Specific idea for each simualation:
Main_1

Main_2
Set up two runways in main_2
One runway is used for landings, one for departures.
One plane can land or depart in each unit of time.
If the departure runway can’t implement the can_depart method, the plane will be refused.
If the arrival runway can’t implement the can_land method, the plane will be refused.
Main_3
One runway is normally used for landings, the other is normally for departures.
One plane can land or depart on each runway in each unit of time.
If the size of the departure runway and arrival runway is 0, the plane can land on the arrival runway, or the plane can depart from the departure runway.
If arrival and departure runways can implement the can_land function, the plane will be refused.
Main_4
One runway is used for landings, a second is for departures.
The third runway (Runway overflow) is for overflow traffic. It gives priority to arrivals. One plane can land or depart on each runway in each unit of time.
Based on the state of two runways: departure and arrival runways, we will choose the suitable method for the third runway.
Main_5
Add Plane_p5.h Plane_status emergency and variable fuel.
The fuel will determine by random.h file
If fuel< 1, assign the emergency situation to state variable.
Edit in the main_5 :If the state is emergency, we will require the plane can land immediately.
