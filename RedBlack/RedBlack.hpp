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

    /*
    Node(int code, int score, std::string nome, Color cor)
        : code(code), score(score), nome(nome), cor(cor), esq(nullptr), dir(nullptr), pai() {}
    */
        Node(int code , int score ,std::string nome, Color cor):
        code(code), score(score), nome(nome), cor(cor), esq(nullptr) , dir(nullptr) , pai(){}

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
        void transplant(std::shared_ptr<Node> raiz , std::shared_ptr<Node> u , std::shared_ptr<Node> v); //feito
        std::shared_ptr<Node> minimum(std::shared_ptr<Node> node); //feito


    public:
        Tree();
        ~Tree();

        std::shared_ptr<Node> arv_CriarArv(); //feito
        std::shared_ptr<Node> arv_buscaArv(std::shared_ptr<Node> raiz , int code);//feito
        std::shared_ptr<Node> arv_BuscaArvThreads(std::shared_ptr<Node> raiz , int code);

        std::shared_ptr<Node> arv_CriaNode(Node no); //feito
        void rotationLeft(std::shared_ptr<Node> raiz, std::shared_ptr<Node> no); //feito
        void rotationRigth(std::shared_ptr<Node> raiz,std::shared_ptr<Node> no); //feito

        int arv_Altura(std::shared_ptr<Node> raiz); //feito

        void arv_InsereRB(std::shared_ptr<Node> raiz , Node no); //

        void arv_Remove(std::shared_ptr<Node> raiz , Node no); //

        void arv_ImprimeNode(std::shared_ptr<Node> no); //feito
        void arv_ImprimeOrdem(std::shared_ptr<Node> raiz); //feito
        void arv_ImprimePosOrdem(std::shared_ptr<Node> raiz); //feito

        bool arv_Vazia(std::shared_ptr<Node> raiz); //feito

};


#endif //REDBLACK_HPP
