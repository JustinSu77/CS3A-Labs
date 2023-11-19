/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: main.cpp for Problem #1 of Lab #19
**/
#include "Truck.h"
using namespace std;

int main()
{
	// Declare and initialize Person owners of Trucks
	Person alice("Alice", 27);
	Person bob("Bob", 45);
	Person cindy("Cindy", 38);
	
	// Declare and initialize Trucks
	Truck aliceTruck("Toyota", "Tacoma", 6, 1600, alice);
	Truck bobTruck("Ford", "Ranger", 4, 1400, bob);
	Truck cindyTruck("Chevy", "Silverado", 6, 2200, cindy);

	// Display value of member variables of Truck object owned by alice
	cout << "< " << aliceTruck.getOwner().getName() << " Truck >" << endl;
	cout << "Make: " << aliceTruck.getMake() << endl;
	cout << "Model: " << aliceTruck.getModel() << endl;
	cout << "Cylinder: " << aliceTruck.getCylinder() << endl;
	cout << "Load: " << aliceTruck.getLoad() << endl;
	
	// Output new line to terminal for readability
	cout << endl;
	
	// Display value of member variables of Truck object owned by bob
	cout << "< " << bobTruck.getOwner().getName() << " Truck >" << endl;
	cout << "Make: " << bobTruck.getMake() << endl;
	cout << "Model: " << bobTruck.getModel() << endl;
	cout << "Cylinder: " << bobTruck.getCylinder() << endl;
	cout << "Load: " << bobTruck.getLoad() << endl;
	
	// Output new line to terminal for readability
	cout << endl;
	
	// // Display value of member variables of Truck object owned by cindy
	cout << "< " << cindyTruck.getOwner().getName() << " Truck >" << endl;
	cout << "Make: " << cindyTruck.getMake() << endl;
	cout << "Model: " << cindyTruck.getModel() << endl;
	cout << "Cylinder: " << cindyTruck.getCylinder() << endl;
	cout << "Load: " << cindyTruck.getLoad() << endl;

	return 0;
}