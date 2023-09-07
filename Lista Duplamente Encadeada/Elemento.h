#pragma once

class Elemento {
    private:
        int valor;
        Elemento* anterior;
        Elemento* proximo;

    public:
        Elemento(int valor) {
            this->valor = valor;
            this->anterior = nullptr;
            this->proximo = nullptr;
        }
        
        int getValor() {
            return this->valor;
        }

        void setValor(int valor) {
            this->valor = valor;
        }

        Elemento* getAnterior() {
            return this->anterior;
        }

        void setAnterior(Elemento* anterior) {
            this->anterior = anterior;
        }

        Elemento* getProximo() {
            return this->proximo;
        }

        void setProximo(Elemento* proximo) {
            this->proximo = proximo;
        }
};