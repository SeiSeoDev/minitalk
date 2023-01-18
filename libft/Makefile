
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC/I = ft_isalnum.c    	\
        ft_isalpha.c    	\
        ft_isdigit.c		\
		ft_isascii.c		\
		ft_isprint.c
SRC/S = ft_strlen.c			\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strnstr.c		\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strtrim.c		\
		ft_strjoin.c
SRC/O = ft_tolower.c		\
		ft_toupper.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_split.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putstr.c			\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_itoa.c			\
		ft_strmapi.c
SRC/M = ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memmove.c
SRC/B = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstclear.c		\
		ft_lstmap.c

INC = libft.h
AR = ar -rc
SRC = $(SRC/I) $(SRC/S) $(SRC/O) $(SRC/M)
OBJ = $(SRC:.c=.o)
NAME = libft.a
OBJ_B = $(SRC/B:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean :
	rm -rf $(OBJ) $(OBJ_B)
fclean : clean
	rm -rf $(NAME)
re : fclean all

bonus : $(OBJ) $(OBJ_B)
		$(AR) $(NAME) $(OBJ_B) $(OBJ)
