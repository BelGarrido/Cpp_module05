CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureau

SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp

# Directorio donde irán los .o
OBJ_DIR = obj

# Transformamos los .cpp en obj/*.o
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Regla para crear el directorio si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla de compilación hacia obj/
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re