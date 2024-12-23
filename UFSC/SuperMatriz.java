public class SuperMatriz {
    private Integer linhas;
    private Integer colunas;
    private SuperArray[] superMatriz;
    
    public SuperMatriz(Integer linhas, Integer colunas) {
        this.linhas = linhas;
        this.colunas = colunas;
        this.superMatriz = new SuperArray[this.linhas];
        int i = 0;
        for (int x = 0; x < this.linhas; x++) {
            this.superMatriz[x] = new SuperArray(i+1, i+this.colunas);
            i += this.colunas;
        }
    }

    public void atribuir(Integer linha, Integer coluna, Integer valor) {
        if (coluna < 1 || coluna > this.colunas || linha < 1 || linha > this.linhas) {
            throw new ArrayIndexOutOfBoundsException();
        }
        this.superMatriz[linha-1].atribuir(coluna*linha, valor);
    }

    public Integer acessar(Integer linha, Integer coluna) {
        Integer value_returned = 0;
        value_returned = this.superMatriz[linha-1].acessar(coluna*linha);

        return value_returned;
    }
}
