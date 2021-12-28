#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //1) Listen
                //I receive an integer array called "nums"
                //Move all ceros to the end of the list
                //Must mantain relative order of non-0 elements
                //I must resolve it with constant memory
                //Array size is between 1 and 10,000
                
        
        //2) Example
            //[0, 1, 2, 0, 3] -> [1, 2, 3, 0, 0]
            //[0, 0, 0, 0, 1] -> [1, 0, 0, 0, 0]
            //[0, 1, 2, 3, 4] -> [1, 2, 3, 4, 0]
            //[1, 2, 0, 3, 0] -> [1, 2, 3, 0, 0]
        
        //3) Brute Force
            //Brute force puede ser aplicar switch como en bubble sort, pero solo para recorrer el 0
            //El peor de los casos sería O(N^2)
        
        //4) Optimize
            //Un algoritmos más optimizado puede utilizar 2 pointers
            //uno que recorre el array y al encontrar un 0, manda al otro pointer hacia adelante
                //Si el pointer auxiliar encuentra un valor distinto a 0, hace switch.
                //Si llega al final de la lista, salimos y regresamos
            //Runtime sería entre O(N) y O(N log N)
        
        //5) Walkthrough
            //Creo pointer que recorre la lista
            //Recorre la lista hasta encontrar un 0
            //Al encontrar un 0, manda al otro pointer en busca de un valor distinto a 0
                //Aux encuentra, switch
                //No encuentra, salimos
            //Regresamos
        
        //6) Implement
        
        //7) Test
        
        for(int i = 0; i < nums.size(); i++){
            int aux = i;
            
            //Checo si estoy al final de la lista
            if(i == nums.size()-1){
                //Si estoy al final de la lista, salgo
                break;
                }
            
            if(nums[i] == 0){   //Si encuentra un 0
                
                //Despliego el auxiliar
                aux++; 
                
                
                while(aux <= nums.size()-1){ //Mientras no recorra toda la lista
                    
                    if(nums[aux] != 0){ //Si su valor es diferente a 0
                        //Switch
                        switchNums(nums, i, aux);
                        break;  //Salimos
                    }
                    else{
                        aux++; //Recorremos uno
                    }
                }
                  
            }
            
            if(aux == nums.size()){ //Si aux llego al final de la lista
                    break;  //Salimos
                }
        } 
        
    }
    
    void switchNums(vector<int> & nums, int & i, int & j){
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
};