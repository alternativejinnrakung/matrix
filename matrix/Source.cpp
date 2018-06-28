#include "Mat.hpp"

using namespace jrw;

std::vector<std::vector<int>> getMatrix(int size) {
	std::vector<std::vector<int>> matrix;
	for (int i = 0; i < size; i++) {
		std::vector<int> thisline;
		for (int j = 0; j < size; j++) {
			thisline.push_back(j);
		}
		matrix.push_back(thisline);
	}
	return matrix;
}

int main() {
	std::vector<std::vector<int>> matrix = getMatrix(4);
	Mat m1(matrix);
	m1.transpose();
	m1.print();
	getchar();
	return 0;
}