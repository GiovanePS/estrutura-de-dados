class Lista {
    private Elemento inicio;
    private Elemento fim;
    private Integer tamanho;

    public Lista() {
        this.inicio = null;
        this.fim = null;
        this.tamanho = 0;
    }

    public void inserirComoPrimeiro(Integer valor) {
        Elemento novoElemento = new Elemento(valor);
        tamanho++;
        if (ListIsVoid()) {
            this.inicio = novoElemento;
            this.fim = novoElemento;
        } else {
            novoElemento.setProximo(this.inicio);
            this.inicio = novoElemento;
        }
    }

    public void inserirComoUltimo(Integer valor) {
        Elemento novoElemento = new Elemento(valor);
        tamanho++;
        if (ListIsVoid()) {
            this.inicio = novoElemento;
            this.fim = novoElemento;
        } else {
            this.fim.setProximo(novoElemento);
            this.fim = novoElemento;
        }
    }

    public void inserirNaPosicao(Integer posicao, Integer valor) {
        if (posicao < 0 || posicao > this.tamanho) {
            throw new ArrayIndexOutOfBoundsException();
        }

        if (posicao == 0) {
            this.inserirComoPrimeiro(valor);
            return;
        }

        int i = 0;
        Elemento iterador = this.inicio;
        Elemento anterior = iterador;
        while (i < posicao) {
            anterior = iterador;
            iterador = iterador.getProximo();
            i++;
        }

        Elemento novoElemento = new Elemento(valor);
        anterior.setProximo(novoElemento);
        novoElemento.setProximo(iterador);
        tamanho++;
    }

    public void inserirAntesDe(Integer referencia, Integer valor) {

        if (this.inicio.getValor() == referencia) {
            this.inserirComoPrimeiro(valor);
            return;
        }
        
        Elemento iterador = this.inicio;
        while (iterador.getProximo().getValor() != referencia) {
            iterador = iterador.getProximo();
            if (iterador.getProximo() == null) { return; }
        }

        Elemento novoElemento = new Elemento(valor);
        novoElemento.setProximo(iterador.getProximo());
        iterador.setProximo(novoElemento);
        tamanho++;
    }

    public void inserirDepoisDe(Integer referencia, Integer valor) {
        Elemento iterador = this.inicio;
        while (iterador.getValor() != referencia) {
            iterador = iterador.getProximo();
        }

        Elemento novoElemento = new Elemento(valor);
        novoElemento.setProximo(iterador.getProximo());
        iterador.setProximo(novoElemento);

    }

    public void removerPrimeiro() {
        if (ListIsVoid()) {
            throw new ArrayVoidException();
        } else {
            this.inicio = this.inicio.getProximo();
            tamanho--;
        }
    }
    
    public void removerUltimo() {
        if (ListIsVoid()) {
            throw new ArrayVoidException();
        }

        if (this.inicio.getProximo() == null) {
            this.removerPrimeiro();
            return;
        }

        Elemento iterador = this.inicio;
        Elemento anterior = null;
        while (iterador.getProximo() != null) {
            anterior = iterador;
            iterador = iterador.getProximo();
        }

        anterior.setProximo(null);
        this.fim = anterior;
        tamanho--;
    }

    public void removerDaPosicao(Integer posicao) {
        int i = 0;
        Elemento iterador = this.inicio;
        Elemento anterior = null;
        while (i < posicao) {
            anterior = iterador;
            iterador = iterador.getProximo();
            i++;
        }

        anterior.setProximo(iterador.getProximo());
        tamanho--;
    }

    public void remover(Integer referencia) {
        Elemento iterador = this.inicio;
        Elemento anterior = null;
        this.fim.setProximo(new Elemento(referencia));
        while (iterador.getValor() != referencia) {
            anterior = iterador;
            iterador = iterador.getProximo();
        }

        this.fim.setProximo(null);
        if (iterador != this.fim.getProximo()) {
            anterior.setProximo(iterador.getProximo());
        }

        tamanho--;
    }

    public void removerDaPosicaoRelativa(Integer antesDe, Integer depoisDe) {
        Elemento alvo = this.inicio;
        Elemento anterior = alvo;
        while (anterior.getValor() != depoisDe || alvo.getProximo().getValor() != antesDe) {
            anterior = alvo;
            alvo = alvo.getProximo();
        }

        anterior.setProximo(alvo.getProximo());
    }

    public Integer acessaPrimeiro() {
        return this.inicio.getValor();
    }
    public Integer acessaUltimo() {
        return this.fim.getValor();
    }
    public Integer acessaDaPosicao(Integer posicao) {
        int i = 0;
        Elemento iterador = this.inicio;
        while (i < posicao) {
            iterador = iterador.getProximo();
            i++;
        }

        return iterador.getValor();
    }

    public String printLista() {
        String strintToReturn = "[";
        Elemento iterador = this.inicio;
        while (iterador != null) {
            strintToReturn += String.format("%d", iterador.getValor());
            if (iterador.getProximo() != null) {
                strintToReturn += ", ";
            }
            iterador = iterador.getProximo();
        }

        strintToReturn += "]";

        return strintToReturn;
    }

    private boolean ListIsVoid() {
        if (this.fim == null || this.inicio == null) { return true; }
        else { return false; }
    }
}