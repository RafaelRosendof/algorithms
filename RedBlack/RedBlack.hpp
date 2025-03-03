#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <iostream>
#include <memory>
#include <string>



enum Color { RED , BLACK};
class Node{

    //os ponteiros precisam ser private?

   private:
    int code;
    int score;
    std::string nome;
    Color cor;
    std::shared_ptr<Node> esq;
    std::shared_ptr<Node> dir;
    std::weak_ptr<Node> pai;

    public:
        Node(int code , int score ,std::string nome, Color cor):
        code(code), score(score), nome(nome), cor(cor){}

        int getCode() const {return code;}
        int getScore() const {return score;}
        std::string getNome() const {return nome;}
        Color getColor() const {return cor;}
        std::shared_ptr<Node> getEsq() const {return esq;}
        std::shared_ptr<Node> getDir() const {return dir;}
        std::weak_ptr<Node> getPai() const {return pai;}

        void setCode(int code) {this->code = code;}
        void setScore(int score) {this -> score = score;}
        void setNome(std::string nome) {this -> nome = nome;}
        void setCor (Color cor) {this -> cor = cor;}
        void setEsq(std::shared_ptr<Node> esq) {this->esq = esq;}
        void setDir(std::shared_ptr<Node> dir) {this->dir = dir;}
        void setPai(std::weak_ptr<Node> pai) {this->pai = pai;}

        friend class Tree;
};

class Tree{

    private:
        std::shared_ptr<Node> raiz;

        void cor_Insert(std::shared_ptr<Node> no);
        void cor_Remove(std::shared_ptr<Node> no);
        void transplant(std::shared_ptr<Node> u , std::shared_ptr<Node> v);
        std::shared_ptr<Node> minimum(std::shared_ptr<Node> node);
        std::shared_ptr<Node> maximum(std::shared_ptr<Node> node);

    public:
        Tree();
        ~Tree();

        std::shared_ptr<Node> arv_CriarArv();
        std::shared_ptr<Node> arv_buscArv(std::shared_ptr<Node> raiz , int code);
        std::shared_ptr<Node> arv_BuscaArvThreads(std::shared_ptr<Node> raiz , int code);

        std::shared_ptr<Node> arv_CriaNode(Node no);
        void rotationLeft(std::shared_ptr<Node> no);
        void rotationRigth(std::shared_ptr<Node> no);

        int arv_Altura(std::shared_ptr<Node> raiz);

        void arv_InsereRB(std::shared_ptr<Node> raiz , Node no); // why i'm can't do a pointer to the root? i'm need to have a anchor

        void arv_Remove(std::shared_ptr<Node> raiz , Node no); //here i'm need to find the pointer to remove

        void arv_ImprimeNode(std::shared_ptr<Node> no);
        void arv_ImprimeOrdem(std::shared_ptr<Node> raiz);
        void arv_ImprimePosOrdem(std::shared_ptr<Node> raiz);

        bool arv_Vazia(std::shared_ptr<Node> raiz);

};


#endif //REDBLACK_HPP
