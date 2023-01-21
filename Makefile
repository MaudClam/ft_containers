NAME 		= 	test

NAMET		=	time_test

NAMEV		=	vector_test

SRC 		= 	main.cpp

SRCT		=	./tests/time_test.cpp

SRCV		=	./tests/vector_test.cpp

OBJS 		= 	${SRC:.cpp=.o}

OBJST 		= 	${SRCT:.cpp=.o}

OBJSV 		= 	${SRCV:.cpp=.o}

HEADERS		=	map.hpp \
				set.hpp \
				stack.hpp \
				vector.hpp \
				./utils/iterators.hpp \
				./utils/RBTree.hpp \
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

${NAMET}:		${OBJST}
				${CPP} ${FLAGS} ${OBJST} -o ${NAMET}

${NAMEV}:		${OBJSV}
				${CPP} ${FLAGS} ${OBJSV} -o ${NAMEV}

all:			${NAME}

time:			${NAMET}

vector:			${NAMEV}

clean:
				${RM} ${OBJS} ${OBJST} ${OBJSV}

fclean:			clean
				${RM} ${NAME} ${NAMET} ${NAMEV}

re:				fclean all

.PHONY:			all clean fclean re time vector
