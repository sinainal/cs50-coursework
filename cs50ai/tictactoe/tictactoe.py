"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    n = 0
    for i in board:
        for j in i:
            if j is not None:
                n += 1
    if n % 2 == 1:
        return O
    else:
        return X



def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions = set()
    x = 0
    y = 0
    for i in board:
        x += 1
        for j in i:
            y +=1
            if j is None:
                actions.add((x-1,y-1))
        y = 0
    return actions



def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    p = player(board)
    i = action[0]
    j = action[1]
    boardc = copy.deepcopy(board)
    if boardc[i][j] == None and -1<i<3 and -1<j<3:
        boardc[i][j] = p
    else:
        raise Exception("invalid move")
    return boardc


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    I = [0,0,0]
    J = [0,0,0]
    d1=0
    d2=0
    for i in range(3):
        for j in range(3):
            if board[i][j] == "X":
                I[j] += 1
                J[i] += 1
                if i==j:
                    d1 += 1
                if i+j == 2:
                    d2 += 1
            if board[i][j] == "O":
                I[j] += -1
                J[i] += -1
                if i==j:
                    d1 -= 1
                if i+j == 2:
                    d2 -= 1
    if 3 in I or 3 in J or d1 == 3 or d2 == 3:
        return X
    if -3 in I or -3 in J or  d1 == -3 or d2 == -3:
        return O
    else:
        return None



def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) or None not in sum(board,[]) :
        return True
    else:
        return False


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    c = winner(board)
    if c == X:
        return 1
    if c == O:
        return -1
    else:
        return 0

def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    if terminal(board):
        return None
    print(board)
    p = player(board)
    action_list = actions(board)
    print(action_list)
    print(p)
    best_action = (0,0)
    v = 0
    best_max = -2
    best_min = 2
    if p == X:
        for action in action_list:
            v = min_val(result(board, action))
            print(v)
            if v > best_max:
                best_max = v
                best_action = action
            print(action)
            print(best_action)
    else:
        for action in action_list:
            v = max_val(result(board, action))
            print(v)
            if v < best_min:
                best_min = v
                best_action = action
            print(action)
            print(best_action)
    return best_action


def max_val(board):
    if terminal(board):
        return utility(board)
    v = -2
    for action in actions(board):
        v = max(v, min_val(result(board, action)))
    return v
def min_val(board):
    if terminal(board):
        return utility(board)
    v = 2
    for action in actions(board):
        v = min(v, max_val(result(board, action)))
    return v



