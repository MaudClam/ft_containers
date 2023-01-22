NAMEJ 		= 	test

NAMET		=	time_test

NAMEV		=	vector_test

NAMES		=	stack_test

NAMEM		=	map_test

NAMESE		=	set_test

SRCJ 		= 	main.cpp

SRCT		=	./tests/time_test.cpp

SRCV		=	./tests/vector_test.cpp

SRCS		=	./tests/stack_test.cpp

SRCM		=	./tests/map_test.cpp

SRCSE		=	./tests/set_test.cpp

OBJSJ 		= 	${SRCJ:.cpp=.o}

OBJST 		= 	${SRCT:.cpp=.o}

OBJSV 		= 	${SRCV:.cpp=.o}

OBJSS 		= 	${SRCS:.cpp=.o}

OBJSM 		= 	${SRCM:.cpp=.o}

OBJSSE 		= 	${SRCSE:.cpp=.o}

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

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} ${TEST} -I. $< -o ${<:.cpp=.o}

# The flag TEST is taken from the command line, for example:
# make re TEST="-D STL=TRUE"
${NAMEJ}:		${OBJSJ}
				${CPP} ${FLAGS} ${OBJSJ} -o ${NAMEJ}

${NAMET}:		${OBJST}
				${CPP} ${FLAGS} ${OBJST} -o ${NAMET}

${NAMEV}:		${OBJSV}
				${CPP} ${FLAGS} ${OBJSV} -o ${NAMEV}

${NAMES}:		${OBJSS}
				${CPP} ${FLAGS} ${OBJSS} -o ${NAMES}

${NAMEM}:		${OBJSM}
				${CPP} ${FLAGS} ${OBJSM} -o ${NAMEM}

${NAMESE}:		${OBJSSE}
				${CPP} ${FLAGS} ${OBJSSE} -o ${NAMESE}

all:			test time vector stack map set

test:			${NAMEJ}

time:			${NAMET}

vector:			${NAMEV}

stack:			${NAMES}

map:			${NAMEM}

set:			${NAMESE}

clean:
				${RM} ${OBJSJ} ${OBJST} ${OBJSV} ${OBJSS} ${OBJSM} ${OBJSSE}

fclean:			clean
				${RM} ${NAMEJ} ${NAMET} ${NAMEV} ${NAMES} ${NAMEM} ${NAMESE}

re:				fclean all

.PHONY:			all clean fclean re test time vector stack map set
