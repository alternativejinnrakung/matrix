#pragma once
#include "Vec2.hpp"
#include "Vec3.hpp"

#include <iostream>
#include <vector>

namespace jrw {
	class Mat
	{
	public:
		Mat();
		Mat(std::vector<std::vector<int>> mat);
		~Mat();

		std::vector<std::vector<int>> matrix;
		int matrixsize = 0;

		void print();

		Mat& timesScale(int scale);
		std::vector<int>& timesVec2(Vec2 vector);
		std::vector<int>& timesVec3(Vec3 vector);
		std::vector<int>& timesMatrix(Mat mat2);

		friend Mat operator*(Mat origin, int scale);
		friend std::vector<int> operator*(Mat thismat, Vec2 vector);
		friend std::vector<int> operator*(Mat thismat, Vec3 vector);
		friend std::vector<int> operator*(Mat left, Mat right);

		int det();
		Mat& transpose();
		Mat& rotate(int degree);
		Mat& rotate2x2(int degree);
		Mat& rotate3x3(int degree);

		Mat& identity();
		Mat& zeros();
	};
}

