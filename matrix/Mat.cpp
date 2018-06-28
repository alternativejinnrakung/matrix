#include "Mat.hpp"

namespace jrw {
	Mat::Mat()
	{
	}

	Mat::Mat(std::vector<std::vector<int>> mat) 
		: matrix(mat) 
	{
		matrixsize = static_cast<int>(mat.size());
	}

	Mat::~Mat()
	{
	}

	void Mat::print() {
		for (int i = 0; i < matrixsize; i++) {
			for (int j = 0; j < matrixsize; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	Mat& Mat::timesScale(int scale) {
		for (int i = 0; i < matrixsize; i++) {
			for (int j = 0; j < matrixsize; j++) {
				matrix[i][j] *= scale;
			}
		}

		return *this;
	}

	std::vector<int>& Mat::timesVec2(Vec2 vector) {
		std::vector<int> newmatrix;
		int currentnumber = 0;
		if (matrixsize != 2) {
			std::cout << "Size Error";
			return newmatrix;
		}
		for (int i = 0; i < matrixsize; i++) {
			currentnumber += matrix[i][0] * vector.x;
			currentnumber += matrix[i][1] * vector.y;
			newmatrix.push_back(currentnumber);
			currentnumber = 0;
		}

		return newmatrix;
	}

	std::vector<int>& Mat::timesVec3(Vec3 vector) {
		std::vector<int> newmatrix;
		int currentnumber = 0;
		if (matrixsize != 3) {
			std::cout << "Size Error";
			return newmatrix;
		}
		for (int i = 0; i < matrixsize; i++) {
			currentnumber += matrix[i][0] * vector.x;
			currentnumber += matrix[i][1] * vector.y;
			currentnumber += matrix[i][2] * vector.z;
			newmatrix.push_back(currentnumber);
			currentnumber = 0;
		}

		return newmatrix;
	}

	std::vector<int>& Mat::timesMatrix(Mat mat2) {
		std::vector<int> newmatrix;
		int currentnumber = 0;
		if (matrixsize != mat2.matrixsize) {
			return newmatrix;
		}
		for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
			for (int j = 0; j < static_cast<int>(matrix[i].size()); j++) {
				currentnumber += matrix[i][j] * mat2.matrix[j][i];
			}
			newmatrix.push_back(currentnumber);
			currentnumber = 0;
		}

		return newmatrix;
	}

	Mat operator*(Mat origin, int scale) {
		return origin.timesScale(scale);
	}

	std::vector<int> operator*(Mat thismat, Vec2 vector) {
		return thismat.timesVec2(vector);
	}

	std::vector<int> operator*(Mat thismat, Vec3 vector) {
		return thismat.timesVec3(vector);
	}

	std::vector<int> operator*(Mat mat1, Mat mat2) {
		return mat1.timesMatrix(mat2);
	}

	int Mat::det() {
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}

	Mat& Mat::transpose() {
		std::vector<std::vector<int>> newmatrix;
		for (int i = 0; i < matrixsize; i++) {
			std::vector<int> thisline;
			for (int j = 0; j < matrixsize; j++) {
				thisline.push_back(matrix[j][i]);
			}
			newmatrix.push_back(thisline);
		}
		matrix = newmatrix;

		return *this;
	}

	Mat& Mat::rotate(int degree) {
		if (matrixsize == 2) {
			return rotate2x2(degree);
		}
		else if (matrixsize == 3) {
			return rotate3x3(degree);
		}
	}

	Mat& Mat::rotate2x2(int degree) {
		std::vector<std::vector<int>> degreemat;
		std::vector<int> thisline;
		thisline.push_back(std::cos(degree)); 
		thisline.push_back(std::sin(degree));
		degreemat.push_back(thisline);
		thisline[0] = std::sin(degree) * -1.0;
		thisline[1] = std::cos(degree);
		degreemat.push_back(thisline);

		Mat dmat(degreemat);

		this->timesMatrix(degreemat);
		return *this;
	}

	Mat& Mat::rotate3x3(int degree) {
		
	}

	Mat& Mat::identity() {
		for (int i = 0; i < matrixsize; i++) {
			for (int j = 0; j < matrixsize; j++) {
				if (i == j) {
					matrix[i][j] = 1;
				}
				else {
					matrix[i][j] = 0;
				}
			}
		}

		return *this;
	}

	Mat& Mat::zeros() {
		for (int i = 0; i < matrixsize; i++) {
			for (int j = 0; j < matrixsize; j++) {
				matrix[i][j] = 0;
			}
		}

		return *this;
	}
}