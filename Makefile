##
## Makefile for raytracer1 in /home/rotaru_i/Coding/Liblap/gfx_raytracer1
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Sat Feb 13 17:49:21 2016 Iulian Rotaru
## Last update Sat Feb 13 17:49:59 2016 Iulian Rotaru
##

all:
	make -C ./src

clean:
	make -C ./src clean

fclean:
	make -C ./src fclean

re:
	make -C ./src re

.PHONY: all clean fclean re
