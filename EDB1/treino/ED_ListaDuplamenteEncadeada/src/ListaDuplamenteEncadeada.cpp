//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CABECA_--NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CAUDA_--CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->setProximo(this->cauda);
    this->cabeca->setAnterior(nullptr);

    this->cauda->setProximo(nullptr);
    this->cauda->setAnterior(this->cabeca);

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{

	auto atual = cabeca;

	while(atual != nullptr){
		auto proximo = atual -> getProximo();
		delete atual;
		atual = proximo;
	}

}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void)
{
    return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
    return this->tamanho() == 0;
}

std::string ListaDuplamenteEncadeada::recuperar(int i)
{
	if(i < 0 || i > quantidade){
		return "";
	}
	//if(i == 0) {return cabeca -> getValor();}
	//if(i == quantidade) {return cauda -> getValor();}

	auto aux = cabeca -> getProximo();
	if(i==0) return aux -> getValor();
	if(i==quantidade) return cauda -> getAnterior() -> getValor();

	for(int j = 0 ; j < i - 1 ; j ++){
		aux = aux -> getProximo();
	}

	return aux -> getValor();
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{

	auto aux = cabeca -> getProximo();
	int i = 0;

	while(aux != cauda){
		if(aux -> getValor() == s){
			return i+1;
		}else{
			aux = aux -> getProximo();
			i++;
		}
	}
	return -1;
	
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{   
	auto aux = this -> cabeca -> getProximo();
	auto novo = new No<std::string>(s);

	novo -> setProximo(aux);
	novo -> setAnterior(this->cabeca);

	aux -> setAnterior(novo);
	this-> cabeca -> setProximo(novo);

	quantidade++;

	return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{    

	auto aux = this -> cauda -> getAnterior();
	auto novo = new No<std::string>(s);

	novo -> setAnterior(aux);
	novo -> setProximo(this->cauda);
	aux -> setProximo(novo);
	this-> cauda -> setAnterior(novo);

	quantidade++;
	return true;
}


bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    

}

/*
	auto aux = this -> cabeca -> getProximo();
	No<std::string>* novo = new No<std::string>(s);

	//if(i == 0) { inserirNaCabeca(s); return true; }
	//if(i == quantidade){ inserirNaCauda(s); return true; }

	for(int j = 0 ; j < i-1 ; j++){
		aux = aux -> getProximo();
	}

	novo -> setProximo(aux);
	novo -> setAnterior(aux -> getAnterior());
	aux -> getAnterior() -> setProximo(novo);
	aux -> setAnterior(novo);

	quantidade++;
	return true;
*/
std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
	auto aux = this -> cabeca -> getProximo();
	if(quantidade == 0) return "";
	if(aux == nullptr) return "";

	std::string valor = aux -> getValor();

	this->cabeca -> setProximo(aux -> getProximo());

	if(aux -> getProximo() != nullptr){
		aux -> getProximo() -> setAnterior(this-> cabeca);
	}
	else{
		cauda = cabeca;
	}
	delete aux;
	quantidade--;
	return valor;
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
	auto aux = this -> cauda -> getAnterior();
	if(quantidade == 0) return "";
	if(aux == nullptr) return "";

	std::string valor = aux -> getValor();

	this -> cauda -> setAnterior(aux -> getAnterior());
	if(aux -> getAnterior() != nullptr){
		aux -> getAnterior() -> setProximo(this -> cauda);
	}
	else{
		cabeca = cauda;
	}

	delete aux;
	quantidade--;
	return valor;
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
	auto aux = this -> cabeca -> getProximo();
	if(i == 0) return removerDaCabeca();
	if(i == quantidade) return removerDaCauda();

	std::string valor = aux -> getValor();

	for(int j = 0 ; j < i-1 ; j++){
		aux = aux -> getProximo();
	}

	aux -> getAnterior() -> setProximo(aux -> getProximo());
	aux -> getProximo() -> setAnterior(aux -> getAnterior());

	delete aux;
	quantidade--;
	return valor;
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->getProximo() == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->getProximo()->getAnterior() != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->getAnterior() != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->getAnterior() == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->getAnterior()->getProximo() != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->getProximo() != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->getProximo() != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->getAnterior() )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->getProximo(); i != this->cauda; i=i->getProximo())
		{
			if( i->getProximo()->getAnterior() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->getAnterior()->getProximo() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
