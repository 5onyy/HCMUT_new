import numpy as np
import math
from gurobipy import Model, GRB

n = 8
m = 5
S = 2
ps = 0.5

X = []
b = np.random.randint(30, 51, size=m)

l = np.random.randint(50,301, size=n)
q = np.random.randint(706,1201, size=n)
s = np.random.randint(5, 21, size=m)
c = [a - b for a,b in zip(l,q)]
A = np.random.randint(1, 6, size=(n,m))

D1 = np.random.binomial(10, 0.5, size=n)
D2 = np.random.binomial(10, 0.5, size=n)
AT = np.transpose(A)
model = Model('first stage')

x = [model.addVar(vtype=GRB.CONTINUOUS, name=f"x{i}") for i in range(m)]

z1 = [model.addVar(vtype=GRB.CONTINUOUS, name=f"z1{i}") for i in range(n)]
z2 = [model.addVar(vtype=GRB.CONTINUOUS, name=f"z2{i}") for i in range(n)]

model.setObjective(sum(b[i] * x[i] for i in range(m)) + ps * sum(c[i] * z1[i] for i in range(n)) + ps * sum(c[i] * z2[i] for i in range(n)), sense=GRB.MINIMIZE) #objective function
model.update()
for var in z1:
    model.addConstr(var >= 0, name=f"NonNegativity_{var.VarName}")
for var in z2:
    model.addConstr(var >= 0, name=f"NonNegativity_{var.VarName}")
for i, var in enumerate(z1):
    model.addConstr(var <= D1[i], name=f"Constraint_z1_{i}")
for i, var in enumerate(z2):
    model.addConstr(var <= D2[i], name=f"Constraint_z2_{i}") 
for i, var in enumerate(x):
    model.addConstr(var - np.dot(AT[i, :], z1) == 0, name=f"Constraint1_{var.VarName}")
    model.addConstr(var - np.dot(AT[i, :], z2) == 0, name=f"Constraint2_{var.VarName}")
model.update()
model.optimize()

for i, var in enumerate(x):
    X.append(var.X)
    
if np.random.randint(0,S) == 1:
    D = D1
else:
    D = D2

model_1 = Model('second stage')

z = [model_1.addVar(vtype=GRB.CONTINUOUS, name=f"z{i}") for i in range(n)]
y = [model_1.addVar(vtype=GRB.CONTINUOUS, name=f"y{i}") for i in range(m)]
    
model_1.setObjective(sum(c[i] * z[i] for i in range(n))-sum(s[i] * y[i] for i in range(m)), sense=GRB.MINIMIZE)
model_1.update()

for var in z:
    model_1.addConstr(var >= 0, name=f"NonNegativity_{var.VarName}")
for var in y:
    model_1.addConstr(var >= 0, name=f"NonNegativity_{var.VarName}")
for i, var in enumerate(z):
    model_1.addConstr(var <= D[i], name=f"Constraint_z_{i}")
for i, var in enumerate(y):
    model_1.addConstr(X[i] - np.dot(AT[i, :], z) == y[i], name=f"Constraint_{var.VarName}")
model_1.update()
model_1.optimize()
print('\n********** 2-stage SLP with recourse action in Industry-Manufacturing **********')
print("\nPreorder cost b: ", b)
print("\nAdditional cost l that satisfy a unit of demand for product: ", l)
print("\nThe unit selling price of the product: ",q)
print("\nSalvage values of parts not used: ", s)
print("\nThe matrix A that shows the units of part needed by the units of product:\n", A)
print("\nThe numbers of parts to be ordered: ", np.ceil(X))
print("\nThe numbers of unit produced:")
for i, var in enumerate(z):
    print(f"{var.VarName} = {math.ceil(var.X)}")
print("\nThe numbers of parts left in inventory:")
for i, var in enumerate(y):
    print(f"{var.VarName} = {math.ceil(var.X)}")
print("\nOptimal production costs (can be negative): ", math.ceil(model.Objval * 100)/100)



