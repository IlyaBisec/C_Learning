// Conversion of polar coordinates 
// to cartesian coordinates

#pragma once

#include "..\stdafx.h"

//class Casterian;
//class Polar;

/*Но есть всё те же проблемы, что и в предыдущих.
Плюс - код не компилируется.*/

class Polar
{
public:

	Polar() :m_Angle(0), m_Radius(0){}
	Polar(double angle, double radius) :m_Angle(angle),
		m_Radius(radius){}
	Polar(const Casterian &cartes)
	{
		double x = cartes.getCoordinateX();
		double y = cartes.getCoordinateY();

		m_Angle = tan(y / x);
		m_Radius = hypot(x, y);
	}

	void getCoordinate();
	void displayPolar();

	double getAngle() const;
	double getRadius() const;

private:
	double m_Angle;
	double m_Radius;

};

class Casterian
{
public:

	Casterian() :mX(0), mY(0){}
	Casterian(double x, double y):mX(x), mY(y){}
	Casterian(const Polar& polar)
	{
		double angle = polar.getAngle();
		double radius = polar.getRadius();
		mX = radius * cos(angle);
		mY = radius * sin(angle);
	}

	Casterian operator +(Casterian coordinate);

	double getCoordinateX()const;
	double getCoordinateY()const;

private:
	double mX;
	double mY;
};
