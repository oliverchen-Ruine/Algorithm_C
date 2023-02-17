#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
	int rows;
	int cols;
	vector<vector<int>> intMatrix;
	vector<vector<float>> floatMatrix;
	bool isInt = true;
public:
	Matrix(int r, int c) : rows(r), cols(c) {
		intMatrix.resize(rows, vector<int>(cols, 0));
		floatMatrix.resize(rows, vector<float>(cols, 0));
	}
	void setElement(int r, int c, int value) {
		intMatrix[r][c] = value;
		isInt = true;
	}
	void setElement(int r, int c, float value) {
		floatMatrix[r][c] = value;
		isInt = false;
	}
	int getElement(int r, int c) {
		return intMatrix[r][c];
	}
	float getElement(int r, int c, bool isInt) {
		if (!isInt)
		{
			return floatMatrix[r][c];
		}
		return float(0);
		
	}
	int getRows() {
		return this->rows;
	}
	int getCols() {
		return this->cols;
	}
	void print() {
		if (isInt) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << intMatrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << floatMatrix[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	Matrix operator*(Matrix& other) {
		if (cols != other.rows) {
			throw invalid_argument("The number of columns of the first matrix must match the number of rows of the second matrix.");
		}
		Matrix result(rows, other.cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < other.cols; j++) {
				float sum = 0;
				for (int k = 0; k < cols; k++) {
					sum += floatMatrix[i][k] * other.floatMatrix[k][j];
				}
				result.setElement(i, j, sum);
			}
		}
		return result;
	}
};
