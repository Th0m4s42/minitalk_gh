NAME = minitalk
MANDATORY_SERVER_NAME = server
MANDATORY_CLIENT_NAME = client
BONUS_SERVER_NAME = bonus_server
BONUS_CLIENT_NAME = bonus_client

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

LIBFT_FLAGS = -Llibft -l:libft.a

MANDATORY_SRCS_DIR = mandatory_srcs/
MANDATORY_SRCS_SERVER_DIR = $(MANDATORY_SRCS_DIR)server_srcs/
MANDATORY_SRCS_CLIENT_DIR = $(MANDATORY_SRCS_DIR)client_srcs/

BONUS_SRCS_DIR = bonus_srcs/
BONUS_SRCS_SERVER_DIR = $(BONUS_SRCS_DIR)server_srcs/
BONUS_SRCS_CLIENT_DIR = $(BONUS_SRCS_DIR)client_srcs/

OBJS_DIR = objs/

MANDATORY_OBJS_DIR = $(OBJS_DIR)mandatory/
MANDATORY_OBJS_SERVER_DIR = $(MANDATORY_OBJS_DIR)server/
MANDATORY_OBJS_CLIENT_DIR = $(MANDATORY_OBJS_DIR)client/

BONUS_OBJS_DIR = $(OBJS_DIR)bonus/
BONUS_OBJS_SERVER_DIR = $(BONUS_OBJS_DIR)server/
BONUS_OBJS_CLIENT_DIR = $(BONUS_OBJS_DIR)client/

MANDATORY_HEADER = minitalk.h
BONUS_HEADER = minitalk_bonus.h

MANDATORY_SRCS_SERVER = $(MANDATORY_SRCS_SERVER_DIR)main.c \

MANDATORY_SRCS_CLIENT = $(MANDATORY_SRCS_CLIENT_DIR)main.c \


BONUS_SRCS_SERVER = $(BONUS_SRCS_SERVER_DIR)main.c \

BONUS_SRCS_CLIENT = $(BONUS_SRCS_CLIENT_DIR)main.c \

MANDATORY_OBJS_SERVER = $(patsubst $(MANDATORY_SRCS_SERVER_DIR)%.c,$(MANDATORY_OBJS_SERVER_DIR)%.o,$(MANDATORY_SRCS_SERVER))
MANDATORY_OBJS_CLIENT = $(patsubst $(MANDATORY_SRCS_CLIENT_DIR)%.c,$(MANDATORY_OBJS_CLIENT_DIR)%.o,$(MANDATORY_SRCS_CLIENT))

BONUS_OBJS_SERVER = $(patsubst $(BONUS_SRCS_SERVER_DIR)%.c,$(BONUS_OBJS_SERVER_DIR)%.o,$(BONUS_SRCS_SERVER))
BONUS_OBJS_CLIENT = $(patsubst $(BONUS_SRCS_CLIENT_DIR)%.c,$(BONUS_OBJS_CLIENT_DIR)%.o,$(BONUS_SRCS_CLIENT))

$(NAME) : $(MANDATORY_SERVER_NAME) $(MANDATORY_CLIENT_NAME)

$(MANDATORY_SERVER_NAME) : $(MANDATORY_OBJS_SERVER) $(MANDATORY_HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $(MANDATORY_SERVER_NAME) $(MANDATORY_OBJS_SERVER) $(LIBFT_FLAGS)

$(MANDATORY_CLIENT_NAME) : $(MANDATORY_OBJS_CLIENT) $(MANDATORY_HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $(MANDATORY_CLIENT_NAME) $(MANDATORY_OBJS_CLIENT) $(LIBFT_FLAGS)


bonus : $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)

$(BONUS_SERVER_NAME) : $(BONUS_OBJS_SERVER) $(BONUS_HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $(BONUS_SERVER_NAME) $(BONUS_OBJS_SERVER) $(LIBFT_FLAGS)

$(BONUS_CLIENT_NAME) : $(BONUS_OBJS_CLIENT) $(BONUS_HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $(BONUS_CLIENT_NAME) $(BONUS_OBJS_CLIENT) $(LIBFT_FLAGS)


$(MANDATORY_OBJS_SERVER_DIR)%.o : $(MANDATORY_SRCS_SERVER_DIR)%.c $(MANDATORY_HEADER) | $(MANDATORY_OBJS_SERVER_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(MANDATORY_OBJS_SERVER_DIR) : | $(MANDATORY_OBJS_DIR)
	mkdir -p $(MANDATORY_OBJS_SERVER_DIR)


$(BONUS_OBJS_SERVER_DIR)%.o : $(BONUS_SRCS_SERVER_DIR)%.c $(BONUS_HEADER) | $(BONUS_OBJS_SERVER_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(BONUS_OBJS_SERVER_DIR) : | $(BONUS_OBJS_DIR)
	mkdir -p $(BONUS_OBJS_SERVER_DIR)


$(MANDATORY_OBJS_CLIENT_DIR)%.o : $(MANDATORY_SRCS_CLIENT_DIR)%.c $(MANDATORY_HEADER) | $(MANDATORY_OBJS_CLIENT_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(MANDATORY_OBJS_CLIENT_DIR) : | $(MANDATORY_OBJS_DIR)
	mkdir -p $(MANDATORY_OBJS_CLIENT_DIR)


$(BONUS_OBJS_CLIENT_DIR)%.o : $(BONUS_SRCS_CLIENT_DIR)%.c $(BONUS_HEADER) | $(BONUS_OBJS_CLIENT_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(BONUS_OBJS_CLIENT_DIR) : | $(BONUS_OBJS_DIR)
	mkdir -p $(BONUS_OBJS_CLIENT_DIR)


$(MANDATORY_OBJS_DIR) : 
	mkdir -p $(MANDATORY_OBJS_DIR)
	mkdir -p $(MANDATORY_OBJS_SERVER_DIR)
	mkdir -p $(MANDATORY_OBJS_CLIENT_DIR)

$(BONUS_OBJS_DIR) : 
	mkdir -p $(BONUS_OBJS_DIR)
	mkdir -p $(BONUS_OBJS_SERVER_DIR)
	mkdir -p $(BONUS_OBJS_CLIENT_DIR)

all : $(NAME) bonus

clean :
	make -C libft/ clean
	rm -rf $(OBJS_DIR)

fclean : clean
	make -C libft/ fclean
	rm -f $(MANDATORY_SERVER_NAME)
	rm -f $(MANDATORY_CLIENT_NAME)
	rm -f $(BONUS_SERVER_NAME)
	rm -f $(BONUS_CLIENT_NAME)
	rm -rf $(OBJS_DIR)

re : fclean all

.PHONY: all clean fclean re