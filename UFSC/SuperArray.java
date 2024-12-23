public class SuperArray {
    private Integer inicio;
    private Integer fim;
    private Integer tamanho;
    private Integer[] superArray;
    
    public SuperArray(Integer inicio, Integer fim) {
        if (inicio > fim) {
            int temp = inicio;
            inicio = fim;
            fim = temp;
        }
        this.inicio = inicio;
        this.fim = fim;
        this.tamanho = fim - inicio + 1;
        this.superArray = new Integer[tamanho];
    }

    public Integer acessar(Integer posicao) {
        this.limiteArrayException(posicao);
        return this.superArray[posicao-this.inicio];
    }

    public void atribuir(Integer posicao, Integer valor) {
        this.limiteArrayException(posicao);
        this.superArray[posicao-this.inicio] = valor;
    }

    private void limiteArrayException(Integer posicao) {
        try {
            if (posicao < this.inicio || posicao > this.fim) {
                throw new ArrayIndexOutOfBoundsException(
                    String.format("Posição %d fora dos limites do array (%d..%d).",
                    posicao, this.inicio, this.fim)
                );
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
    }
}
