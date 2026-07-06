import tictactoe as tc

X = "X"
O = "O"
EMPTY = None
board = [[X, EMPTY, X],
            [X,O, EMPTY],
            [EMPTY, O, O]]


# for i in range(3):
#     for j in range(3):
#         a = (i,j)
#         board = tc.result(board, a)
print (tc.minimax(board))
