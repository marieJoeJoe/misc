#include <ncurses.h>

using namespace std;

int main(int argc,char * arv[]){


  initscr();
  int height, width, start_y, start_x;


  height = 10;
  width = 20;

  start_y = start_x =10;

  WINDOW *win = newwin(height, width, start_y, start_x);

  refresh();

  box(win,0,0);

  //wprintw(win,"this is box");
  mvwprintw(win,1,4,"this is box");

  wrefresh(win);

  int c = getch();

  endwin();

  return 0 ;
}
