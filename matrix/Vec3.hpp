#pragma once
#include <iostream>

namespace jrw {
	class Vec3
	{
	public:
		Vec3();
		Vec3(int x, int y, int z);
		~Vec3();

		int x, y, z;

		void print() const;
		Vec3& add(const Vec3& other);
		Vec3& minus(const Vec3& other);
		Vec3& times(const int& scale);
		Vec3& divide(const int& scale);
		Vec3& vtimes(const Vec3& other);
		Vec3& vdivide(const Vec3& other);

		//overload operator +, -, *
		friend Vec3 operator+(Vec3 left, Vec3 right);
		friend Vec3 operator-(Vec3 left, Vec3 right);
		friend Vec3 operator*(Vec3 origin, int scale);
		friend Vec3 operator*(Vec3 left, Vec3 right);
		friend Vec3 operator/(Vec3 origin, int scale);
		friend Vec3 operator/(Vec3 left, Vec3 right);

		//overload operator ==
		bool operator==(const Vec3& other) const;

		//overload operator <=, >=, ==, !=, <, >
		bool operator!=(const Vec3& other) const;
		bool operator>=(const Vec3& other) const;
		bool operator<=(const Vec3& other) const;
		bool operator>(const Vec3& other) const;
		bool operator<(const Vec3& other) const;

		//overload operator +=, -=, *=, /=
		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(const int& scale);
		Vec3& operator*=(const Vec3& other);
		Vec3& operator/=(const int& scale);
		Vec3& operator/=(const Vec3& other);

		//iostream <<, >>
		friend std::ostream& operator<< (std::ostream& ostream, const Vec3& other);
		friend std::istream& operator>> (std::istream& istream, Vec3 other);

		//miscellanous function
		int dot(const Vec3& other); //dot product
		Vec3& cross(const Vec3& other); //cross product
		double magnitude();
		double mag2();
		Vec3& normalized();
		double eulerangle();
		double eulerangleToVector(Vec3 other);
	};
}

