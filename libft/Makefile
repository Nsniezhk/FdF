NAME	=	libft.a

CC	= gcc

CFLAGS	=	-Wall	-Wextra	-Werror
HEADERS	+=	../libft
CFLAGS += $(foreach Libft_funcs, ../libft, -I$(Libft_funcs))
CFLAGS += $(foreach ft_printf, ./ft_printf/header, -I$(ft_printf))
LIBFT	=	/libft

FT_PRINTF	=	ft_printf/ft_printf.c \
			ft_printf/arg_processing.c \
			ft_printf/specifier_processing.c \
			ft_printf/extenctions/num_precision_len.c \
			ft_printf/extenctions/numstr_len.c \
			ft_printf/extenctions/print_space_or_zero.c \
			ft_printf/extenctions/sign_force_processing.c \
			ft_printf/extenctions/length_cast_processing.c \
			ft_printf/extenctions/print_num_base.c \
			ft_printf/the_handler/percent_handler.c \
			ft_printf/the_handler/char_handler.c \
			ft_printf/the_handler/hex_handler.c \
			ft_printf/the_handler/int_handler.c \
			ft_printf/the_handler/octal_handler.c \
			ft_printf/the_handler/ptr_handler.c \
			ft_printf/the_handler/str_handler.c \
			ft_printf/the_handler/uint_handler.c \
			ft_printf/the_handler/unsigned_handler.c \
			ft_printf/the_handler/wchar_handler.c \
			ft_printf/the_handler/wstr_handler.c\
			ft_printf/the_handler/null_handler.c 

LIBFT_FUNCS = Libft_funcs/ft_memset.c Libft_funcs/ft_bzero.c Libft_funcs/ft_memcpy.c \
	   Libft_funcs/ft_memccpy.c Libft_funcs/ft_memmove.c Libft_funcs/ft_memchr.c Libft_funcs/ft_memcmp.c \
	   Libft_funcs/ft_strlen.c Libft_funcs/ft_strnlen.c	Libft_funcs/ft_strdup.c \
	   Libft_funcs/ft_strcpy.c Libft_funcs/ft_strncpy.c Libft_funcs/ft_strcat.c \
	   Libft_funcs/ft_strncat.c Libft_funcs/ft_strlcat.c Libft_funcs/ft_strchr.c \
	   Libft_funcs/ft_strrchr.c Libft_funcs/ft_strstr.c Libft_funcs/ft_strnstr.c \
	   Libft_funcs/ft_strcmp.c Libft_funcs/ft_strncmp.c Libft_funcs/ft_sqrt.c	\
	   Libft_funcs/ft_atoi.c Libft_funcs/ft_isalpha.c Libft_funcs/ft_isdigit.c \
	   Libft_funcs/ft_isalnum.c Libft_funcs/ft_isascii.c Libft_funcs/ft_isprint.c \
	   Libft_funcs/ft_toupper.c Libft_funcs/ft_tolower.c Libft_funcs/ft_memalloc.c \
	   Libft_funcs/ft_memdel.c Libft_funcs/ft_strnew.c Libft_funcs/ft_strdel.c \
	   Libft_funcs/ft_strclr.c Libft_funcs/ft_striter.c Libft_funcs/ft_striteri.c \
	   Libft_funcs/ft_strmap.c Libft_funcs/ft_strmapi.c Libft_funcs/ft_strequ.c \
	   Libft_funcs/ft_strnequ.c Libft_funcs/ft_strsub.c Libft_funcs/ft_strjoin.c \
	   Libft_funcs/ft_strtrim.c Libft_funcs/ft_strsplit.c Libft_funcs/ft_itoa.c \
	   Libft_funcs/ft_itoa_base.c Libft_funcs/ft_putchar.c Libft_funcs/ft_putwchar.c	\
	   Libft_funcs/ft_putstr.c Libft_funcs/ft_putnstr.c	Libft_funcs/ft_putendl.c \
	   Libft_funcs/ft_putnbr.c Libft_funcs/ft_putchar_fd.c Libft_funcs/ft_putstr_fd.c \
	   Libft_funcs/ft_putendl_fd.c Libft_funcs/ft_putnbr_fd.c Libft_funcs/ft_lstnew.c \
	   Libft_funcs/ft_lstdelone.c Libft_funcs/ft_lstdel.c Libft_funcs/ft_lstadd.c \
	   Libft_funcs/ft_lstiter.c	Libft_funcs/ft_lstmap.c	Libft_funcs/ft_numlen.c	\
	   Libft_funcs/ft_lstcount.c Libft_funcs/ft_lstrev.c Libft_funcs/ft_strndup.c	\
	   Libft_funcs/ft_strrev.c Libft_funcs/ft_strclen.c Libft_funcs/get_next_line.c \
	   Libft_funcs/ft_wordcount.c Libft_funcs/ft_splitdel.c Libft_funcs/ft_abs.c

OBJS = $(patsubst ft_printf/%.c,obj/ft_printf/%.o,$(FT_PRINTF))
OBJS += $(patsubst Libft_funcs/%.c, obj/Libft_obj/%.o,$(LIBFT_FUNCS))

all:	$(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/ft_printf
	@mkdir -p $@/ft_printf/the_handler
	@mkdir -p $@/ft_printf/extenctions
	@mkdir -p $@/Libft_obj
obj/ft_printf/%.o: ft_printf/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
obj/Libft_obj/%.o: Libft_funcs/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
	rm -rf obj
	
re: fclean all
