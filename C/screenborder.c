#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void screenborder(WINDOW *the_window);

int main () {
	initscr();
	raw();
	screenborder();
	getch();
	endwin();
	return 0;
}


void screenborder(WINDOW *the_window) {
	srand(time(0));
	int ch;
	int a, b, x, y;
	start_color();
 	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
 	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	noecho();
	getmaxyx(the_window, y, x);
	ch = getch();
	for ( a = 0; a < y; a++)
	{
		for ( b = 0; b < x; b++)
		{
			if (a == 0)
			{
				attron(A_BOLD | A_BLINK);
				mvaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BOLD | A_BLINK);
				refresh();
				usleep(900);

			}
			else if (a == y-1)
			{
				attron(A_BLINK | A_BOLD);
				mvaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BLINK | A_BOLD);
				refresh();
				usleep(900);
			}
			else if (b == 0)
			{
				attron(A_BLINK | A_BOLD);
				mvaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BLINK | A_BOLD);
				refresh();
				usleep(900);
			}
			else if (b == x-1)
			{
				attron(A_BLINK | A_BOLD);
				mvaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BLINK | A_BOLD);
				refresh();
				usleep(900);
			}
		}
	}

}
