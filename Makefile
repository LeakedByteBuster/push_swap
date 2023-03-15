# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:52:24 by mfouadi           #+#    #+#              #
#    Updated: 2023/03/15 05:50:50 by mfouadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# obj folder where .o files will be placed
OBJDIR := obj

# Directory of headers files
INCDIR := include

# Finding all .c files in the source directory and its subdirectories
SRC := mand_src/main.c \
		mand_src/parsing.c \
		mand_src/push_swap.c \
		mand_src/utils/utils.c \

# patsubst ('pattern substitution') takes a pattern, a replacement string and a list of names
# List of object files to be generated
OBJ := $(patsubst %, $(OBJDIR)/%,$(SRC:.c=.o))

# Headers files
HEADERS := include/push_swap.h

#----------------------------------------------------------------------------------------------
# Variables
#----------------------------------------------------------------------------------------------

# Goal of this Makefile
NAME := push_swap

# Flags used in compilation
CFLAGS := -Werror -Wextra -Wall

# Command used to rm files and obj directory
RM := /bin/rm -rf

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

# Ultimate Goal
all : $(NAME)

$(NAME) : libft_ar $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)

$(OBJDIR)/%.o : %.c $(HEADERS)
	 mkdir -p $(dir $@)
	 $(CC) $(CFLAGS) -c $< -I$(INCDIR) -o $@

# Creates static archive 'libft.a'
libft_ar:
	make -C libft

#----------------------------------------------------------------------------------------------
# Deleting object files
#----------------------------------------------------------------------------------------------

# Deletes object files
clean :
	make -C libft clean
	$(RM) $(OBJDIR)

# Deletes libft.a, and executable
fclean : clean
	make -C libft fclean
	$(RM) $(NAME) a.out

# re-compile all .c files
re : fclean all

#----------------------------------------------------------------------------------------------
# Special Built-in Target Names
#----------------------------------------------------------------------------------------------

# Words that do not represent files of the project
.Phony : all clean fclean re

# Prevents output of these targets from being printed
.SILENT : bonus $(NAME) clean fclean re libft_ar

# Makes 'all' the default target
.DEFAULT_GOAL := all
