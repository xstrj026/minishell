NAME = minishell

LIBFT = ./libft/libft.a
# Compiler and Norminette
CC = gcc
NORM = norminette

# Compiler Flags and Cleaning Command
CFLAGS = -g -Wall -Wextra -Werror -Iinclude
LDFLAGS = -lreadline ./libft/libft.a
RM = rm -rf

# Directories
OBJS_DIR = objs
SRC_DIRS = srcs srcs/utils


# Source and Object Files
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all : $(OBJS_DIR) $(NAME)

# Compile and Link the Project
$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS)  $^ -o $@ $(LDFLAGS)
	@echo "Compilation successful."

# Compile Source Files into Object Files
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the Object File Directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)/$(SRC_DIRS)

# Clean Objects and Executable
clean :
	$(RM) $(OBJS_DIR)
	@echo "Object files and directory cleaned."

fclean : clean
	$(RM) $(NAME)
	@echo "Executable removed."

norm :
	@$(NORM) $(SRCS)

$(LIBFT):
	@echo -e "\nMake libft library file: $(LIBFT).."
	@make -C ./libft
	@echo -e "\n$(LIBFT) created!\n"



# Define symbolic constants for color codes
BOLD_CYAN=\033[1;36m
RESET_COLOR=\033[0m

help:
	@echo "Targets available:"
	@echo "  $(BOLD_CYAN)all$(RESET_COLOR)       : Compile the program"
	@echo "  $(BOLD_CYAN)clean$(RESET_COLOR)     : Remove object files"
	@echo "  $(BOLD_CYAN)fclean$(RESET_COLOR)    : Remove object files and the executable"
	@echo "  $(BOLD_CYAN)norm$(RESET_COLOR)      : Check the code with norminette"
	@echo "  $(BOLD_CYAN)leaks$(RESET_COLOR)     : Check the program for memory leaks"
	@echo "  $(BOLD_CYAN)valgrind_race$(RESET_COLOR)     : Check the program for race conditions in linux"
	@echo "  $(BOLD_CYAN)valgrind_leaks$(RESET_COLOR)     : Check the program for leaks  in linux"
	@echo ""
	@echo "Variables you can set:"
	@echo "  $(BOLD_CYAN)DEBUG_MODE$(RESET_COLOR) : Set to 1 to enable debugging mode (emoji + fsanitize=thread), just make fclean; make DEBUG_MODE=1"
	@echo "  $(BOLD_CYAN)PHILO_MAX$(RESET_COLOR)  : Set maximum number of philosophers (default is 200), just make fclean; make PHILO_MAX=your_value"
	@echo ""
	@echo "Example usage:"



.PHONY : clean fclean re all bonus LIBFT