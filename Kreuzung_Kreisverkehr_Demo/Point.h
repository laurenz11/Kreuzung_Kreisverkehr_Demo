#pragma once
class Point
{
public:

	Point();
	~Point();

	float x;
	float y;

	void setPoint(float X, float Y);
	void movePoint(float X, float Y);

	float getX();
	float getY();

};

