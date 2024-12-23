public class Elemento {
    private int valor;
    private Elemento proximo;

    public Elemento(int valor) {
        this.valor = valor;
        this.proximo =  null;
    }

    public int getValor() {
        return this.valor;
    }

    public void setValor(Integer valor) {
        this.valor = valor;
    }

    public Elemento getProximo() {
        return this.proximo;
    }

    public void setProximo(Elemento proximo) {
        this.proximo = proximo;
    }
}
