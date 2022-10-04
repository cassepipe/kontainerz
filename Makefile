##################
##  VARIABLES   ##
##################
MAKEFLAGS		+= --no-builtin-rules

DIFF			= meld
DIFF			= diff -s

CXX				= clang++-14 -gdwarf-4
CXX				= g++-12
CXX				= c++

SHELL			= zsh
SHELL			= bash

FT				= ft_containers_test
STD				= std_containers_test

SOURCES			= $(wildcard *.cpp)
OBJ/FT_OBJECTS	= $(patsubst %.cpp,  obj/ft_%.o, $(SOURCES))
OBJ/STD_OBJECTS	= $(patsubst %.cpp, obj/std_%.o, $(SOURCES))
OBJ/FT_DEPS		= $(patsubst %.o,           %.d, $(OBJ/FT_OBJECTS))
OBJ/STD_DEPS	= $(patsubst %.o,           %.d, $(OBJ/STD_OBJECTS))

#DEBUG			= -DDEBUG

## FLAGS
INCLUDE_FLAGS	= -I.
CPPFLAGS		= ${INCLUDE_FLAGS} -MMD

## Add -Werror before correction
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3 -pedantic-errors
LDFLAGS			=
LDLIBS			=

#Our beloved address sanitizer
#ASAN_FLAG		=  -fsanitize=address
CXXFLAGS		+=	$(ASAN_FLAG)
LDFLAGS			+=	$(ASAN_FLAG)

##############
##  RULES   ##
##############

all:			$(FT) $(STD) diff

# Reminder : LDFLAGS (-L) always come before oject files !
$(FT):			$(OBJ/FT_OBJECTS)
				@echo "Linking..."
				${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

# Reminder : LDFLAGS (-L) always come before oject files !
$(STD):			${OBJ/STD_OBJECTS}
				@echo "Linking..."
				${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

obj/ft_%.o:		%.cpp Makefile | obj
				${CXX} -DNAMESPACE=ft ${DEBUG} ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@

obj/std_%.o:	%.cpp Makefile | obj
				${CXX} -DNAMESPACE=std ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@
obj:
				mkdir obj
clean:
				rm -rf obj
				rm -rf tree*.dot

fclean:			clean
				rm -rf $(FT)
				rm -rf $(STD)

re:				fclean all

diff:
				@#$(DIFF) =( ./${FT} )  =( ./${STD}  )
				$(DIFF) <( ./${FT} )  <( ./${STD}  )

-include $(OBJ/FT_DEPS)
-include $(OBJ/STD_DEPS)

.PHONY:			all clean fclean re diff

