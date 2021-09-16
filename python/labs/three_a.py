from math import sqrt

def new_board():
    return {} # An empty dictionary.

def is_free(board, x, y):
    return not (x, y) in board

def place_piece(board, x, y, player):
    if not is_free(board, x, y):
        return False

    board[(x, y)] = player
    return True

def get_piece(board, x, y):
    if is_free(board, x, y):
        return False

    return board[(x, y)]

def remove_piece(board, x, y):
    if is_free(board, x, y):
        return False

    del board[(x, y)] # Deletes the key from the dictionary.
    return True

def move_piece(board, x_old, y_old, x_new, y_new):
    if is_free(board, x_old, y_old) or not is_free(board, x_new, y_new):
        return False

    player = get_piece(board, x_old, y_old)
    remove_piece(board, x_old, y_old)
    place_piece(board, x_new, y_new, player)
    return True

def count(board, direction, value, player):
    count = 0
    for pos, plr in board.items():
        if (plr == player and
        (direction == "row" and pos[1] == value) or
        (direction == "column" and pos[0] == value)):
            count += 1

    return count

def dist_between(x_old, y_old, x_new, y_new):
    dist_x = abs(x_old - x_new)
    dist_y = abs(y_old - y_new)
    return sqrt(dist_x ** 2 + dist_y ** 2)

def nearest_piece(board, x, y):
    if len(board) == 0:
    	return False

    nearest = None
    nearest_dist = -1

    for pos in board:
        dist = dist_between(x, y, pos[0], pos[1])
        if dist < nearest_dist or nearest_dist == -1:
            nearest_dist = dist
            nearest = pos

    return nearest


# Tests that only run when executed directly.
if __name__ == "__main__":
    board = new_board()
    
    print(is_free(board, 500, 100))                   # Är plats (500, 100), d v s platsen på kolumn 500 och rad 100, ledig?
    print(place_piece(board, 500, 100, "spelare1"))   # Placera en figur från "spelare1" på position (500, 100).
    print(place_piece(board, 1, 100, "spelare2"))
    print(place_piece(board, 500, 100, "spelare2"))   # Försök placera en figur på en redan upptagen position.
    print(place_piece(board, 500, 200, "spelare2"))

    print(is_free(board, 500, 100))
    print(get_piece(board, 500, 100))
    print(get_piece(board, 666,666))

    print(remove_piece(board, 500, 100))              # Ta bort figuren på plats (500, 100).
    print(remove_piece(board, 1, 1))                  # Det fanns ingen figur på den platsen. 
    print(is_free(board, 500, 100))

    print(move_piece(board,  500, 200, 500, 100))     # Flytta pjäsen på (500, 200) till (500, 100).
    print(get_piece(board, 500, 100))

    print(count(board, "column", 500, "spelare2"))    # Räkna antalet figurer av typen "spelare2" på rad 500.
    print(count(board, "row", 100, "spelare2"))

    print(nearest_piece(board, 500, 105))             # Hitta figuren närmast position (500, 105).
