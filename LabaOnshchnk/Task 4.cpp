#include <iostream>

struct mas {
	int m;
	int n;
	double value;
};

class Matrix {
	int dim1, dim2;
	mas** array;
	void create() {
		array = new mas * [dim1];
		for (int i = 0; i < dim1; i++) {
			array[i] = new mas[dim2];
		}
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++)
				array[i][j].value = 0;
		}
	}

public:

	Matrix() {
		dim1 = dim2 = 2;
		create();
	}

	Matrix(int dim1, int dim2) {
		this->dim1 = dim1;
		this->dim2 = dim2;
		create();
	}

	Matrix(const Matrix& other) {
		dim1 = other.dim1;
		dim2 = other.dim2;
		array = new mas * [dim1];
		for (int i = 0; i < dim1; i++) {
			array[i] = new mas[dim2];
		}
		for (int i = 0; i < other.dim1; i++) {
			for (int j = 0; j < other.dim2; j++)
				array[i][j].value = other.array[i][j].value;
		}
	}

	~Matrix() {
		for (int i = 0; i < dim1; i++) {
			delete array[i];
		}
		delete[] array;
	}

	void add(int m, int n, double val) {
		array[m][n].value = val;
		array[m][n].m = m;
		array[m][n].n = n;
	}

	void print() {
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++) {
                std::cout << array[i][j].value << " ";
            }	
			std::cout << std::endl;
		}
	}

	friend Matrix operator+ (const Matrix& left, const Matrix& right);
	friend Matrix operator- (const Matrix& left, const Matrix& right);
	friend Matrix operator* (const Matrix& left, const Matrix& right);
	friend Matrix operator/ (const Matrix& left, double right);

	Matrix operator= (const Matrix& right) {
		dim1 = right.dim1;
		dim2 = right.dim2;
		array = new mas * [dim1];
		for (int i = 0; i < dim1; i++) {
			array[i] = new mas[dim2];
		}
		for (int i = 0; i < right.dim1; i++) {
			for (int j = 0; j < right.dim2; j++) {
                array[i][j].value = right.array[i][j].value;
            }	
		}
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const Matrix& x); 
		friend std::istream& operator>> (std::istream& in, Matrix& x);
};

Matrix operator+ (const Matrix& left, const Matrix& right) {
	Matrix res(right);
	if ((left.dim1 == right.dim1) && (left.dim2 == right.dim2)) {
        for (int i = 0; i < res.dim1; ++i) {
            for (int j = 0; j < res.dim2; ++j){
                res.array[i][j].value += left.array[i][j].value;
            }
        }	
		return res;
	}
	std::cout << "OMF WTF ICQ!" << std::endl;
	else exit(1);
	
}

Matrix operator- (const Matrix& left, const Matrix& right) {
	Matrix res(left);
	if ((left.dim1 == right.dim1) && (left.dim2 == right.dim2)) {
        for (int i = 0; i < res.dim1; ++i) {
            for (int j = 0; j < res.dim2; ++j) {
                res.array[i][j].value -= right.array[i][j].value;
            }    
        }	
		return res;
	}
    std::cout << "OMF WTF ICQ!" << std::endl;
	else exit(1);
}

Matrix operator* (const Matrix& left, const Matrix& right) {
	Matrix out(left.dim1, right.dim2);
	for (int i = 0; i < left.dim1; i++) {
		for (int j = 0; j < right.dim2; j++) {
			for (int k = 0; k < right.dim1; k++) {
                out.array[i][j].value += left.array[i][k].value * right.array[k][j].value;
            }	
		}
	}
	return out;
}

Matrix operator/ (const Matrix& left, double right) {
    Matrix res(left);
    for (int i = 0; i < left.dim1; i++) {
        for (int j = 0; j < left.dim2; j++) {
            res.array[i][j].value *= right;
        }
    }	
	return res;
}

std::ostream& operator<< (std::ostream& out, const Matrix& x) {
	for (int i = 0; i < x.dim1; i++) {
        for (int j = 0; j < x.dim2; j++) {
            out << x.array[i][j].value << " ";
        }
		out << std::endl;
	}
	return out;
}

std::istream& operator>> (std::istream& in, Matrix& x) {
	std::cout << "Input dimensions: " << std::endl;
	in >> x.dim1 >> x.dim2;
	x.create();
	std::cout << "Input values: " << std::endl;
	for (int i = 0; i < x.dim1; i++) {
        for (int j = 0; j < x.dim2; j++) {
            in >> x.array[i][j].value;
        }
	}
	return in;
}

int main() {
	Matrix d;
	std::cin >> d;
	Matrix e(2, 1);
	std::cin >> e;
	std::cout << (d * e);
	((d * e) / 2).print();
	return 0;
}
