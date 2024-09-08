#exemplo 1#
def calcula1(I, J, K):
    I=I+3 
    J=I+K
    K=K+1
    return I, J

def calcula2(I, J, K):
    I=I+2
    J=J+K
    K=K+1
    return K

def executa(p1, p2, p3):
    p3, p1 = calcula1(p3, p1, p2)
    p2 = calcula2(p2, p2, p2)
    return p1, p2, p3

A = 3
B = 5
C = 7
A, B, C = executa(A, B, C)
print("Primeiro valor modificado = ", A)
print("Segundo valor modificado = ", B)
print("Terceiro valor modificado = ", C)

#exemplo 2#
def faz_uma_repeticao_while(X, n):
    i=0
    result=1
    while(i<n):
        result=result * X
        i=i+1
        return result

s = faz_uma_repeticao_while(2,4)
print("Resultado = %d" % s)

#exemplo 3#

def faz_uma_repeticao_for(X, n):
    i=0
    result=1
    for i in range(n):
        result=result * X
        return result

s = faz_uma_repeticao_for(2,4)
print("Resultado = %d" % s)

#exemplo 4 #
import math  
def juros_composto(P, i, n):
    M = P*(1 + i/100)**n
    return M

res = juros_composto(2000, 1.5, 10)
print("Resultado = %.2f" % res)

#exemplo 5 #
def funcao(chave):     
    nomes = ["Joao", "Jose", "Maria"]
    numeros = [17, 123, 33]
    print(nomes)     
    print(numeros)
    lista_mista = ["ola", 2.0, 5*2, [10, 20]]
    if chave in lista_mista:         
        return "S"     
    return "N"          

ret = funcao("ola") 
if ret == "S":
    print("Econtrou!!!")
    
#exemplos dado pelo chico no documento para fim de testes ainda precisar ser criado o proprio nosso