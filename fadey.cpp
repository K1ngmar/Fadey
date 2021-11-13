
#include <fadey.hpp>
# include <iostream>
# include <string>
# include <iomanip>


fadey::fadey()
{
	colors_init();
	make_fade_matrix();
}

fadey::~fadey()
{}


void	fadey::put_row_in_fade(size_t& i, size_t z, size_t y)
{
	for (size_t x = 0; x < FADEY_MATRIX_SIZE; x++) 
		_fade[i][x] = _matrix[z][y][x];
	i++;
}

void	fadey::init_fade_reverse_y_axis(int color, size_t& i)
{
	for (size_t z = 4; z > 0; z--)
		put_row_in_fade(i, z, color);
}

void	fadey::init_fade_y_axis(int color, size_t& i)
{
	for (size_t z = 1; z < 5; z++)
		put_row_in_fade(i, z, color);
}

void	fadey::init_fade_z_axis(int color, size_t& i)
{
	for (size_t y = 0; y < FADEY_MATRIX_SIZE; y++)
		put_row_in_fade(i, color, y);
}

void	fadey::init_fade_reverse_z_axis(int color, size_t& i)
{
	for (size_t y = 5; y > 0; y--)
		put_row_in_fade(i, color, y);
}

void	fadey::make_fade_matrix()
{
	size_t i = 0;

	init_fade_z_axis(5, i);
	init_fade_reverse_y_axis(5, i);
	init_fade_reverse_z_axis(0, i);
	init_fade_y_axis(0, i);
	
	for (size_t l = 0; l < FADE_SIZE; l++) {
		for (size_t u = 0; u < FADEY_MATRIX_SIZE; u++) {
			std::cout << "\e[38;5;" << _fade[l][u] << "m" << "pog" << " ";
		}
		std::cout << std::endl;
	}
}

void	fadey::colors_init()
{
	/* skip first 16 colors */
	int color = 16;

	for (size_t z = 0; z < FADEY_MATRIX_SIZE; ++z) {
		for (size_t y = 0; y < FADEY_MATRIX_SIZE; ++y) {
			for (size_t x = 0; x < FADEY_MATRIX_SIZE; ++x) {
				_matrix[z][y][x] = color;
				color++;
			}
		}
	}
}

