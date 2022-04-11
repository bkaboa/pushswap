include 	config/srcs.mk

NAME	=	push

IPATH	=	Includes
OPATH	=	.OBJ
MEMFLAGS=	-fsanitize=address -g3
CFLAGS	=	-Wall -Werror -Wextra
IFLAGS	=	-I $(IPATH)
OBJS	=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))

INC		=	$(addprefix $(IPATH)/, pushswap.h)

all:			$(NAME)

$(NAME):		$(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

re:				fclean all

$(OPATH)/%.o:	%.c $(INC) config/srcs.mk Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

memoire:		CFLAGS += $(FFLAGS)
memoire:		re

clean:
	@$(RM) $(OBJS)

fclean:			clean
	@$(RM) $(NAME)
