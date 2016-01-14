#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef bool;
enum {false,true};
bool *update(bool*);
void draw(bool *);
int size=0;

int main(){
  scanf("%d",&size);
  bool *grid = malloc(size*size*sizeof(bool));
  int index;
  srand(time(NULL));
  for(index=0;index<size*size;index++)
    *(grid +index)=rand()%2;
  
  while(true){
    usleep(100000);
     for(index=0;index<size*size;index++){
       if(index%size==0)printf("\n");
       if(*(grid+index)==true)
	 printf(" 0");
	 else printf("  ");
     }
     update(grid);
  }
}
bool *update(bool *grid){
  bool *tempgrid = malloc(size*size*sizeof(bool));
  int index,x,y,i,j;//iteration variables (x,y)>primaryloop (i,j)>countloop index>copy loop
  for(index=0;index<size*size;index++)
    *(tempgrid+index)=*(grid+index);
  for(x=0;x<size;x++){
    for(y=0;y<size;y++){
      int count = 0;
      for(i=x-1;i<=x+1;i++){
	for(j=y-1;j<=y+1;j++){
	  if(i>=0 && i<size && j>=0 && j<size)
	    if(*(grid+i*size+j)==true)
	      count++;
	}
      }
      if(*(grid+x*size+y)==true){
	  if(count<3 || count>4)
	    *(tempgrid+x*size+y)=false;
      }else if(count==3)
	*(tempgrid+x*size+y)=true;
    }
  }
  for(index=0;index<size*size;index++)
    *(grid+index)=*(tempgrid+index);
  free(tempgrid);
  return grid;
}
