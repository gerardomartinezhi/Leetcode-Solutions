#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // listen
            //Recibo un array con strings
            //Escribir una función para encontrar el prefix mayor, que comparten todas las palabras
            //Si no lo encuentro, regreso un empty string
            //El array puede tener entre 1 y 200 palabras
            //Cada palabra puede tener entre 0 y 200 characters
        
        // example
            //["arandano", "argelia", "argentina"] -> "ar"
            //["flower", "flow", "flight"] -> "fl"
            
        
        // brute force
            //Puedo hacer un array con characters de la primera palabra
            //La siguiente palabra checar las letras que son iguales, cuando exista una dif la borro
            //Hago lo mismo para las demas, pero solo checo el size del array de prefix
            //Al final regreso todos los elementos en el array, juntos
            //memory: O(m)
            //runtime: O(n * m)
        
        // optimize
            //Si el array tiene un elemento, retorno ese elemento
            //Si una palabra tiene size 0, retorno un empty string
        
            //Puedo tener apuntador al indice en donde son iguales las palabras
            //solo sería comparar size de la palabra con el apuntador
            //Puedo sacar el size del primer prefix al comparar las primeras 2 palabras
            //Asi siempre tengo el dato de hasta donde recorrer, pero mantengo memory O(1)
            //Runtime BCR: O(elementos de la lista * prefix) O(n log n)
        
            //Simplify and generalize
                //Primero lo aplicare con 2 palabras nadamas, el recorrido
                
            
        
        // walkthrough
            // 
        
        // implement
            //
        
        // test
            //Array con puro empty string
        
            //Special case:
                //Array con 1 elemento
                //Palabras que no coinciden
        
        //Checo el size del array
        //Si es de un elemento, regreso ese elemento
        if(strs.size() == 1){ return strs[0]; }
        
        string result = strs[0];
        
        for(int i = 0; i < strs.size()-1; i++){
            
            string aux;
            
            //Saco la palabra de menor tamaño, para no pasarme de indice
            int size = (strs[i].size() > strs[i+1].size()) ? strs[i+1].size() : strs[i].size();
            
            for(int j = 0; j < size; j++){
                if(strs[i+1][j] == strs[i][j]){
                    aux += strs[i][j];
                }
                else{
                    break;
                }
            }
            cout << "aux: " <<  aux << endl;
            if(aux == ""){return "";}
            
            result = (aux.size() > result.size()) ? result: aux;
            
        }

        return result;
    }
};
/*
    Es muy sencillo, pero no estaba pensando claro.

*/