#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <iomanip>


using namespace std;

struct travel_locations {
	string locName;
	double latitude = 0;
	double longitude = 0;
};

void printLocationData(const vector<travel_locations>);
void editLocation(vector<travel_locations>&, vector<travel_locations>&, int);
double haversine(double lat1, double long1, double lat2, double long2, double radius);
double getFlightTime(double miles, double speed);

int main() {
	const double radius = 3958.8;
	const double planeSpeed = 500;
	double time = 0;
	double distance = 0;
	vector<travel_locations> locations_data;
	bool stillSelecting = true;
	int selectionNum = 0;
	vector<travel_locations> selectedLocations;

	travel_locations loc1;
	loc1.locName = "West Palm Beach, FL, USA";
	loc1.latitude = 26.709723;
	loc1.longitude = -80.064163;

	travel_locations loc2;
	loc2.locName = "Charlotte, NC, USA";
	loc2.latitude = 35.227085;
	loc2.longitude = -80.843124;

	travel_locations loc3;
	loc3.locName = "Connersville, IN, USA";
	loc3.latitude = 39.653687;
	loc3.longitude = -85.147896;

	travel_locations loc4;
	loc4.locName = "Park Ridge, IL, USA";
	loc4.latitude = 42.017452;
	loc4.longitude = -87.861786;

	travel_locations loc5;
	loc5.locName = "Belmont, CA, USA";
	loc5.latitude = 37.524174;
	loc5.longitude = -122.304199;

	travel_locations loc6;
	loc6.locName = "Stuart, FL, USA";
	loc6.latitude = 27.192223;
	loc6.longitude = -80.243057;

	travel_locations loc7;
	loc7.locName = "Lafayette, LA, USA";
	loc7.latitude = 30.216667;
	loc7.longitude = -92.033333;

	travel_locations loc8;
	loc8.locName = "Yuma, AZ, USA";
	loc8.latitude = 32.698437;
	loc8.longitude = -114.650398;

	travel_locations loc9;
	loc9.locName = "Juneau, AK, USA";
	loc9.latitude = 58.305801;
	loc9.longitude = -134.433304;

	travel_locations loc10;
	loc10.locName = "Yakima, WA, USA";
	loc10.latitude = 46.602070;
	loc10.longitude = -120.505898;

	locations_data.insert(locations_data.end(), { loc1, loc2, loc3, loc4, loc5, loc6, loc7, loc8, loc9, loc10 });

	while (stillSelecting == true) {
		cout << "Select one of the following " << locations_data.size() << " loactions" << endl << endl;
		printLocationData(locations_data);
		cout << endl;
		cin >> selectionNum;
		//system("CLS");
		if (selectionNum < 0 || selectionNum > locations_data.size()) {
			cout << "Invalid Selection!" << endl;
		}
		else {
			editLocation(locations_data, selectedLocations, selectionNum);

		}
		if (selectedLocations.size() == 2) {
			stillSelecting = false;
		}
	}
	cout << endl << "The location selected were: " << endl;
	printLocationData(selectedLocations);
	cout << endl;
	distance = haversine(selectedLocations.at(0).latitude, selectedLocations.at(1).latitude, selectedLocations.at(0).longitude, selectedLocations.at(1).longitude, radius);
	cout << "The distance between the two cities is " << distance << " miles" << endl;
	time = getFlightTime(distance, planeSpeed);
	cout << "It will take " << time << " hour(s)" << endl << endl;
	return 0;
}
void printLocationData(vector<travel_locations> location)// prints the city and state name, along with the latitude and longtidue values
{
	for (int i = 0; i < location.size(); i++) {
		travel_locations LD = location.at(i);
		cout << i + 1 << ".  ";
		cout << LD.locName << setw(20);
		cout << LD.latitude << setw(20);
		cout << LD.longitude << endl;
	}
}
void editLocation(vector<travel_locations>& locationList, vector<travel_locations>& locationCopy, int vectPos) {
	int pos = vectPos - 1;
	locationCopy.push_back(locationList.at(pos)); //copys the location to a new vector
	locationList.erase(locationList.begin() + pos); // deletes the selected loction from the original list
}
double haversine(double lat1, double lat2, double long1, double long2, double radius)
{
	double a = ((lat2 - lat1) / 2) * (M_PI / 180);
	double b = ((long2 - long1) / 2) * (M_PI / 180);
	double c = sqrt(sin(a) * sin(a) + (cos(lat1) * cos(lat2) * sin(b) * sin(b)));
	double d = 2 * radius * c;
	return d;
}

double getFlightTime(double miles, double speed)
{
	double flightTime = miles/speed;
	return flightTime;
}