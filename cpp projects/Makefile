CC = g++
TARGET = BattleShip
SOURCES = 	./BattleShipApp/main.cpp \
			./GamePlay/GameManager.cpp \
			./GamePlay/player.cpp \
			./GamePlay/Map.cpp \
			./GamePlay/Ship.cpp \
			./BattleShipApp/BattleShip.cpp \
			./Pane/Pane.cpp \
			./Pane/BattleShipMap.cpp \
			./Pane/StatPane.cpp \
			./Pane/InputPane.cpp \
			./GamePlay/Aircraft.cpp \
			./GamePlay/BattleShip.cpp \
			./GamePlay/Cruiser.cpp \
			./GamePlay/Destroyer.cpp  
LDFLAGS = -lncurses

all:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS)

run:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS) && ./$(TARGET)

clean:
	rm -rf *.o $(TARGET)