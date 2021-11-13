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
# include <iostream>
# include <string>
# include <iomanip>

////////////////////////////////
// Do not look at this please //
////////////////////////////////

fadey::fade_matrix const fadey::_fade = {
	{ 52,  53,  54,  55,  56,  57 },
	{ 88,  89,  90,  91,  92,  93 },
	{124, 125, 126, 127, 128, 129 },
	{160, 161, 162, 163, 164, 165 },
	{196, 197, 198, 199, 200, 201 },
	{202, 203, 204, 205, 206, 207 },
	{208, 209, 210, 211, 212, 213 },
	{214, 215, 216, 217, 218, 219 },
	{220, 221, 222, 223, 224, 225 },
	{226, 227, 228, 229, 230, 231 },
	{190, 191, 192, 193, 194, 195 },
	{154, 155, 156, 157, 158, 159 },
	{118, 119, 120, 121, 122, 123 },
	{ 82,  83,  84,  85,  86,  87 },
	{ 46,  47,  48,  49,  50,  51 },
	{ 40,  41,  42,  43,  44,  45 },
	{ 34,  35,  36,  37,  38,  39 },
	{ 28,  29,  30,  31,  32,  33 },
	{ 34,  35,  36,  37,  38,  39 },
	{ 40,  41,  42,  43,  44,  45 },
	{ 46,  47,  48,  49,  50,  51 },
	{ 82,  83,  84,  85,  86,  87 },
	{118, 119, 120, 121, 122, 123 },
	{154, 155, 156, 157, 158, 159 },
	{190, 191, 192, 193, 194, 195 },
	{226, 227, 228, 229, 230, 231 },
	{220, 221, 222, 223, 224, 225 },
	{214, 215, 216, 217, 218, 219 },
	{208, 209, 210, 211, 212, 213 },
	{202, 203, 204, 205, 206, 207 },
	{160, 161, 162, 163, 164, 165 },
	{124, 125, 126, 127, 128, 129 },
	{ 88,  89,  90,  91,  92,  93 }
};

//////////////////
// Construction //
//////////////////

fadey::fadey() : _idx(rand() % FADE_SIZE)
{
}

fadey::~fadey()
{}

//////////
// Fade //
//////////

size_t fadey::fadify_line(size_t pos, size_t interval, std::string& line, std::string& to_fade)
{
	size_t line_pos;

	line_pos = to_fade.find('\n', pos);
	if (line_pos == std::string::npos)
		line_pos = to_fade.length();
	else
		line_pos++;
	
	size_t color = 0;
	for (size_t i = pos; i < line_pos; i++) {
		if ((i - pos) % interval == 0 && color < FADEY_MATRIX_SIZE - 1) {
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

static size_t get_interval(std::string& str)
{
	size_t old_pos = 0;
	size_t line_pos = 0;
	size_t longest_line = 0;

	while (line_pos != str.length())
	{
		line_pos = str.find('\n', old_pos);
		if (line_pos == std::string::npos)
			line_pos = str.length();
		else
			line_pos++;

		if (line_pos - old_pos > longest_line)
			longest_line = line_pos - old_pos;
		old_pos = line_pos;
	}

	size_t interval = longest_line / FADEY_MATRIX_SIZE;
	if (interval == 0)
		interval = 1;
	return (interval);
}

std::string fadey::fadify(std::string to_fade)
{
	std::string faded;

	size_t pos = 0;
	size_t interval = get_interval(to_fade);
	while (pos != to_fade.length()) {
		pos = this->fadify_line(pos, interval, faded, to_fade);
	}

	return (faded);
}
