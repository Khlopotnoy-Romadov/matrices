import matrices, numpy

A = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
A1 = [[2, -1, 5],[1,1,-3],[2,4,1]]
B = [[1, 5, 0], [0, 1, 0], [20, 10, 70]]
v = [1,2,3]
v1 = [10, -2, 1]
A2 = [[1, -4, -2], [3, 1, 1], [3, -5, -6]]
v2 = [-3, 5, -9]

print("matrix A: \n", A)
print("matrix B: \n", B)
print("A x B: \n", matrices.multiply(A, B))
print("A + B: \n", matrices.add(A, B))
print("identity matrix of size 5: \n", matrices.identity_matrix(5))
print("B x 15: \n", matrices.mul_on_number(B, 15))
print("random square matrix 4 x 4", matrices.random_matrix(4))
print("random square symmetric matrix 3 x 3", matrices.random_symm_matrix(3))
print("random square diagonal matrix 5 x 5", matrices.random_diag_matrix(5))
print("transposition", matrices.matrix_transpose(B))
print("solve", matrices.solve(A2, v2))



