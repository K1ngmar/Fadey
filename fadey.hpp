/* ************************************************************************** */
/*                                                                            */
/*       _     _      _     _      _     _      _     _      _     _          */
/*      (c).-.(c)    (c).-.(c)    (c).-.(c)    (c).-.(c)    (c).-.(c)         */
/*       / ._. \      / ._. \      / ._. \      / ._. \      / ._. \          */
/*     __\( Y )/__  __\( Y )/__  __\( Y )/__  __\( Y )/__  __\( Y )/__        */
/*    (_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)       */
/*       || F ||      || A ||      || D ||      || E ||      || Y ||          */
/*     _.' `-' '._  _.' `-' '._  _.' `-' '._  _.' `-' '._  _.' `-' '._        */
/*    (.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)       */
/*     `-'     `-'  `-'     `-'  `-'     `-'  `-'     `-'  `-'     `-'        */
/*                                                                            */
/*                   Kingmar  |  https://github.com/K1ngmar                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FADEY_HPP
# define FADEY_HPP

# include <string>
# include <random>
# include <iostream>

/////////////
// Defines //
/////////////

	# define FADEY_MATRIX_SIZE 6
	# define FADE_SIZE 33

	# define COLOR_RESET "\033[0m"

/////////////////
// Fadey class //
/////////////////
	class Fadey
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
		std::ostream&				_stream;


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
		** - pass colors which to fade
		** - set fade length
		*/

		Fadey(std::ostream& stream = std::cout);
		virtual ~Fadey();

		friend std::ostream& operator << (Fadey& f, std::string str);

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

	}; /* end of Fadey class */

//////////////////////
// Global Fadey pog //
//////////////////////

	extern Fadey fadey;

#endif
