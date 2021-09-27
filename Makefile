
NAME_FT =		ft-containers
NAME_STD =		std-containers

CXX =		clang++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98  -g #-g to delete

SRC_FILES_FT =	ft_containers/main.cpp \
				ft_containers/tests/containers/vector/constructors/defaultConstructor.cpp \
				ft_containers/tests/containers/vector/constructors/fillConstructor.cpp \
				ft_containers/tests/containers/vector/constructors/rangeConstructor.cpp \
				ft_containers/tests/containers/vector/constructors/copyConstructor.cpp \
				ft_containers/tests/containers/vector/constructors/operatorEqual.cpp \
				ft_containers/tests/containers/vector/iterators/begin.cpp \
				ft_containers/tests/containers/vector/iterators/end.cpp \
				ft_containers/tests/containers/vector/iterators/rbegin.cpp \
				ft_containers/tests/containers/vector/iterators/rend.cpp \
				ft_containers/tests/containers/vector/capacity/size.cpp \
				ft_containers/tests/containers/vector/capacity/maxSize.cpp \
				ft_containers/tests/containers/vector/capacity/resize.cpp \
				ft_containers/tests/containers/vector/capacity/capacity.cpp \
				ft_containers/tests/containers/vector/capacity/empty.cpp \
				ft_containers/tests/containers/vector/capacity/reserve.cpp \
				ft_containers/tests/containers/vector/element_access/operator[].cpp \
				ft_containers/tests/containers/vector/element_access/at.cpp \
				ft_containers/tests/containers/vector/element_access/front.cpp \
				ft_containers/tests/containers/vector/element_access/back.cpp \
				ft_containers/tests/containers/vector/modifiers/assign.cpp \
				ft_containers/tests/containers/vector/modifiers/pushBack.cpp \
				ft_containers/tests/containers/vector/modifiers/popBack.cpp \
				ft_containers/tests/containers/vector/modifiers/insert.cpp \
				ft_containers/tests/containers/vector/modifiers/erase.cpp \
				ft_containers/tests/containers/vector/modifiers/swap.cpp \
				ft_containers/tests/containers/vector/modifiers/clear.cpp \
				ft_containers/tests/containers/vector/allocator/getAllocator.cpp


SRC_FILES_STD =	std_containers/main.cpp \
				std_containers/tests/containers/vector/constructors/defaultConstructor.cpp \
				std_containers/tests/containers/vector/constructors/fillConstructor.cpp \
				std_containers/tests/containers/vector/constructors/rangeConstructor.cpp \
				std_containers/tests/containers/vector/constructors/copyConstructor.cpp \
				std_containers/tests/containers/vector/constructors/operatorEqual.cpp \
				std_containers/tests/containers/vector/iterators/begin.cpp \
				std_containers/tests/containers/vector/iterators/end.cpp \
				std_containers/tests/containers/vector/iterators/rbegin.cpp \
				std_containers/tests/containers/vector/iterators/rend.cpp \
				std_containers/tests/containers/vector/capacity/size.cpp \
				std_containers/tests/containers/vector/capacity/maxSize.cpp \
				std_containers/tests/containers/vector/capacity/resize.cpp \
				std_containers/tests/containers/vector/capacity/capacity.cpp \
				std_containers/tests/containers/vector/capacity/empty.cpp \
				std_containers/tests/containers/vector/capacity/reserve.cpp \
				std_containers/tests/containers/vector/element_access/operator[].cpp \
				std_containers/tests/containers/vector/element_access/at.cpp \
				std_containers/tests/containers/vector/element_access/front.cpp \
				std_containers/tests/containers/vector/element_access/back.cpp \
				std_containers/tests/containers/vector/modifiers/assign.cpp \
				std_containers/tests/containers/vector/modifiers/pushBack.cpp \
				std_containers/tests/containers/vector/modifiers/popBack.cpp \
				std_containers/tests/containers/vector/modifiers/insert.cpp \
				std_containers/tests/containers/vector/modifiers/erase.cpp \
				std_containers/tests/containers/vector/modifiers/swap.cpp \
				std_containers/tests/containers/vector/modifiers/clear.cpp \
				std_containers/tests/containers/vector/allocator/getAllocator.cpp
				

				
SRCS_FT = $(SRC_FILES_FT)
OBJS_FT = $(SRCS_FT:.cpp=.o)

SRCS_STD = $(SRC_FILES_STD)
OBJS_STD = $(SRCS_STD:.cpp=.o)

all: $(NAME_FT) $(NAME_STD)

$(NAME_FT): $(OBJS_FT)
	@$(CXX) $(OBJS_FT) $(CXXFLAGS) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m $@\n"

$(NAME_STD): $(OBJS_STD)
	@$(CXX) $(OBJS_STD) $(CXXFLAGS) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m $@"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
	@$(RM) $(OBJS_FT) $(OBJS_STD)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of $(NAME_FT)\n"
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of $(NAME_STD)\n"

fclean: clean
	@$(RM) $(NAME_FT) $(NAME_STD)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME_FT)\n"
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME_STD)\n"

re: fclean all