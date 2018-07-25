#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int height, int width, int y0, int x0);
void removewindow(WINDOW *the_window);
void buildmenu(WINDOW *the_window, int highlight);
void band(WINDOW *the_window);
void curl(WINDOW *the_window);
void clearwin(WINDOW *the_window);

// TODO: Make this into a struct that holds all of this data 
//       then, the  menu becomes arbitrary.
	// Highlight represents a cursor, choices represents menu items.
	// For more items and cursors, make more of these.
	int highlight = 1;
	char *choices[5] =
	{
		"I",
		"II",
		"III",
		"IV",
		"Exit"
	};
	// sizeof(choices) gives the size of an array of character pointers.
	// Character pointers are bigger than 1.
	// So, we need to divide by the size of a character pointer.
	int n = sizeof(choices)/sizeof(char *);

int main ()
{
	WINDOW *tl;
	WINDOW *tr; 
	WINDOW *bl;
	WINDOW *br;
	int ch;
	int a, b, x, y;
	initscr();
	curs_set(0);
	cbreak();
//	raw();
	noecho();
	getmaxyx(stdscr, y, x);
	refresh();
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
 	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	tl = createwindow(y/2,x/2, 0, 0);
	tr = createwindow(y/2,x/2, 0, x/2);
	bl = createwindow(y/2,x/2, y/2, 0);
	br = createwindow(y/2,x/2, y/2, x/2);
	keypad(tl, TRUE);
	keypad(tr, TRUE);
	keypad(bl, TRUE);
	keypad(br, TRUE);
	refresh();
	// TODO: Put this into a function that gets called on a window
	//	 and does a menu instance for the window.
	buildmenu(tl,highlight);
	while(1)
	{
		int choice = 0;
		wrefresh(tl);
		// This will get complicated with multiple menus.
		ch = wgetch(tl);
		switch(ch)
		{
			case KEY_UP:
				// If I'm at the top and I press up,
				if( highlight == 1 )
					// Highlight the last option
					highlight = n;
				else
					// Otherwise, move up the list
					--highlight;
				break;
			case KEY_DOWN:
				// If I'm at the bottom and I press down,
				if( highlight == n)
					// Highlight the first option
					highlight = 1;
				else
					// Otherwise, move down the list
					++highlight;
				break;
			case '\n':
				choice = highlight;
				break;
			default:
				break;
		}
		// User pressed enter.
		if( choice == 1 )
			{
				clearwin(tl);
				band(tl);
				clearwin(tl);
			}
		else if( choice == 2 )
			{
				clearwin(tl);
				curl(tl);
				clearwin(tl);
			}
		else if( choice != 0 )
			{
				break;
			}
		buildmenu(tl, highlight);
	}
	// Clear to end of line.
	clrtoeol;
	refresh();
	getch();
	delwin(tl);
	delwin(tr);
	delwin(bl);
	delwin(br);
	endwin();
	return 0;
}



WINDOW *createwindow(int height, int width, int y0, int x0)
{
	// Let's initialize a window.
	WINDOW *the_window;
	the_window = newwin(height, width, y0, x0);
	// We're going to put a box around the window.
	wborder(the_window, ':', ':', '~', '~', 'x', 'x', 'x', 'x');
	wrefresh(the_window);
	return the_window;
}

void removewindow(WINDOW *the_window)
{
	delwin(the_window);
}

// TODO: Fix weird coloring issues with the menu options
// Builds a menu with n options
void buildmenu(WINDOW *the_window, int highlight)
{
	int i, x, y;
	// Choose a sensible location inside the current box
	// where we will start our menu.
	x = 2;
	y = 2;
	for ( i = 0; i < n; ++i )
	{
		if ( highlight == i + 1 )
		{
			wattron(the_window, A_REVERSE);
			mvwprintw(the_window, y, x, "%s", choices[i]);
			wattroff(the_window, A_REVERSE);
		}
		else
			mvwprintw(the_window, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(the_window);
}

void band(WINDOW *the_window)
{
	int i, j, x, y, ch;
	ch = getch();
	getmaxyx(the_window, y, x);
	for ( i = 1; i < y-1; i ++)
	{
		for ( j = 1; j < x-1; j++ )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, i, j, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
	}
	getch();

}

void curl(WINDOW *the_window)
{
	int i, j, x, y, ch;
	ch = getch();
	getmaxyx(the_window, y, x);
	for ( i = 1; i < y-1; i++)
	{
		for ( j = 1; j < x-1; j++ )
		{
			if ( i%2 == 0 )
			{
				if ( j%2 == 0 )
				{
					mvwaddch(the_window, i, j, ch);
					wrefresh(the_window);
					usleep(1500);
				}
			}
		}
	}
	getch();

}

void clearwin(WINDOW *the_window)
{
	int i, j, x, y, ch;
	ch = ' ';
	getmaxyx(the_window, y, x);
	for ( i = 1; i < y-1; i++ )
	{
		for ( j = 1; j < x-1; j ++ )
		{
			mvwaddch(the_window, i, j, ch);
		}
	}
	wrefresh(the_window);
}












