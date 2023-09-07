#include "Elemento.h"

class ListaDuplamenteEncadeada {
private:
    Elemento* inicio;
    Elemento* fim;
    Elemento* cursor;
public:
    ListaDuplamenteEncadeada() {
        this->inicio = nullptr;
        this->fim = nullptr;
        this->cursor = nullptr;
    };

    void inserirNaFrente(int valor) {
        Elemento novoElemento(valor);
        this->inicio = &novoElemento;
        this->inicio->setProximo(&novoElemento);
        this->cursor = this->inicio;
    }

    int acessarAtual() {
        return this->cursor->getValor();
    }
};