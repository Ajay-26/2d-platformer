#include "vector2d.hpp"

Vector2D::Vector2D(){
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float p_x, float p_y){
	x = p_x;
	y = p_y;
}

Vector2D& Vector2D::add(const Vector2D& vec){
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& vec){
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec){
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec){
	if(vec.x == 0 || vec.y == 0){
		std::cout << "Warning - Input vector has one of it's two components as 0" << std::endl;
	}
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

Vector2D& operator+(Vector2D &v1, const Vector2D& v2){
	return v1.add(v2);
}

Vector2D& operator-(Vector2D &v1, const Vector2D& v2){
	return v1.subtract(v2);
}

Vector2D& operator*(Vector2D &v1, const Vector2D& v2){
	return v1.multiply(v2);
}

Vector2D& operator/(Vector2D &v1, const Vector2D& v2){
	return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v){
	return this->add(v);
}

Vector2D& Vector2D::operator-=(const Vector2D& v){
	return this->subtract(v);
}

Vector2D& Vector2D::operator*=(const Vector2D& v){
	return this->multiply(v);
}

Vector2D& Vector2D::operator/=(const Vector2D& v){
	return this->divide(v);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec){
	// Don't take a new line here, do that while calling
	//Redefining the std::cout function
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
}