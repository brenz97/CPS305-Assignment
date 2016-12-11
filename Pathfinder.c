#include <stdio.h>
#include "QueueCode/QueueImplementation.c"

ItemType newItem(int i, int j, ItemType * link);
int compareItem(ItemType a, ItemType b);

int main(int argc, char * argv[]){
    
    int i, j, width, height, visited, size;
    
    size = 0;
    scanf("%d %d", &width, &height);

    char map[height][width], line[width];
    ItemType item, seen[height*width], * node;
    Queue Q;
    IntitializeQueue(&Q);

    for(i=0; i<height; i++){
        scanf("%s",line);
        for(j=0; j<width; j++){
            map[i][j]=line[j];
            if(line[j]=='s'){
                item = newItem(i,j,NULL);
                Insert(item, &Q);
                seen[size]=item;
                size++;
            }
        }
    }

    while(!Empty(&Q)){

        Remove(&Q, Qitem);
        if(map[item.i][item.j]=='e'){

            printf("A Path:\n");
            node=&item;

            while(node->link != NULL){
                map[node->i][node->j]='*';
                printf("[%d,%d]",node->i,node->j);
                node = node->link;
            }
            print("\n");

            for(i=0; i<height; i++){
                for(j=0; j<width; j++){
                    printf("%c",map[i][j]);
                }
                print("\n");
            }
            return 1;
        } else{

            visited=0;
            for(i=0; i<size; i++){
                if(compareItem(item,seen[i])){
                    visited=1;
                    break;
                }
            }

            if(!visited){
                seen[size]=item;
                size++;

                if(item.i>0 && (map[(item.i)-1][item.j]=='.' || map[(item.i)-1][item.j]=='e')){
                    Insert(newItem((item.i)-1,item.j, &item), &Q);
                }

                if(item.j<width && (map[item.i][(item.j)-1]=='.' || map[item.i][(item.j)-1]=='e')){
                    Insert(newItem((item.i)-1, item.j, &item), &Q);
                }

                if(item.i<height && (map[(item.i)+1][item.j]=='.' || map[(item.i)+1][item.j]=='e')){
                    Insert(newItem((item.i)-1, item.j, &item), &Q);
                }

                if(item.j>0 && (map[item.i][(item.j)-1]=='.' || map[item.i][(item.j)-1]=='e')){
                    Insert(newItem(item.i, (item.j)-1, &item), &Q);
                }
            }
        }

    }

    printf("NO PATHS");
    return 0;
}

ItemType newItem(int i, int j, ItemType * link){
    ItemType item;
    item.i = i;
    item.j = j;
    item.link = link;
    return item;
}

int compareItem(ItemType a, ItemType b){
    if((a.i == b.i) && (a.j == b.j)){
        return 1;
    } else {
        return 0;
    }
}
