##
## Makefile for raytracer1 in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Sat Feb 13 17:46:17 2016 Iulian Rotaru
## Last update Sun Mar 13 22:15:17 2016 Iulian Rotaru
##

CFLAGS	+= -I../inc            			\
	   -I/home/${USER}/.froot/include 	\
	   -L/home/${USER}/.froot/lib     	\
	   -llapin -lsfml-audio -lsfml-graphics	\
	   -lsfml-window -lsfml-system -lstdc++	\
	   -ldl -lm 				\
	   -Wall -Wextra -Werror

LAPIN	= -I../inc                        	\
	  -I/home/${USER}/.froot/include 	\
	  -L/home/${USER}/.froot/lib     	\
	  -llapin -lsfml-audio -lsfml-graphics	\
	  -lsfml-window -lsfml-system -lstdc++	\
	  -ldl -lm 				\
	  -Wall -Wextra -Werror

CC	= gcc

RM	= rm -rf

NAME	= raytracer1

SRCS	= main.c 		\
	  loop.c		\
	  d_calc.c		\
	  my_getnbr.c		\
	  normifier.c		\
	  light_calc.c		\
	  my_put_nbr.c		\
	  load_plans.c		\
	  color_mixer.c		\
	  useless_fct.c		\
	  check_inter.c		\
	  load_sphere.c		\
	  move_eye_hori.c	\
	  load_eyes_next.c	\
	  find_inter_obst.c	\
	  ../tcore/tekray.c	\
	  ../tcore/tekpixel.c	\
	  check_inter_plan_big.c\
	  properly_loaded_five.c

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LAPIN)
	cp $(NAME) ..

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
