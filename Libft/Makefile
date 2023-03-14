# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 20:08:38 by mfouadi           #+#    #+#              #
#    Updated: 2023/03/14 07:03:18 by mfouadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------------------------------------------------------------
# Finding .c Files, list of .o Files, 
#----------------------------------------------------------------------------------------------

ROOTDIR := .
OBJDIR := obj
# directory of headers files
INCDIR := include
# Finding all .c files in the source directory and its subdirectories
# $(shell find $(INCDIR) -type f -name '*.c')
SRC := $(shell find $(ROOTDIR) -type f -name '*.c')
# patsubst ('pattern substitution') takes a pattern, a replacement string and a list of names
# List of object files to be generated
OBJ := $(patsubst $(ROOTDIR)/%,$(OBJDIR)/%,$(SRC:.c=.o))
# Headers files
HEADERS := $(shell find $(INCDIR) -type f -name '*.h')

#----------------------------------------------------------------------------------------------
# Variables
#----------------------------------------------------------------------------------------------

# Goal of this Makefile
NAME := libft.a
# Flags used in 
CFLAGS := -Werror -Wextra -Wall
# Command used to rm files and obj directory
RM := /bin/rm -rf
# Used for animation
FILES_COMPILED = 0
TOTAL_FILES = $(shell find $(ROOTDIR) -type f -name "*.c" | wc -l)

#----------------------------------------------------------------------------------------------
# Terminal ANSI colors
#----------------------------------------------------------------------------------------------
HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC ='\033[0m'

#----------------------------------------------------------------------------------------------
# Main dependencies
#----------------------------------------------------------------------------------------------

# Target all depends on static library ($(NAME))
all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

# $(eval ...) is used to dynamically generate makefile rules.
#		 - Output of the command is interpreted as makefile code
#		 - Generated code is added to the Makefile and executed when the makefile run

# $(shell ...) is used to capture the value of the output of shell and stores it 
#			in a make variable
#		- i.e. $(shell TEST = $(echo "hello"))


obj/%.o : %.c $(HEADERS)
# $(eval FILES_COMPILED = $(shell echo "$(FILES_COMPILED) + 1" | bc ))
# @ printf ${HBLK}"  Compiling ▻"${HBLK}" [%-20s] "${HBLK} $(notdir $@)
# @ echo "$(FILES_COMPILED) * 100 / $(TOTAL_FILES)" | bc | tr -d '\n'
# @ printf "%% \r"${NC}
	@ mkdir -p $(dir $@)
	 $(CC) $(CFLAGS)  -c $< -o $@ -I$(INCDIR)

#----------------------------------------------------------------------------------------------
# Deleting object files
#----------------------------------------------------------------------------------------------
clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#----------------------------------------------------------------------------------------------
# Special Built-in Target Names
#----------------------------------------------------------------------------------------------
.Phony : all clean fclean re
.SILENT : bonus $(NAME) clean fclean re
.DEFAULT_GOAL := all
