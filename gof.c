#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef bool;
enum {false,true};

bool *update(bool *);
int size = 0;
int main(){
  scanf("%d",&size);
  bool grid[size][size];
  int x,y;
  srand(time(NULL));
  for(x =0;x<size;x++){
    for(y=0;y<size;y++){
      if(rand()%2==0){
	grid[x][y] = true;
      }else{
	grid[x][y] = false;
      }
    }
  }
  //mainloop
  bool *gridp;
  while(true){
  usleep(50000);
  printf("-----------------------------------------------");
    for(x =0;x<size;x++){
      for(y=0;y<size;y++){
	if(grid[x][y]==true)
	printf("0 ");
	else
	  printf("  ");
      }
      printf("\n");
    }
    gridp= update(&grid[0][0]);
    int i;
    for(i=0;i<size*size;i++){
      grid[i/size][i%size]=*(gridp+i);
    }
   }
}
//update the board
bool *update(bool *g){
  printf("\n");
  // looping vars
  int x,y;
  bool grid[size][size];
  //fill grid
  int i;
  for(i=0;i<size*size;i++){
    grid[i/size][i%size]=*(g+i);
  }
  bool tempgrid[size][size];
  //looping vars
  
  //copy grid to temp
  for(x =0;x<size;x++){
    for(y=0;y<size;y++){
      tempgrid[x][y] = grid[x][y];
    }
  }
  //implement rules
  for(x=0;x<size;x++){
    for(y=0;y<size;y++){
      //count loop
      int count=0;
      int i,j;
      for(i=x-1;i<=x+1;i++){
	//printf("poop");
	for(j=y-1;j<=y+1;j++){
	  if((i>0 && i<size && j>0 && j<size))
	    if(grid[i][j]==true){
	     count++;
	    }
	  
	}  
      }
      if(grid[x][y]==true){
	if(count<3 || count>4)
	  tempgrid[x][y]=false;
      }else if(count==3) tempgrid[x][y]=true;
    }
  }
  int index;
  for(index=0;index<size*size;index++){
    *(g+index)=tempgrid[index/size][index%size]; 
  }
   return g;
}
