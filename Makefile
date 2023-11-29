CFLAGS = -Wall -Wextra 
LIBFT = libft/libft.a
SERVER = server
CLIENT = client
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c


.PHONY: all clean fclean re

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft --no-print-directory

$(SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) -Llibft -lft -o $(SERVER)

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -Llibft -lft -o $(CLIENT)

clean:
	@make -C libft clean --no-print-directory

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f $(SERVER)
	@rm -f $(CLIENT)

re: fclean all