NAME =        ft-containers
NAME_STD =    std-containers

CXX =        clang++
CXXFLAGS =    -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRC_DIR = ./tests

SRC_FILES =		${SRC_DIR}/main.cpp \
				${SRC_DIR}/containers.cpp \
				${SRC_DIR}/iterators.cpp \
            	${SRC_DIR}/containers/vector/constructors/vector_constructors.cpp \
            	${SRC_DIR}/containers/vector/iterators/vector_iterators.cpp \
            	${SRC_DIR}/containers/vector/capacity/vector_capacity.cpp \
            	${SRC_DIR}/containers/vector/element_access/vector_element_access.cpp \
            	${SRC_DIR}/containers/vector/modifiers/vector_modifiers.cpp \
            	${SRC_DIR}/containers/vector/allocator/vector_allocators.cpp \
				${SRC_DIR}/containers/vector/relational_operators/relationalOperators.cpp \
				${SRC_DIR}/containers/map/constructors/map_constructors.cpp \
				${SRC_DIR}/containers/map/iterators/map_iterators.cpp \
				${SRC_DIR}/containers/map/capacity/map_capacity.cpp \
				${SRC_DIR}/containers/map/element_access/operator[].cpp \
				${SRC_DIR}/containers/map/modifiers/map_modifiers.cpp \
				${SRC_DIR}/containers/map/observers/map_observers.cpp \
				${SRC_DIR}/containers/map/operations/map_operations.cpp \
				${SRC_DIR}/containers/map/allocator/map_allocators.cpp \
				${SRC_DIR}/containers/map/relational_operators/relationalOperators.cpp \
				${SRC_DIR}/containers/stack/stack_tests.cpp \
				${SRC_DIR}/iterators/random_access/constructors/ra_constructors.cpp \
				${SRC_DIR}/iterators/random_access/element_access/ra_element_access.cpp \
				${SRC_DIR}/iterators/random_access/arithmetic_operators/ra_arithmetic.cpp \
				${SRC_DIR}/iterators/random_access/relational_operators/relationalOperators.cpp \
				${SRC_DIR}/iterators/random_access_reverse/constructors/rar_constructors.cpp \
				${SRC_DIR}/iterators/random_access_reverse/element_access/rar_element_access.cpp \
				${SRC_DIR}/iterators/random_access_reverse/arithmetic_operators/rar_arithmetic.cpp \
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
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of $(NAME_STD)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME)\n"
	@$(RM) $(NAME_STD)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME_STD)\n"

re: fclean all