/**
	Date: 9/21/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #8
**/
#include <iostream>
using namespace std;

// Rectangle class
class Rectangle
{
// Private fields	
private:
	int width;
	int height;
// Public fields	
public:
	// Constructor to set all private fields to given values
	Rectangle(int newWidth, int newHeight);
	// Setter function for width
	void setWidth(int newWidth);
	// Getter function for width
	int getWidth();
	// Setter function for height
	void setHeight(int newHeight);
	// Setter function for height
	int getHeight();
};

int main()
{
	// Construct 4 rectangle objects
	Rectangle r1(4, 3);
	Rectangle r2(2, 8);
	Rectangle r3(3, 5);
	Rectangle r4(1, 11);
	
	// Declare and initialize variable to store the area for each rectangle
	int r1Area = r1.getHeight() * r1.getWidth();
	int r2Area = r2.getHeight() * r2.getWidth();
	int r3Area = r3.getHeight() * r3.getWidth();
	int r4Area = r4.getHeight() * r4.getWidth();

	// Declare and initialize variables to store largestArea and smallestArea
	int largestArea = 0;
	int smallestArea = 0;

	// Get largest area
	// If r1's area is largest
	if (r1Area > r2Area && r1Area > r3Area && r1Area > r4Area)
	{
		// Set largestArea to r1Area
		largestArea = r1Area;
	}
	// If r2's Area is the largest 
	else if (r2Area > r1Area && r2Area > r3Area && r2Area > r4Area)
	{
		// Set largestArea to r2Area
		largestArea = r2Area;
	}
	// If r3's area is the largest
	else if (r3Area > r1Area && r3Area > r2Area && r3Area > r4Area)
	{
		// Set largestArea to r3Area
		largestArea = r3Area;
	}
	// If r4's area is the largest
	else if (r4Area > r1Area && r4Area > r2Area && r4Area > r3Area)
	{
		// Set largestArea to r4Area
		largestArea = r4Area;
	}
	// Get smallest area
	// If r1's area is the smallest
	if (r1Area < r2Area && r1Area < r3Area && r1Area < r4Area)
	{
		// Set smallestArea to r1Area
		smallestArea = r1Area;
	}
	// If r2's area is the smallest area
	else if (r2Area < r1Area && r2Area < r3Area && r2Area < r4Area)
	{
		// Set smallestArea to r2Area
		smallestArea = r2Area;
	}
	// If r3's area is the smallest area
	else if (r3Area < r1Area && r3Area < r2Area && r3Area < r4Area)
	{
		// Set smallestArea to r3Area
		smallestArea = r3Area;
	}
	// IF f4's area is the smallest area
	else if (r4Area < r1Area && r4Area < r2Area && r4Area < r3Area)
	{
		// Set smallestArea to r4Area
		smallestArea = r4Area;
	}
	// Find the difference between the largestArea and smallestArea
	int difference = largestArea - smallestArea;

	// Output the largest area, smallest area, and differece
	cout << "The largest area : " << largestArea << endl;
	cout << "The smallest area : " << smallestArea << endl;
	cout << "The difference : " << difference << endl;

	return 0;
}

Rectangle::Rectangle(int newWidth, int newHeight)
{
	// Set width to given newWidth
	width = newWidth;
	// Set height to given newHeight
	height = newHeight;
}

void Rectangle::setWidth(int newWidth)
{
	// Set width to given newWidth
	width = newWidth;
}

int Rectangle::getWidth()
{
	return width;
}

void Rectangle::setHeight(int newHeight)
{
	// Set height to given newHeight
	height = newHeight;
}

int Rectangle::getHeight()
{
	return height;
}

