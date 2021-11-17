#  **************************************************************************  #
#                                                                              #
#        _     _      _     _      _     _      _     _      _     _           #
#       (c).-.(c)    (c).-.(c)    (c).-.(c)    (c).-.(c)    (c).-.(c)          #
#        / ._. \      / ._. \      / ._. \      / ._. \      / ._. \           #
#      __\( Y )/__  __\( Y )/__  __\( Y )/__  __\( Y )/__  __\( Y )/__         #
#     (_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)(_.-/'-'\-._)        #
#        || F ||      || A ||      || D ||      || E ||      || Y ||           #
#      _.' `-' '._  _.' `-' '._  _.' `-' '._  _.' `-' '._  _.' `-' '._         #
#     (.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)(.-./`-'\.-.)        #
#      `-'     `-'  `-'     `-'  `-'     `-'  `-'     `-'  `-'     `-'         #
#                                                                              #
#                    Kingmar  |  https://github.com/K1ngmar                    #
#                                                                              #
#  **************************************************************************  #

NAME		=	libfadey.a

CC			=	g++

FLAGS		=	-std=c++98 -pedantic -Wall -Werror -Wextra

DEBUG_FLAGS	=	-g -fsanitize=address

SRC			=	src/fadey.cpp

DEMO		=	demo/demo.cpp

DEMO_EXEC	=	FadeyDemo

OBJ			=	$(SRC:.cpp=.o)

HEADER		=	-I ./includes/

LINK		=	-L. -lfadey

RM 			=	rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(HEADER) -c $(SRC) -o $(OBJ)
	ar rcs $(NAME) $(OBJ)

demo: $(NAME) $(DEMO_EXEC)

$(DEMO_EXEC): $(DEMO)
	$(CC) $(FLAGS) $(DEMO) $(HEADER) $(LINK) -o $(DEMO_EXEC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(DEMO_EXEC)

re: fclean all
