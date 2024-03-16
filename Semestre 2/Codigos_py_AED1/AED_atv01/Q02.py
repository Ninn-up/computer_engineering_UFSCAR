# Resposta Questão 02

# Função Recursiva
def comprimento(s):
    # Caso base
    if not s:
        return 0
    # Passo recursivo
    else:
        return 1 + comprimento(s[1:])


# Código principal
string = 'Hello World!'

tamanho = comprimento(string)

print(f'A string "{string}" tem tamanho {tamanho}')
print(f'O algoritmo{" " if len(string) == tamanho else "não "}funcionou, pois len(string) = {len(string)} = {tamanho}')
