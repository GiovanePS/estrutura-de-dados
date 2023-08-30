public class Pilha {
    private Elemento inicio;
    private Elemento fim;

    public Pilha() {
        this.inicio = null;
        this.fim = null;
    }

    public void inserir(Integer valor) {
        Elemento novoElemento = new Elemento(valor);
        if (this.inicio == null) {
            this.inicio = novoElemento;
            this.fim = novoElemento;
        } else {
            this.fim.setProximo(novoElemento);
            this.fim = novoElemento;
        }
    }

    public void remover() {
        if (this.inicio == null) {
            throw new PilhaVaziaException("A pilha está vazia.");
        }

        Elemento anterior = null;
        Elemento i = this.inicio;
        while (i.getProximo() != null) {
            anterior = i;
            i = i.getProximo();
        }

        anterior.setProximo(null);
        this.fim = anterior;
    }

    public Integer getTopo() {
        if (this.inicio == null) {
            throw new PilhaVaziaException("A pilha está vazia.");
        }
        return this.fim.getValor();
    }
}