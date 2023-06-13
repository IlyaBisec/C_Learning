#pragma once

#include "..\stdafx.h"

//class Casterian;
//class Polar;


class Polar
{
private:
	double mAngle;
	double mRadius;
public:

	Polar() :mAngle(0), mRadius(0){}
	Polar(double angle, double radius) :mAngle(angle),
		mRadius(radius){}
	Polar(const Casterian& cartes)
	{
		double x = cartes.getCoordinateX();
		double y = cartes.getCoordinateY();

		mAngle = tan(y / x);
		mRadius = hypot(x, y);
	}

	void getCoordinate();
	void displayPolar();

	double getAngle() const;
	double getRadius() const;

};

class Casterian
{
private:
	double mX;
	double mY;
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
};
