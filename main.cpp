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

#include<fadey.hpp>
#include<iostream>
#include<fstream>
#include <sstream>

int main(void)
{
	srand(time(NULL));

	std::ifstream file("README.md");
	std::stringstream buffer;
	buffer << file.rdbuf();

	fadey << buffer.str() << std::endl;
	

	fadey.set_auto_reset(true);
	fadey.new_seed();
	for (size_t i = 0; i < 5; i++)
		std::cout << fadey.fadify("Fadey is amazing") << std::endl;

	// for(size_t i = 0; i < 69; i++)

}
