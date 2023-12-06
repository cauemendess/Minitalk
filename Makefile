CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SERVER = server
CLIENT = client
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c


SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRC_SERVER_BONUS = src_bonus/server_bonus.c
SRC_CLIENT_BONUS = src_bonus/client_bonus.c




all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft --no-print-directory

$(SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) -Llibft -lft -o $(SERVER)

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -Llibft -lft -o $(CLIENT)


bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SRC_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) -Llibft -lft -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) -Llibft -lft -o $(CLIENT_BONUS)


clean:
	@make -C libft clean --no-print-directory

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@rm -f $(SERVER_BONUS)
	@rm -f $(CLIENT_BONUS)


re: fclean all

.PHONY: all clean fclean re