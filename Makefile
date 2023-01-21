NAME 		= 	test

SRC 		= 	main.cpp

OBJS 		= 	${SRC:.cpp=.o}

HEADERS		=	map.hpp \
				set.hpp \
				stack.hpp \
				vector.hpp \
				./utils/iterators.hpp \
				./RBTree.hpp \
				./utils/util.hpp

FLAGS		=	-Wall -Wextra -Werror -std=c++98

CPP			=	c++

RM 			= 	rm -f

# The flag TEST is taken from the command line, for example:
# make re TEST="-D STL=TRUE"

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} ${TEST} -I. $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
