def modular_exponentiation(base, exponent, modulus):
    # Se o divisor for 1, o resto é sempre 0
    if modulus == 1:
        return 0
    
    result = 1
    # Garante que a base inicial já esteja dentro do módulo
    base = base % modulus
    
    while exponent > 0:
        # Se o expoente for ímpar, multiplicamos o resultado pela base atual
        if exponent % 2 == 1:
            result = (result * base) % modulus
            #print(f"Expoente atual é ímpar: Multiplicando resultado -> Novo resultado: {result}")
        
        # Quadrados repetidos: eleva a base ao quadrado para a próxima potência de 2
        base = (base * base) % modulus
        
        # Divide o expoente por 2 (shift para a direita)
        exponent = exponent // 2
        
        #if exponent > 0:
            #print(f"Elevando base ao quadrado -> Próxima base: {base} (Expoente restante: {exponent})")

    return result

# Interface para o usuário
def main():
    try:
        b = int(input("Digite a base (x): "))
        #e = int(input("Digite o expoente (d): "))
        #m = int(input("Digite o divisor (n): "))

        e = 40781
        m = 67637
        final_res = modular_exponentiation(b, e, m)
        
        print(f"Resultado Final: {final_res}")
        
    except ValueError:
        print("Erro: Insira apenas números inteiros.")

if __name__ == "__main__":
    while True:
        main()