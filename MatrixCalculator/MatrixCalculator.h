#pragma once

#include <iostream>
#include <math.h>

class MatrixCalculator
{
private:
	
	int max_columns;
	int max_rows;

	float** curent_tensor = new float* [max_rows];

public:

	MatrixCalculator();
	MatrixCalculator(int, int);
	~MatrixCalculator();

	friend std::ostream operator<< (std::ostream&, MatrixCalculator&);

	MatrixCalculator& operator += (const MatrixCalculator&);
	MatrixCalculator& operator + (const MatrixCalculator&);
	MatrixCalculator& operator -= (const MatrixCalculator&);
	MatrixCalculator& operator - (const MatrixCalculator&);
	MatrixCalculator& operator * (const MatrixCalculator&);
	std::ostream operator << (std::ostream&, const MatrixCalculator&);
	int operator == (const MatrixCalculator&);
	int operator != (const MatrixCalculator&);

	void tensor_random_init();


};

