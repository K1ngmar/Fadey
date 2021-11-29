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

struct demo
{
	int a;
};


int main()
{
	std::ifstream file("demo/BANNER");
	std::stringstream buffer;
	buffer << file.rdbuf();
	km::fadey.backgroundColor(0x0F0F0F);
	km::fadey << buffer.str() << std::endl;
	km::fadey.backgroundColorReset();

	km::fadey << "Every time you seed fady the fade pattern will change :0" << std::endl;

	km::fadey << "Fadey supports a couple ways of fadifying your output :0" << std::endl;

	/* still does not work ffff */
	km::fadey << "it can also print " << 42069 << std::endl;
	km::fadey << "it can also print " << (long)42069 << std::endl;


	for (size_t i = 0; i < FADE_SIZE; i++)
		km::fadey << km::blue << ": WOOOW FADEY" << std::endl;
	
	return (0);
}
