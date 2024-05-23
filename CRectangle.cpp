/// \file CRectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "CRectangle.h"

/// @brief default constructor 
Rectangle::Rectangle():Quadrilateral() {

	cout << "Rectangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the rectangle
/// @param h height of the rectangle
Rectangle::Rectangle(float w, float h):Quadrilateral() {

	Init();

	cout << "Rectangle - constructor" << endl;

	if (w <= 0. || h <= 0.) {
		WarningMessage("constructor: width and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(w,h);

}

/// @brief constructor 
/// @param w width of the rectangle
/// @param h height of the rectangle 
/// @param sf struct of type Format
Rectangle::Rectangle(float w, float h, Format sf):Quadrilateral(sf)  {

	Init();

	cout << "Rectangle and color - constructor" << endl;

	if (w <= 0. || h <= 0.) {
		WarningMessage("constructor: width and height should be > 0");
		SetDim(0, 0);
	}
	else
		SetDim(w, h);

}

/// @brief destructor  {
Rectangle::~Rectangle() {

	cout << "Rectangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Rectangle::Rectangle(const Rectangle &r) { 

	cout << "Rectangle - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rectangle& Rectangle::operator=(const Rectangle &r) { 

	cout << "Rectangle - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length and same colors 
bool Rectangle::operator==(const Rectangle &r) { 

	if (r.width == width && r.height == height && r.shapef==shapef)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Rectangle::Init() {
	SetDim(0,0);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rectangle::Init(const Rectangle &r) {
		
	Init();
	SetDim(r.width,r.height);
	shapef->fill = r.shapef->fill;
	shapef->outline = r.shapef->outline;
}

/// @brief total reset of the object  
void Rectangle::Reset() {
	
	SetDim(0,0);
	shapef->fill = k;
	shapef->outline = k;
	
}


/// @brief set width of the object
/// @param w width 
void Rectangle::SetWidth(float w) {

	if (w < 0.) {
		WarningMessage("SetWidth: width should be > 0");
		return;
	}

	SetDim(w,height);

}

/// @brief set length of the object
/// @param h height 
void Rectangle::SetHeight(float h) {

	if (h < 0.) {
		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	SetDim(width,h);

}



/// @brief get width of the object
/// @return width 
float Rectangle::GetWidth() {

	return width;

}

/// @brief get length of the object
/// @return height
float Rectangle::GetHeight() {

	return height;
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void Rectangle::SetDim(float w, float h) {

	width = w;
	height = h;  
	Quadrilateral::SetSides(w,h,w,h);
	
	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void Rectangle::GetDim(float &w, float &h) {

	w = width;
	h = height; 
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float Rectangle::Area() {
	
	return (width*height);
}


/// @brief write an error message 
/// @param string message to be printed
void Rectangle::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Rectangle --";
	cout << string << endl;

}


/// @brief write a warning message 
/// @param string message to be printed
void Rectangle::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Rectangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rectangle::Dump() {
	cout << endl;
	cout << "---Rectangle---" << endl; 
	cout << endl;
	
	cout << "Width = " << width << endl;
	cout << "Heigth = " << height << endl;
	cout << "------------" << endl;
	
	Quadrilateral::Dump();
	
	cout << endl;

}

/// @brief to draw a colored rectangle
void Rectangle::Drawing() {
	
	cout << endl << "Rectangle - Drawing: " << endl;
	switch (shapef->outline)
	{
	case 0:
		cout << "Outline Black" << endl;
		break;
	case 1:
		cout << "Outline White" << endl;
		break;
	case 2:
		cout << "Outline Red" << endl;
		break;
	case 3:
		cout << "Outline Green" << endl;
		break;
	case 4:
		cout << "Outline Blue" << endl;
		break;
	default:
		WarningMessage("Rectangle - Drawing: Outline not colored");
		break;
	}

	switch (shapef->fill)
	{
	case 0:
		cout << "Fill Black" << endl;
		break;
	case 1:
		cout << "Fill White" << endl;
		break;
	case 2:
		cout << "Fill Red" << endl;
		break;
	case 3:
		cout << "Fill Green" << endl;
		break;
	case 4:
		cout << "Fill Blue" << endl;
		break;
	default:
		WarningMessage("Rectangle - Drawing: Fill not colored");
		break;
	}
	cout << endl;

}






