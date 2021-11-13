
#include <fadey.hpp>
# include <iostream>
# include <string>
# include <iomanip>


//////////////////
// Construction //
//////////////////

fadey::fadey()
{
	_idx = rand() % FADE_SIZE;
	colors_init();
	make_fade_matrix();
}

fadey::~fadey()
{}

//////////
// Init //
//////////

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

	// for (size_t l = 0; l < FADE_SIZE; l++) {
	// 	for (size_t u = 0; u < FADEY_MATRIX_SIZE; u++) {
	// 		std::cout << "\e[38;5;" << _fade[l][u] << "m" << "pog" << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
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

//////////
// Fade //
//////////

size_t fadey::fadify_line(size_t pos, std::string& line, std::string& to_fade)
{
	size_t line_pos;

	line_pos = to_fade.find('\n', pos);
	if (line_pos == std::string::npos)
		line_pos = to_fade.length();
	else
		line_pos++;

	size_t interval = (line_pos - pos) / FADEY_MATRIX_SIZE;
	if (interval == 0)
		interval = 1;
	size_t color = 0;
	for (size_t i = pos; i < line_pos; i++) {
		if (i % interval == 0 && color < FADEY_MATRIX_SIZE - 1) {
			color++;
			line += "\033[38;5;" + std::to_string(_fade[_idx][color]) + "m";
		}
		line += to_fade[i];
	}

	_idx++;
	if (_idx == FADE_SIZE)
		_idx = 0;
	return (line_pos);
}

std::string fadey::fadify(std::string to_fade)
{
	std::string faded;

	size_t pos = 0;
	while (pos != to_fade.length()) {
		pos = this->fadify_line(pos, faded, to_fade);
	}

	return (faded);
}
