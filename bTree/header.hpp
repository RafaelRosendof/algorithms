#ifndef HEADER_HPP
#define HEADER_HPP

#include <cstdio>
#include <memory>
#include <string>


class Node{
    public:
   int code;
   int score;
   std::string cpf;
   std::string nome;

   Node(int code, int score , std::string cpf , std::string nome): code(code), score(score), cpf(cpf), nome(nome){}
   };


class Tree{
    private:
        std::unique_ptr<Tree> esq;
        std::unique_ptr<Tree> dir;
        Node no;
        int num_filhos;
    public:
        explicit Tree(const Node& no);
        ~Tree();

        //Escrita de métodos a seguir somente as assinaturas

        Tree * arvore_criaArv(); //feito
        void  arv_insere(Tree * raiz , Node no); //feito
        Node * arv_CriaNo(Node no); //feito
        Tree * arv_buscaNode(Tree * raiz , int code); //feito
        Tree * arv_buscaNodeT(Tree *raiz , int code);

        bool arv_vazia(Tree * raiz); //feito
        bool arv_removeNode(std::unique_ptr<Tree> &raiz , int code); //feito

        int arv_altura(Tree * raiz); //feito


        void arv_imprimeOrdem(Tree * raiz);//feito
        void arv_imprimePreOrdem(Tree * raiz);//feito
        void arv_imprimePosOrdem(Tree * raiz);//feito

        //int arv_altura(Tree * raiz);



};


#endif
