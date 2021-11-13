
# include <iostream>
# include <string>
# include <iomanip>


void		set_color(char c, std::string& s)
{
	s += c;
	s += ';';
}

/*
** 38 to set foreground color;
** 2 for rgb format;
*/
std::string	set_rgb(char r, char g, char b)
{
	std::string ret = "\e[38;2;";
	set_color(r, ret);
	set_color(g, ret);
	set_color(b, ret);
	ret += "m";
	return (ret);
}

void	broken_rgb()
{
	for (size_t r = 0; r < 16; ++r) {
		for (size_t g = 0; g < 16; ++g) {
			for (size_t b = 0; b < 16; ++b) {
				std::cout << set_rgb(r, g, b) \
					<< "r: " << std::to_string(r) \
					<< " g: " << std::to_string(g) \
					<< " b: " << std::to_string(b) \
					<< std::endl;			
			}
		}
	}
}

void	working_colors()
{
	// char fade[] = {17, 18, 19, 20, 21, 26, 27};
	int WTF[6][6][6];

	int color = 16;
	for (size_t z = 0; z < 6; ++z) {
		for (size_t y = 0; y < 6; ++y) {
			for (size_t x = 0; x < 6; ++x) {
				WTF[z][y][x] = color;
				// std::cout << "\e[38;5;" << color << "m" << color << " ";
				color++;
			}
			// std::cout << std::endl;
		}
	}

	int fade_color = 5;
	for (size_t y = 0; y < 6; y++) {
		for (size_t x = 0; x < 6; x++) {
			std::cout << "\e[38;5;" << WTF[fade_color][y][x] << "m" << "pog" << " ";
		}
		std::cout << std::endl;
	}
	for (size_t z = 4; z > 0; z--) {
		for (size_t x = 0; x < 6; x++) {
			std::cout << "\e[38;5;" << WTF[z][fade_color][x] << "m" << "pog" << " ";
		}
		std::cout << std::endl;
	}
	fade_color = 0;
	for (size_t y = 5; y > 0; y--) {
		for (size_t x = 0; x < 6; x++) {
			std::cout << "\e[38;5;" << WTF[fade_color][y][x] << "m" << "pog" << " ";
		}
		std::cout << std::endl;
	}
	for (size_t z = 1; z < 5; z++) {
		for (size_t x = 0; x < 6; x++) {
			std::cout << "\e[38;5;" << WTF[z][fade_color][x] << "m" << "pog" << " ";
		}
		std::cout << std::endl;
	}
	
	// for (size_t i = 1; i + 15 < 232; ++i) {
	// 	std::cout << "\e[38;5;" << i + 15 << "m" << i + 15 << " ";
	// 	if (i % 6 == 0)
	// 		std::cout << std::endl;
	// }
}

int main(void)
{
	// broken_rgb();
	working_colors();
}