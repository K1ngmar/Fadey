
#ifndef FADEY_HPP
# define FADEY_HPP

# include <string>

/////////////
// Defines //
/////////////

	# define FADEY_MATRIX_SIZE 6
	# define FADE_SIZE 19

/////////////////
// Fadey class //
/////////////////
	class fadey
	{
	//////////////
	// Typedefs //
	//////////////
	private:
		
		typedef int	color_matrix[FADEY_MATRIX_SIZE][FADEY_MATRIX_SIZE][FADEY_MATRIX_SIZE];
		typedef int fade_matrix[FADE_SIZE][FADEY_MATRIX_SIZE];

	//////////////////////
	// Member variables //
	//////////////////////
	private:

		color_matrix	_matrix;
		fade_matrix		_fade;

	//////////////////
	// Construction //
	//////////////////
	public:

		fadey();
		virtual ~fadey();

	//////////
	// init //
	//////////
	private:

		void	put_row_in_fade(size_t& i, size_t z, size_t y);
		void	init_fade_reverse_y_axis(int color, size_t& i);
		void	init_fade_y_axis(int color, size_t& i);
		void	init_fade_z_axis(int color, size_t& i);
		void	init_fade_reverse_z_axis(int color, size_t& i);
		void	make_fade_matrix();
		void	colors_init();

	}; /* end of fadey class */

#endif
