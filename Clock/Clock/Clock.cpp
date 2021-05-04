/* Clocks is a program that displays a 12-hour and 24-hour clock that the user can manipulate 
   @author Anthony Minunni
   @date 3/19/21 */

#include <iostream>
#include <string>
#include <cstdlib> //for random
#include <iomanip> //for whitespace formatting
#include <chrono> //for time tracking

using namespace std;

/* addOneSecond adds a second to the current time
   @param second is the second value at time of method calling
   @return second */
int addOneSecond(int second) {
	second += 1;
	if (second == 60) {
		second = 0;
	}
	return second;
}

/* addOneMinute is a method that adds a minute to the current time
   @param minute is the minute value at time of calling
   @return minute*/
int addOneMinute(int minute) {
	minute += 1;
	if (minute == 60) {
		minute = 0;
	}
	return minute;
}

/* addOneHour is a method that adds 1 hour to the time
   @param hour1 is an int that represents the hour marker
   @return hour1*/
int addOneHour(int hour) {
	hour += 1;
	if (hour == 13) {
		hour = 01;
	}
	return hour;
}

int main() {

	int hour12 = (rand() % 12) + 1;
	int minute = rand() % 60;
	int second = rand() % 60;

	clock_t time_req; //variable that will keep track of time passed
	bool running = true; //boolean to keep while loop running
	string zone = "AM"; //initial calling of string that reflects time of day in 12-hour time
	int hour24; //integer that is derived from 12-hour time
	string option = "null"; //the variable that the user will input their clock changes into

	while (running) {
		
		//This loop calculates the 24-hour clock's time based on the 12-hour time
		if (hour12 != 12 && zone == "PM") {
			hour24 = hour12 + 12;
		}
		else if (hour12 == 12 && zone == "AM"){
			hour24 = 0;
		}
		else {
			hour24 = hour12;
		}

		//Block of outputs below format the clock
		
		cout << setfill('*') << setw(33) << "" << endl;
		cout << setfill(' ');
		cout << left << "* " << "12-hour clock" << " * ";
		cout << setw(10) << right << "24-hour clock" << " *" << endl;
		cout << setw(4) << left << "*  " << hour12 << ":" << minute << ":" << second << " " << zone << "  * ";
		cout << setw(4) << right << hour24 << ":" << minute << ":" << second << "    *" << endl;
		cout << setfill('*') << setw(33) << "" << endl << endl;

		cout << "1 Add One Hour" << endl;
		cout << "2 Add One Minute" << endl;
		cout << "3 Add One Second" << endl;
		cout << "4 Exit" << endl;

		cin >> option; //user input for clock changes

		//This was my attempt to keep track of time for the clock to start automatically. Unfortunately, I could not get it to work properly.
		/* auto start = std::chrono::steady_clock::now(); //get start time
		while (option == "null") {
			auto end = std::chrono::steady_clock::now(); //get end time
			double passed_time = double(std::chrono::duration_cast<std::chrono::seconds> (end - start).count());
			if(passed_time >= 1){
				option = "3";
				break;
			}
		} */ 

		int choice; //will be used to convert string option into an integer (below)		
		try { //try block in the event the user's input is not an integer
			choice = stoi(option);
		}
		catch (exception e) { //no need to have an error message since the clock updating deletes the message
		}

		switch (choice) { //switch statements that call the different time adding methods
			case 1:
				if (hour12 == 11 && zone == "AM") {
					zone = "PM";
				}
				else if (hour12 == 11 && zone == "PM") {
					zone = "AM";
				}
				hour12 = addOneHour(hour12);
				break;
			case 2:
				if (minute == 59) {
					if (hour12 == 11 && zone == "AM") {
					zone = "PM";
				}
				else if (hour12 == 11 && zone == "PM") {
					zone = "AM";
				}
					hour12 = addOneHour(hour12);
				}
				minute = addOneMinute(minute);
				break;
			case 3:
				if (second == 59) {
					if (minute == 59) {
						if (hour12 == 11 && zone == "AM") {
							zone = "PM";
						}
						else if (hour12 == 11 && zone == "PM") {
							zone = "AM";
						}
						hour12 = addOneHour(hour12);
					}
					minute = addOneMinute(minute);
				}
				second = addOneSecond(second);
				break;
			case 4:
				running = false;
				break;
			default:
				break;
		}

		system("cls"); //clears console for a clean slate
	}

	return 0;

}

