NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus
SRCC = client.c minitalk_utils.c
SRCS = server.c minitalk_utils.c
SRCC_BONUS = client_bonus.c minitalk_utils.c
SRCS_BONUS = server_bonus.c minitalk_utils.c
OBJC = ${SRCC:%.c=%.o}
OBJS = ${SRCS:%.c=%.o}
OBJC_BONUS = ${SRCC_BONUS:%.c=%.o}
OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INCLUDE = minitalk.h

all:	$(NAMEC) $(NAMES)

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMEC): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAMEC)

$(NAMES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAMES)

$(NAMES_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMES_BONUS)

$(NAMEC_BONUS) : $(OBJC_BONUS)
	$(CC) $(CFLAGS) $(OBJC_BONUS) -o $(NAMEC_BONUS)

 


clean:
	$(RM) $(OBJC)
	$(RM) $(OBJS)
	$(RM) $(OBJC_BONUS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(RM) $(NAMEC_BONUS)
	$(RM) $(NAMES_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus