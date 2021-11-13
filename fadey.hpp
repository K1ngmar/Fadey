
#ifndef FADEY_HPP
# define FADEY_HPP

# include <string>
# include <random>

/////////////
// Defines //
/////////////

	# define FADEY_MATRIX_SIZE 6
	# define FADE_SIZE 33

/////////////////
// Fadey class //
/////////////////
	class fadey
	{
	//////////////
	// Typedefs //
	//////////////
	public:
		
		typedef int fade_matrix[FADE_SIZE][FADEY_MATRIX_SIZE];

	//////////////////////
	// Member variables //
	//////////////////////
	private:

		static const  fade_matrix	_fade;
		size_t						_idx;

	//////////////////
	// Construction //
	//////////////////
	public:

		/*
		** IDEAS:
		** --------------
		** - Auto reset (reset after every line)
		** - Reset fade (resets on call)
		** - Vertical / Horizontal / diagonal fade
		** - figure out more fade patterns
		*/

		fadey();
		virtual ~fadey();

	//////////////////
	// Fade helpers //
	//////////////////
	private:

		size_t fadify_line(size_t pos, size_t interval, std::string& line, std::string& to_fade);

	//////////
	// FADE //
	//////////
	public:

		std::string fadify(std::string to_fade);

	}; /* end of fadey class */

#endif
