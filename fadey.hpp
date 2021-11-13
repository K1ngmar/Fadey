
#ifndef FADEY_HPP
# define FADEY_HPP

# include <string>
# include <random>

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
		size_t			_idx;

	//////////////////
	// Construction //
	//////////////////
	public:

		/*
		** IDEAS:
		** --------------
		** - Auto reset (reset after every line)
		** - Reset fade (resets on call)
		** - Vertical / Horizontal fade
		** - figure out more fade patterns
		*/

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

	//////////////////
	// Fade helpers //
	//////////////////
	private:

		size_t fadify_line(size_t pos, std::string& line, std::string& to_fade);

	//////////
	// FADE //
	//////////
	public:

		std::string fadify(std::string to_fade);

	}; /* end of fadey class */

#endif
