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

namespace km
{

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

		static const fade_matrix	_fade;
		size_t						_idx;
		size_t						_reset_idx;
		std::ostream&				_stream;
		bool						_auto_reset;

	//////////////////
	// Construction //
	//////////////////
	public:

		/*
		** IDEAS:
		** --------------
		** - Vertical / Horizontal / diagonal fade
		** - figure out more fade patterns
		** - pass colors which to fade
		** - set fade length
		** - make it read and fade instantly
		** - set start color of fade pattern
		*/

		Fadey(bool auto_reset = false, std::ostream& stream = std::cout);
		virtual ~Fadey();

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

	/////////////
	// Setters //
	/////////////
	public:

		/* resets fade */
		void	set_auto_reset(bool auto_reset);
		void	reset_fade();

		void	new_seed();

	///////////////////////////////
	// Stream operator overlaods //
	///////////////////////////////
	public:

		// template < class integral, typename std::enable_if<std::is_integral<integral>::value>::type >
		template < class integral >
			Fadey& operator << (integral val)
		{
			*this << std::to_string(val);
			return (*this);
		}

		friend Fadey& operator << (Fadey& f, void* val);
		
		friend Fadey& operator << (Fadey& f, const char* str);

		friend Fadey& operator << (Fadey& f, std::string str);

		friend Fadey& operator << (Fadey& f, std::string& str);

		friend Fadey& operator << (Fadey& f, std::ostream& (*pf)(std::ostream&));


	/*
	** I dont know how to implement this
	*/

		// friend Fadey& operator << (Fadey& f, std::streambuf* sb );

		// friend Fadey& operator << (Fadey& f, std::ios& (*pf)(std::ios&));

		// friend Fadey& operator << (Fadey& f, std::ios_base& (*pf)(std::ios_base&));

	}; /* end of Fadey class */

	//////////////////////
	// Global Fadey pog //
	//////////////////////

		extern Fadey fadey;

} /* end of namespace km */

#endif
