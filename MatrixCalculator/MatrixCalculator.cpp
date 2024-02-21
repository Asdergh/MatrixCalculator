#include "MatrixCalculator.h"


MatrixCalculator::MatrixCalculator()
{
	max_columns = 10;
	max_rows = 10;

	curent_tensor = new float* [max_rows];
	for (int row{ 0 }; row < max_rows; ++row)
	{
		float* vector = new float[max_columns];
		for (int column{ 0 }; column < max_columns; ++column)
		{
			vector[column] = 0.0;
		}
		curent_tensor[row] = vector;
	}
}

MatrixCalculator::MatrixCalculator(int _max_rows, int _max_columns)
{
	max_rows = _max_rows;
	max_columns = _max_columns;
	curent_tensor = new float* [max_rows];
	for (int row{ 0 }; row < max_rows; ++row)
	{
		float* vector = new float[max_columns];
		for (int column{ 0 }; column < max_columns; ++column)
		{
			vector[column] = 0.0;
		}
		curent_tensor[row] = vector;
	}
}

MatrixCalculator::~MatrixCalculator()
{
	for (int row{ 0 }; row < max_rows; ++row)
	{
		delete[] curent_tensor[row];
	}
	delete[] curent_tensor;
}

MatrixCalculator& MatrixCalculator::operator += (const MatrixCalculator& other_matrix_object)
{
	if ((max_columns == other_matrix_object.max_columns) and (max_rows == other_matrix_object.max_rows))
	{
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				curent_tensor[row][column] += other_matrix_object.curent_tensor[row][column];
			}
		}
	}

	return *this;
}

MatrixCalculator& MatrixCalculator::operator + (const MatrixCalculator& other_matrix_object)
{
	if ((max_rows == other_matrix_object.max_rows) and (max_columns == other_matrix_object.max_columns))
	{
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				curent_tensor[row][column] + other_matrix_object.curent_tensor[row][column];
			}
		}
	}

	return *this;
}

MatrixCalculator& MatrixCalculator::operator -= (const MatrixCalculator& other_matrix_object)
{
	if ((max_rows == other_matrix_object.max_rows) and (max_columns == other_matrix_object.max_columns))
	{
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				curent_tensor[row][column] -= other_matrix_object.curent_tensor[row][column];
			}
		}
	}
	
	return *this;
}

MatrixCalculator& MatrixCalculator::operator - (const MatrixCalculator& other_matrix_object)
{
	if ((max_rows == other_matrix_object.max_rows) and (max_columns == other_matrix_object.max_columns))
	{
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				curent_tensor[row][column] - other_matrix_object.curent_tensor[row][column];
			}
		}
	}

	return *this;
}

MatrixCalculator& MatrixCalculator::operator * (const MatrixCalculator& other_matrix_object)
{
	if (max_columns == other_matrix_object.max_rows)
	{
		float** result_tensor = new float* [max_rows];
		for (int row{ 0 }; row < max_rows; ++row)
		{
			float* vector = new float[other_matrix_object.max_columns];
			result_tensor[row] = vector;
		}

		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < other_matrix_object.max_columns; ++column)
			{
				for (int column_1{ 0 }; column_1 < max_columns; ++column_1)
				{
					result_tensor[row][column] += curent_tensor[row][column_1] * other_matrix_object.curent_tensor[column_1][row];
				}
			}
		}
		for (int row{ 0 }; row < max_rows; ++row)
		{
			delete[] curent_tensor[row];
		}
		delete curent_tensor;

		float** curent_tensor = new float* [max_rows];
		for (int row{ 0 }; row < max_rows; ++row)
		{
			curent_tensor[row] = result_tensor[row];
			delete[] result_tensor[row];
		}
		delete[] result_tensor;

		return *this;
		
	}
}

int MatrixCalculator::operator == (const MatrixCalculator& other_matrix_object)
{
	if ((max_rows == other_matrix_object.max_rows) and (max_columns == other_matrix_object.max_columns)) 
	{
		int bool_gate;
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				if (curent_tensor[row][column] == other_matrix_object.curent_tensor[row][column])
				{
					bool_gate = 0;
				}

				else {
					
					bool_gate = 1;
					return bool_gate;
				}
			}
		}

		return bool_gate;
	}
}

int MatrixCalculator::operator != (const MatrixCalculator& other_matrix_object)
{
	if ((max_rows == other_matrix_object.max_rows) and (max_columns == other_matrix_object.max_columns))
	{
		int bool_gate;
		for (int row{ 0 }; row < max_rows; ++row)
		{
			for (int column{ 0 }; column < max_columns; ++column)
			{
				if (curent_tensor[row][column] == other_matrix_object.curent_tensor[row][column])
				{
					bool_gate = 0;
				}

				else {

					bool_gate = 1;
					return bool_gate;
				}
			}
		}

		if (bool_gate == 0) 
		{

			bool_gate = 1;
			return bool_gate;

		}

		else
		{

			bool_gate = 0;
			return bool_gate;
		}
	}
}

std::ostream MatrixCalculator::operator << (std::ostream& os, const MatrixCalculator& other_matrix_object)
{
	for (int row{ 0 }; row < max_rows; ++row)
	{
		for (int column{ 0 }; column < max_columns; ++column)
		{
			os << curent_tensor[row][column] << "\t";
		}
		os << "\n";
	}

	return os;
}

void MatrixCalculator::tensor_random_init()
{
	for (int row{ 0 }; row < max_rows; ++row)
	{
		for (int column{ 0 }; column < max_columns; ++column)
		{
			curent_tensor[row][column] = float(rand() % 9);
		}
	}
}