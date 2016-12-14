#include <stdio.h>
#include "QueueImplementation.c"

ItemType newItem(int i, int j, ItemType * link);
int compareItem(ItemType a, ItemType b);

int main(int argc, char * argv[]){

	int i, j, width, height, visited, size=0;
	scanf("%d %d", &width, &height);

	char map[height][width], line[width];
	ItemType start, item, seen[height*width], * node;
	Queue Q;
	InitializeQueue(&Q);

	for(i=0; i<height; i++){	//inserts data from stdin into the char matrix, map,
		scanf("%s",line);	//when 's' is found, create new ItemType structure for s,
		for(j=0; j<width; j++){	//and add it to the container 'Q'
			map[i][j]=line[j];
			if(line[j]=='s'){
				start = newItem(i,j,NULL);
				Insert(start, &Q);
			}
		}
	}


	while(!Empty(&Q)){

		Remove(&Q, &item);
		visited=0;				//sets the item as not visited
		for(i=size-1; i>0; i--){		//iterates through list of seen items
			if(compareItem(item,seen[i])){	//if item is in list, add to seen
				visited=1;
				break;
			}
		}

		if(visited){
			//item already seen so skip
		} else if(map[item.i][item.j]=='e') {
			ItemType path[size];
			i=0;
			node=&item;
			printf("A Path:\n");
			while(node != NULL){	//reverse path, and mark path in map with '*'
				path[i] = *(node);
				i++;
				map[node->i][node->j]='*';
				node = node->link;
			}

			for(j=i-1;j>-1;j--){					//print path
				printf("[%d,%d]", path[j].i, path[j].j);
			}
			printf("\n");

			for(i=0; i<height; i++){				//print matrix
				for(j=0; j<width; j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
			return 1;

		} else {			//item hasnt been seen and isnt the end

			seen[size]=item;	//add item to seen items and increase number of items seen
			size++;

			//if in bounds and either and empty or end cell
			//create new ItemType structure and add to 'Q'
			//do for cells above, below, left, and right of current cell
			if(item.i>0 && (map[(item.i)-1][item.j]=='.' || map[(item.i)-1][item.j]=='e')){
				Insert(newItem((item.i)-1,item.j, &seen[size-1]), &Q);
			}

			if(item.j<(width-1) && (map[item.i][(item.j)+1]=='.' || map[item.i][(item.j)+1]=='e')){
				Insert(newItem(item.i, (item.j)+1, &seen[size-1]), &Q);
			}

			if(item.i<(height-1) && (map[(item.i)+1][item.j]=='.' || map[(item.i)+1][item.j]=='e')){
				Insert(newItem((item.i)+1, item.j, &seen[size-1]), &Q);
			}

			if(item.j>0 && (map[item.i][(item.j)-1]=='.' || map[item.i][(item.j)-1]=='e')){
				Insert(newItem(item.i, (item.j)-1, &seen[size-1]), &Q);
			}

		}

	}

	printf("NO PATHS\n");
	return 0;
}

//creates new ItemType structure that takes the coordinates of character in map,
//and a pointer to the item that 'found' it, then returns the new item
ItemType newItem(int i, int j, ItemType * link){
	ItemType item;
	item.i = i;
	item.j = j;
	item.link = link;
	return item;
}

//compares two items base on their coordinates in the map(matrix),
//takes two ItemType structures,
//if their x and y coordinates are the same, return true, false otherwise
int compareItem(ItemType a, ItemType b){
	if((a.i == b.i) && (a.j == b.j)){
		return 1;
	} else {
		return 0;
	}
}
