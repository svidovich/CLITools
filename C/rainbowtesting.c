#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int height, int width, int y0, int x0);
void removewindow(WINDOW *the_window);

int main ()
{
	WINDOW *tl;
	WINDOW *tr; 
	WINDOW *bl;
	WINDOW *br;
	srand(time(0));
	int ch;
	int a, b, x, y;
	initscr();
	cbreak();
//	raw();
//	noecho();
	getmaxyx(stdscr, y, x);
	refresh();
	tl = createwindow(y/2,x/2, 0, 0);
	tr = createwindow(y/2,x/2, 0, x/2);
	bl = createwindow(y/2,x/2, y/2, 0);
	br = createwindow(y/2,x/2, y/2, x/2);
	refresh();
	getch();
	delwin(tl);
	delwin(tr);
	endwin();
	return 0;
}



WINDOW *createwindow(int height, int width, int y0, int x0)
{
	// Let's initialize a window.
	WINDOW *the_window;
	the_window = newwin(height, width, y0, x0);
	// We're going to put a box around the window.
	box(the_window, 0, 0);
	wrefresh(the_window);
	return the_window;
}

void removewindow(WINDOW *the_window)
{
	delwin(the_window);
}
