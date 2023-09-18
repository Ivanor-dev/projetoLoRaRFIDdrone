#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef struct{
    float x;
    float y;
}Position2R;

typedef struct {
    Position2R p2r;
    float z;
}Position3R;



int main(void){
    
    Position3R location;  

    std::vector<std::vector<int>> matrizMap(20, std::vector<int>(30));
    // int matrizMap[10][12];
    int randomNum = 0;
    srand(time(NULL));
    for(int i = 0; i < 20; i+=1){
        matrizMap[i][0] = 0;
        matrizMap[i][29] = 0;
        
        randomNum = rand()%2;
        if(i%2 == 1 && matrizMap[i-1][1] == 1){
             for(int j = 1; j < 20; j++){
                matrizMap[i][j] = 0;
            }     
        }else{
            for(int j = 1; j < 29; j++){
                matrizMap[i][j] = randomNum;
            }
        }
    }


    std::vector<Position2R> stockShelvesPosition(10);

    for(int i = 1; i < 10; i++)
        for(int j = 0; j < 11; j++){
            if(matrizMap[i][j] == 1){
                stockShelvesPosition.emplace_back(i, j);
            }
        }

    std::vector<Position2R> wayOfDrone;
    for(std::vector<Position2R>::iterator it = stockShelvesPosition.begin(); it != stockShelvesPosition.end(); it++){
        
        Position2R position = *it;
        wayOfDrone.emplace_back( position.x - 1, position.y - 1);
        
    }
    




    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 30; j++){
            std::cout << matrizMap[i][j] << " ";
        }
        std::cout << std::endl;
    }


}