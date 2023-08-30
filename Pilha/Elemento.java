public class Elemento {
    private Integer valor;
    private Elemento proximo;

    public Elemento(Integer valor) {
        this.valor = valor;
        this.proximo =  null;
    }

    public Integer getValor() {
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
