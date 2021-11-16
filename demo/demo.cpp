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

#include <fadey.hpp>
#include <sstream>
#include <fstream>

int main()
{
	std::ifstream file("demo/BANNER");
	std::stringstream buffer;
	buffer << file.rdbuf();
	km::fadey << buffer.str() << std::endl;

	km::fadey << "Every time you seed fady the fade pattern will change :0" << std::endl;

	km::fadey << "Fadey supports a couple ways of fadifying your output :0" << std::endl;

	/* still does not work ffff */
	// km::fadey << "it can also print " << 42069.1f << std::endl; 
	
	return (0);
}
