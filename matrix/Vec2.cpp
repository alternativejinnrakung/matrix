#include "Vec2.hpp"

namespace jrw {
	Vec2::Vec2()
	{
	}

	Vec2::Vec2(int input_x, int input_y)
		:x(input_x), y(input_y)
	{

	}

	Vec2::~Vec2() {

	}

	void Vec2::print() const {
		std::cout << "v: (" << x << ", " << y << ")" << std::endl;
	}

	Vec2& Vec2::add(const Vec2& other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	Vec2& Vec2::minus(const Vec2& other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vec2& Vec2::times(const int& scale) {
		x *= scale;
		y *= scale;

		return *this;
	}

	Vec2& Vec2::divide(const int& scale) {
		x /= scale;
		y /= scale;

		return *this;
	}

	Vec2& Vec2::vtimes(const Vec2& other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vec2& Vec2::vdivide(const Vec2& other) {
		x /= other.x;
		y /= other.y;

		return *this;
	}

	Vec2 operator+(Vec2 left, Vec2 right) {
		return left.add(right);
	}

	Vec2 operator-(Vec2 left, Vec2 right) {
		return left.minus(right);
	}

	Vec2 operator*(Vec2 origin, int scale) {
		return origin.times(scale);
	}

	Vec2 operator*(Vec2 left, Vec2 right) {
		return left.vtimes(right);
	}

	Vec2 operator/(Vec2 origin, int scale) {
		return origin.divide(scale);
	}

	Vec2 operator/(Vec2 left, Vec2 right) {
		return left.vdivide(right);
	}

	bool Vec2::operator==(const Vec2& other) const {
		return ((this->x == other.x) && (this->y == other.y));
	}

	int Vec2::dot(const Vec2& other) {
		return ((this->x * other.x) + (this->y * other.y));
	}

	int Vec2::cross(const Vec2& other) {
		return ((this->x * other.y) - (this->y * other.x));
	}

	double Vec2::magnitude() {
		return std::sqrt(this->mag2());
	}

	double Vec2::mag2() {
		return std::pow(this->x, 2) + std::pow(this->y, 2);
	}

	Vec2& Vec2::normalized() {
		double magn = this->magnitude();
		x = static_cast<int>((x / magn) * 100);
		y = static_cast<int>((y / magn) * 100);

		return *this;
	}

	double Vec2::eulerangle() {
		return std::atan(this->y / this->x);
	}

	double Vec2::eulerangleToVector(Vec2 other) {
		int dot_value = this->dot(other);
		double thismag = this->magnitude();
		double thatmag = other.magnitude();
		double degree = std::acos(dot_value / (thismag / thatmag));
		return degree;
	}

	bool Vec2::operator!=(const Vec2& other) const {
		return ((this->x != other.x) && (this->y != other.y));
	}

	bool Vec2::operator>=(const Vec2& other) const {
		return ((this->x >= other.x) && (this->y >= other.y));
	}

	bool Vec2::operator<=(const Vec2& other) const {
		return ((this->x <= other.x) && (this->y <= other.y));
	}

	bool Vec2::operator>(const Vec2& other) const {
		return ((this->x > other.x) && (this->y > other.y));
	}

	bool Vec2::operator<(const Vec2& other) const {
		return ((this->x < other.x) && (this->y < other.y));
	}

	Vec2& Vec2::operator+=(const Vec2& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& other) {
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Vec2& Vec2::operator*=(const int& scale) {
		this->x *= scale;
		this->y *= scale;
		return *this;
	}

	Vec2& Vec2::operator*=(const Vec2& other) {
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	Vec2& Vec2::operator/=(const int& scale) {
		this->x /= scale;
		this->y /= scale;
		return *this;
	}

	Vec2& Vec2::operator/=(const Vec2& other) {
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	std::ostream& operator<< (std::ostream& ostream, const Vec2& other) {
		return ostream << "( " << other.x << ", " << other.y << " )";
	}

	std::istream& operator>> (std::istream& istream, Vec2 other) {
		return istream >> other.x >> other.y;
	}
}