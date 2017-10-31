#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class nodo
{
public:
    T valor;
    nodo *siguiente;
    nodo(T val)
    :valor(val),siguiente(NULL)
    {
        siguiente = 0;
    }
};

template <typename T>
class list
{
public:
    nodo<T>* inicio;
    nodo<T>* fin;
    int cantElementos;
    list()
    {
        inicio = NULL;
        fin = NULL;
        cantElementos = 0;
    }
    list<T> subLista(int ini, int fin)
    {
        list<T> miLista;
        if(ini < 0 || fin > (this->cantElementos-1))
            return miLista;
        nodo<T>* it = this->inicio;
        int cont = 0;
        for(int i = ini; i <= fin; i++)
        {
            miLista.insertar(this->obtener(i),cont);
            it = it->siguiente;
            cont++;
        }
        
    }
    list<T> clonar()
    {
        list<T> miLista;
        nodo<T>* it = this->inicio;
        for(int i = 0; i < this->cantElementos; i++)
        {
            miLista.insertar(it->valor,i);
            it = it->siguiente;
        }
        return miLista;
    }
    list<T> interseccion(list<T> lis)
    {
        list<T> miLista = lis.unir(*this);
        nodo<T>* it = miLista.inicio;
        for(int i = 0; i < miLista.cantElementos; i++)
        {
            if(this->buscar(it->valor) != -1 && lis.buscar(it->valor) != -1)
            {
                it = it->siguiente;
                continue;
            }
            miLista.eliminar(i);
        }
        return miLista;
        
    }
    list<T> unir(list<T> lis)
    {
        list<T> miLista;
        nodo<T>* it = lis.inicio;
        nodo<T>* it1 = this->inicio;
        for(int i = 0; i < lis.cantElementos; i++)
        {
            miLista.insertar(it->valor,miLista.cantElementos);
            it = it->siguiente;
        }
        for(int m = 0; m < this->cantElementos; m++)
        {
            miLista.insertar(this->obtener(m),miLista.cantElementos);
            it1 = it1->siguiente;
        }
        it = miLista.inicio;
        for(int i = 0; i < miLista.cantElementos; i++)
        {
            int reps = 0;
            for(int t = 0; t < miLista.cantElementos; t++)
            {
                if(miLista.obtener(i) == miLista.obtener(t))
                {
                    reps++;
                }
                if(reps > 1)
                {
                    miLista.eliminar(t);
                    reps--;
                }
            }
            
        }
        
        return miLista;
    }
    int insertar(T val,int pos)
    {
        if(pos > cantElementos || pos < 0)
        {
            return -1;
        }
        nodo<T>* nuevo = new nodo<T>(val);
        if(pos == 0)
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
            fin = nuevo;
        }
        else if(pos == cantElementos)
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        else
        {
            nodo<T>* temp = inicio;
            for(int i = 0; i < (pos-1); i++)
            {
                temp = temp->siguiente;
            }
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
            return 0;
        }
        this->cantElementos++;
    }
    void push_back(T val)
    {
        insertar(val,cantElementos);
    }
    void pop_front()
    {
        eliminar(0);
    }
    void push_front(T val)
    {
        insertar(val,0);
    }
    T obtener(int pos)
    {
        nodo<T>* temp = this->inicio->siguiente;
        if(pos < 0 || pos > (cantElementos-1))
        {
            return -1;
        } 
        else if(pos == 0)
        {
            return this->inicio->valor;
        }
        else if(pos == (cantElementos-1))
        {
            return this->fin->valor;
        }

        for(int i = 1; i < cantElementos; i++)
        {
            if(pos == i)
                return temp->valor;
            temp = temp->siguiente;
            
        }
        return -1;
    }
    int buscar(T val)
    {
        nodo<T>* temp = inicio;
        for(int i = 0; i < cantElementos; i++)
        {
            if(temp->valor == val)
                return i;
            temp = temp->siguiente;
            
        }
        return -1;
    }
    T eliminar(int pos)
    {
        if(pos < 0 || pos >= cantElementos)
        {
            return -1;
        }
        nodo<T>* eliminar;
        if(pos ==0)
        {
            eliminar = inicio;
            inicio = inicio->siguiente;
        }
        else
        {
            nodo<T>* tmp =  inicio;
            for(int i = 0; i < pos-1; i++)
            {
                tmp = tmp->siguiente;
            }
            eliminar = tmp->siguiente;
            tmp->siguiente = tmp->siguiente->siguiente;
            if(tmp->siguiente != NULL)
            {
                 
            }
            else{
                fin = tmp;
            }
        }
        if(cantElementos == 1)
        {
            fin == NULL;
        }
        cantElementos--;
        T eliminado = eliminar->valor;
        delete eliminar;
        return eliminado;
    }

};

