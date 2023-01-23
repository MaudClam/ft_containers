NAME		=	time vector stack map set

NAMET		=	time_test

NAMEV		=	vector_test

NAMES		=	stack_test

NAMEM		=	map_test

NAMESE		=	set_test

SRCT		=	./tests/time_test.cpp

SRCV		=	./tests/vector_test.cpp

SRCS		=	./tests/stack_test.cpp

SRCM		=	./tests/map_test.cpp

SRCSE		=	./tests/set_test.cpp

#OBJJ 		= 	${SRCJ:.cpp=.o}

OBJT 		= 	${SRCT:.cpp=.o}

OBJV 		= 	${SRCV:.cpp=.o}

OBJS 		= 	${SRCS:.cpp=.o}

OBJM 		= 	${SRCM:.cpp=.o}

OBJSE 		= 	${SRCSE:.cpp=.o}

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
				${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}

${NAMET}:		${OBJT}
				${CPP} ${FLAGS} ${OBJT} -o ${NAMET}

${NAMEV}:		${OBJV}
				${CPP} ${FLAGS} ${OBJV} -o ${NAMEV}

${NAMES}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAMES}

${NAMEM}:		${OBJM}
				${CPP} ${FLAGS} ${OBJM} -o ${NAMEM}

${NAMESE}:		${OBJSE}
				${CPP} ${FLAGS} ${OBJSE} -o ${NAMESE}

all:			${NAME}

test:			${NAMEJ}

time:			${NAMET}

vector:			${NAMEV}

stack:			${NAMES}

map:			${NAMEM}

set:			${NAMESE}

clean:
				${RM} ${OBJT} ${OBJV} ${OBJS} ${OBJM} ${OBJSE}

fclean:			clean
				${RM} ${NAMET} ${NAMEV} ${NAMES} ${NAMEM} ${NAMESE}

re:				fclean all

.PHONY:			all clean fclean re time vector stack map set
