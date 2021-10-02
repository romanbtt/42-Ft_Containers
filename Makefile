NAME =        ft-containers
NAME_STD =    std-containers

CXX =        clang++
CXXFLAGS =    -Wall -Wextra -Werror -std=c++98  -g #-g to delete

SRC_DIR = ./tests

SRC_FILES =		${SRC_DIR}/main.cpp \
				${SRC_DIR}/containers.cpp \
				${SRC_DIR}/iterators.cpp \
            	${SRC_DIR}/containers/vector/constructors/defaultConstructor.cpp \
            	${SRC_DIR}/containers/vector/constructors/fillConstructor.cpp \
            	${SRC_DIR}/containers/vector/constructors/rangeConstructor.cpp \
            	${SRC_DIR}/containers/vector/constructors/copyConstructor.cpp \
            	${SRC_DIR}/containers/vector/constructors/operatorEqual.cpp \
            	${SRC_DIR}/containers/vector/iterators/begin.cpp \
            	${SRC_DIR}/containers/vector/iterators/end.cpp \
            	${SRC_DIR}/containers/vector/iterators/rbegin.cpp \
            	${SRC_DIR}/containers/vector/iterators/rend.cpp \
            	${SRC_DIR}/containers/vector/capacity/size.cpp \
            	${SRC_DIR}/containers/vector/capacity/maxSize.cpp \
            	${SRC_DIR}/containers/vector/capacity/resize.cpp \
            	${SRC_DIR}/containers/vector/capacity/capacity.cpp \
            	${SRC_DIR}/containers/vector/capacity/empty.cpp \
            	${SRC_DIR}/containers/vector/capacity/reserve.cpp \
            	${SRC_DIR}/containers/vector/element_access/operator[].cpp \
            	${SRC_DIR}/containers/vector/element_access/at.cpp \
            	${SRC_DIR}/containers/vector/element_access/front.cpp \
            	${SRC_DIR}/containers/vector/element_access/back.cpp \
            	${SRC_DIR}/containers/vector/modifiers/assign.cpp \
            	${SRC_DIR}/containers/vector/modifiers/pushBack.cpp \
            	${SRC_DIR}/containers/vector/modifiers/popBack.cpp \
            	${SRC_DIR}/containers/vector/modifiers/insert.cpp \
            	${SRC_DIR}/containers/vector/modifiers/erase.cpp \
            	${SRC_DIR}/containers/vector/modifiers/swap.cpp \
            	${SRC_DIR}/containers/vector/modifiers/clear.cpp \
            	${SRC_DIR}/containers/vector/allocator/getAllocator.cpp \
				${SRC_DIR}/containers/vector/relational_operators/relationalOperators.cpp \
				${SRC_DIR}/iterators/random_access/constructors/defaultConstructor.cpp \
				${SRC_DIR}/iterators/random_access/constructors/copyConstructor.cpp \
				${SRC_DIR}/iterators/random_access/constructors/operatorEqual.cpp \
				${SRC_DIR}/iterators/random_access/element_access/operatorBracket.cpp \
				${SRC_DIR}/iterators/random_access/element_access/operatorStar.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/compound.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/decrement.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/increment.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/minus.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/plus.cpp \
				${SRC_DIR}/iterators/random_access/relational_operators/relationalOperators.cpp \
				${SRC_DIR}/iterators/random_access_reverse/constructors/defaultConstructor.cpp \
				${SRC_DIR}/iterators/random_access_reverse/constructors/copyConstructor.cpp \
				${SRC_DIR}/iterators/random_access_reverse/constructors/operatorEqual.cpp \
				${SRC_DIR}/iterators/random_access_reverse/element_access/operatorBracket.cpp \
				${SRC_DIR}/iterators/random_access_reverse/element_access/operatorStar.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/compound.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/decrement.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/increment.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/minus.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/plus.cpp \
				${SRC_DIR}/iterators/random_access_reverse/relational_operators/relationalOperators.cpp




SRCS = $(SRC_FILES)
OBJ_DIR = ./build
OBJ_DIR_FT = ${OBJ_DIR}/ft_containers
OBJ_DIR_STD = ${OBJ_DIR}/std_containers

OBJS_FT = $(patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR_FT}/%.o, ${SRCS})
OBJS_STD = $(patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR_STD}/%.o, ${SRCS})

all: $(NAME) $(NAME_STD)

$(NAME): $(OBJS_FT)
	@$(CXX) $(OBJS_FT) $(CXXFLAGS) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m $@\n"

$(NAME_STD): $(OBJS_STD)
	@$(CXX) $(OBJS_STD) $(CXXFLAGS) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m $@\n"

${OBJ_DIR_FT}/%.o: ${SRC_DIR}/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) --define-macro ISFT --undefine-macro ISSTD -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

${OBJ_DIR_STD}/%.o: ${SRC_DIR}/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) --undefine-macro ISFT --define-macro ISSTD -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
	@$(RM) -rf ${OBJ_DIR}
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of $(NAME)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME)\n"

re: fclean all