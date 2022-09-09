NAME = libftprintf.a

HEADER_DIR = ./header

INCLUDES = -I${HEADER_DIR}

SOURCE_DIR = ./srcs 

UTILS_DIR = ./utils

SOURCES = $(SOURCE_DIR)/ft_printf.c

UTILS += $(UTILS_DIR)/ft_putchar.c
UTILS += $(UTILS_DIR)/ft_putstr.c
UTILS += $(UTILS_DIR)/ft_putnbr.c

RM = @rm -f

ARCHIVE = @ar -rc

CC = @clang

CFLAGS = -Wall -Wextra -Werror

OBJECTS = ${SOURCES:.c=.o} ${UTILS:.c=.o}

# Mandatory
all: ${NAME}

# Mandatory
$(NAME): ${OBJECTS} 
	${ARCHIVE} ${NAME} ${OBJECTS}
	
.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

# Mandatory
clean:
	make clean
	${RM}	${OBJECTS}
	

# Mandatory
fclean: clean
	make fclean
	${RM} ${NAME}

# Mandatory
# Regenarate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re