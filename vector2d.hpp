#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class Vector2D{

public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x_p, float y_p);

	Vector2D& add(const Vector2D& vec);
	Vector2D& subtract(const Vector2D& vec);
	Vector2D& multiply(const Vector2D& vec);
	Vector2D& divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& v);
	Vector2D& operator-=(const Vector2D& v);
	Vector2D& operator*=(const Vector2D& v);
	Vector2D& operator/=(const Vector2D& v);
	Vector2D& operator*=(const int& n);
	Vector2D& zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};