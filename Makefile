##
## PROJECT, 2024
## Assignement1
## File description:
## Makefile
##

CC	=	g++

SRC_CORE	=	main.cpp	\
				src/Dungeon.cpp	\
				src/AItems.cpp	\
				src/ACharacter.cpp	\
				src/characters/Knight.cpp	\
				src/characters/Dragon.cpp	\
				src/characters/Troll.cpp	\
				src/characters/Goblin.cpp	\
				src/potions/HpPotion.cpp	\
				src/potions/ManaPotion.cpp	\
				src/potions/DefensePotion.cpp	\
				src/potions/StrengthPotion.cpp	\
				src/potions/Potion.cpp	\
				src/weapons/Axe.cpp	\
				src/weapons/Sword.cpp	\
				src/weapons/Weapon.cpp	\
				src/InputManager.cpp	\
				src/items/Map.cpp	\
				src/Room.cpp	\
				src/Chest.cpp	\
				src/GameMap.cpp	\

OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3 -g

CPPFLAGS	=	-I./ -I./class/ -I./class/characters/ -I./class/potions/ -I./class/weapons/ -I./class/items/

NAME	=	assignement

all:	core


core:	$(OBJ_CORE)
	$(CC) -g3 -o $(NAME) $(OBJ_CORE) $(CFLAGS) $(CPPFLAGS)
	make clean

clean:
	$(RM) $(OBJ_CORE)
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re core