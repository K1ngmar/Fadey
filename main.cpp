
# include <iostream>
# include <string>
# include <iomanip>

# define MATRIX_SIZE 6
# define FADE_SIZE 19


typedef int	color_matrix[MATRIX_SIZE][MATRIX_SIZE][MATRIX_SIZE];
typedef int fade_matrix[FADE_SIZE][MATRIX_SIZE];

static void	put_row_in_fade(size_t& i, size_t z, size_t y, fade_matrix fade, color_matrix matrix)
{
	for (size_t x = 0; x < MATRIX_SIZE; x++) 
		fade[i][x] = matrix[z][y][x];
	i++;
}

static void	init_fade_reverse_y_axis(int color, size_t& i, fade_matrix fade, color_matrix matrix)
{
	for (size_t z = 4; z > 0; z--)
		put_row_in_fade(i, z, color, fade, matrix);
}

static void	init_fade_y_axis(int color, size_t& i, fade_matrix fade, color_matrix matrix)
{
	for (size_t z = 1; z < 5; z++)
		put_row_in_fade(i, z, color, fade, matrix);
}

static void	init_fade_z_axis(int color, size_t& i, fade_matrix fade, color_matrix matrix)
{
	for (size_t y = 0; y < MATRIX_SIZE; y++)
		put_row_in_fade(i, color, y, fade, matrix);
}

static void	init_fade_reverse_z_axis(int color, size_t& i, fade_matrix fade, color_matrix matrix)
{
	for (size_t y = 5; y > 0; y--)
		put_row_in_fade(i, color, y, fade, matrix);
}

static void	make_fade_matrix(fade_matrix fade, color_matrix matrix)
{
	size_t i = 0;

	init_fade_z_axis(5, i, fade, matrix);
	init_fade_reverse_y_axis(5, i, fade, matrix);
	init_fade_reverse_z_axis(0, i, fade, matrix);
	init_fade_y_axis(0, i, fade, matrix);
	
	// for (size_t l = 0; l < FADE_SIZE; l++) {
	// 	for (size_t u = 0; u < MATRIX_SIZE; u++) {
	// 		std::cout << "\e[38;5;" << fade[l][u] << "m" << "pog" << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
}


void	colors_init(color_matrix matrix)
{
	/* skip first 16 colors */
	int color = 16;

	for (size_t z = 0; z < MATRIX_SIZE; ++z) {
		for (size_t y = 0; y < MATRIX_SIZE; ++y) {
			for (size_t x = 0; x < MATRIX_SIZE; ++x) {
				matrix[z][y][x] = color;
				color++;
			}
		}
	}
}

int main(void)
{
	color_matrix	matrix;
	fade_matrix		fade;

	colors_init(matrix);
	make_fade_matrix(fade, matrix);
}