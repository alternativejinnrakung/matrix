#include "Vec3.hpp"

namespace jrw {
	Vec3::Vec3()
	{
	}

	Vec3::Vec3(int input_x, int input_y, int input_z)
		:x(input_x), y(input_y), z(input_z)
	{

	}

	Vec3::~Vec3()
	{
	}

	void Vec3::print() const {
		std::cout << "v: (" << x << ", " << y << ", " << z << ")" << std::endl;
	}

	Vec3& Vec3::add(const Vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}
	Vec3& Vec3::minus(const Vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vec3& Vec3::times(const int& scale) {
		x *= scale;
		y *= scale;
		z *= scale;

		return *this;
	}

	Vec3& Vec3::divide(const int& scale) {
		x /= scale;
		y /= scale;
		z /= scale;

		return *this;
	}
	Vec3& Vec3::vtimes(const Vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	Vec3& Vec3::vdivide(const Vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	Vec3 operator+(Vec3 left, Vec3 right) {
		return left.add(right);
	}

	Vec3 operator-(Vec3 left, Vec3 right) {
		return left.minus(right);
	}

	Vec3 operator*(Vec3 origin, int scale) {
		return origin.times(scale);
	}

	Vec3 operator*(Vec3 left, Vec3 right) {
		return left.vtimes(right);
	}

	Vec3 operator/(Vec3 origin, int scale) {
		return origin.divide(scale);
	}

	Vec3 operator/(Vec3 left, Vec3 right) {
		return left.vdivide(right);
	}

	bool Vec3::operator==(const Vec3& other) const {
		return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
	}

	bool Vec3::operator!=(const Vec3& other) const {
		return ((this->x != other.x) && (this->y != other.y));
	}

	bool Vec3::operator>=(const Vec3& other) const {
		return ((this->x >= other.x) && (this->y >= other.y));
	}

	bool Vec3::operator<=(const Vec3& other) const {
		return ((this->x <= other.x) && (this->y <= other.y));
	}

	bool Vec3::operator>(const Vec3& other) const {
		return ((this->x > other.x) && (this->y > other.y));
	}

	bool Vec3::operator<(const Vec3& other) const {
		return ((this->x < other.x) && (this->y < other.y));
	}

	Vec3& Vec3::operator+=(const Vec3& other) {
		return this->add(other);
	}

	Vec3& Vec3::operator-=(const Vec3& other) {
		return this->minus(other);
	}

	Vec3& Vec3::operator*=(const int& scale) {
		return this->times(scale);
	}

	Vec3& Vec3::operator*=(const Vec3& other) {
		return this->vtimes(other);
	}

	Vec3& Vec3::operator/=(const int& scale) {
		return this->divide(scale);
	}

	Vec3& Vec3::operator/=(const Vec3& other) {
		return this->vdivide(other);
	}

	std::ostream& operator<< (std::ostream& ostream, const Vec3& other) {
		return ostream << "( " << other.x << ", " << other.y << ", " << other.z << " )";
	}

	std::istream& operator>> (std::istream& istream, Vec3 other) {
		return istream >> other.x >> other.y >> other.z;
	}

	int Vec3::dot(const Vec3& other) {
		return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
	}

	Vec3& Vec3::cross(const Vec3& other) {
		int crossx = ((this->y * other.z) - (this->z * other.y));
		int crossy = ((this->z * other.x) - (this->x * other.z));
		int crossz = ((this->x * other.y) - (this->y * other.x));

		x = crossx;
		y = crossy;
		z = crossz;

		return *this;
	}

	double Vec3::magnitude() {
		return std::sqrt(this->mag2());
	}

	double Vec3::mag2() {
		return std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2);
	}

	Vec3& Vec3::normalized() {
		double magn = this->magnitude();
		x = static_cast<int>((x / magn) * 100);
		y = static_cast<int>((y / magn) * 100);
		z = static_cast<int>((z / magn) * 100);

		return *this;
	}

	double Vec3::eulerangle() {
		return 0.0;
	}

	double Vec3::eulerangleToVector(Vec3 other) {
		return std::acos(this->dot(other) / (this->magnitude() * other.magnitude()));
	}
}