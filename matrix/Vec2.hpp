#pragma once
#include <iostream>

namespace jrw {
	class Vec2
	{
	public:
		Vec2();
		Vec2(int x, int y);
		~Vec2();

		int x, y;

		void print() const;
		Vec2& add(const Vec2& other);
		Vec2& minus(const Vec2& other);
		Vec2& times(const int& scale);
		Vec2& divide(const int& scale);
		Vec2& vtimes(const Vec2& other);
		Vec2& vdivide(const Vec2& other);

		//overload operator +, -, *
		friend Vec2 operator+(Vec2 left, Vec2 right);
		friend Vec2 operator-(Vec2 left, Vec2 right);
		friend Vec2 operator*(Vec2 origin, int scale);
		friend Vec2 operator*(Vec2 left, Vec2 right);
		friend Vec2 operator/(Vec2 origin, int scale);
		friend Vec2 operator/(Vec2 left, Vec2 right);

		//overload operator ==
		bool operator==(const Vec2& other) const;

		//class work
		int dot(const Vec2& other); //dot product
		int cross(const Vec2& other); //cross product
		double magnitude();
		double mag2();
		Vec2& normalized();
		double eulerangle();
		double eulerangleToVector(Vec2 other);

		//overload operator <=, >=, ==, !=, <, >
		bool operator!=(const Vec2& other) const;
		bool operator>=(const Vec2& other) const;
		bool operator<=(const Vec2& other) const;
		bool operator>(const Vec2& other) const;
		bool operator<(const Vec2& other) const;

		//overload operator +=, -=, *=, /=
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const int& scale);
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const int& scale);
		Vec2& operator/=(const Vec2& other);

		//iostream <<, >>
		friend std::ostream& operator<< (std::ostream& ostream, const Vec2& other);
		friend std::istream& operator>> (std::istream& istream, Vec2 other);
	};
}

