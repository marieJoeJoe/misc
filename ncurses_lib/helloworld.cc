#include <ncurses.h>

using namespace std;

int main(int argc,char * arv[]){


  initscr();

  int x,y;

  x=y=10;

  move(x,y);

  printw("hello world!");

  refresh();

  int c = getch();
 
    clear();

  //move(0,0);
  
  //printw("\n%d\n",c);
  mvprintw(0,0,"\n%d\n",c);
  
  getch();

  endwin();

}
