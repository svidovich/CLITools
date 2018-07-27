// This library shows the different effects I've built so far.
// They will come with requirements as needed.
#include <curses.h>
// Starburst: Takes a mouse event and prints a cute starburst at the event
// location. 
// Requires mousemask(EVENT_NAME).
// Recommends curs_set(0) so that the cursor is invisible.
void starburst(MEVENT mouseevent);

// Firework: Takes a mouse event and prints a cute firework at the event location.
// Requires mousemask (EVENT_NAME).
// Recommends curs_set(0) so that the cursor is invisible.
void firework(MEVENT mouseevent);

// Screenborder: Takes a winow and makes a cute rainbow border in it given a user's
// choice of letter. Argument is any window.
void screenborder(WINDOW *the_window);


// launch and clearlaunch: These come as a pair. They draw then erase a parabola that starts
// at (0,0) and eventually reaches the mouse event location.
// Requires mousemask (EVENT_NAME). Requires math.h.
// Recommends curs_set(0) so that the cursor is invisible.
void launch(MEVENT mouseevent);
void clearlaunch(MEVENT mouseevent);

// curl: Starting from the top left, draws a spiral around the whole of a window.
// Takes any window for its argument.
void curl(WINDOW *the_window);

// snake: Starting from the top left, prints all the way to
// the bottom, moves over a space, all the way to the top,
// then repeats.
// Takes any window for its argument.
void snake(WINDOW *the_window);

void snake(WINDOW *the_window)
{
	int i, j, xmin, xmax, ymin, ymax, ch;
	ch = getch();
	getmaxyx(the_window, ymax, xmax);
	xmin = 1;
	while( xmin < xmax-1 )
	{
		for ( j = 1; j < ymax-1; j++ )
		{
			mvwaddch(the_window, j, xmin, ch);
			wrefresh(the_window);
			usleep(20000);
		}
		xmin++;
		for ( j = ymax-2; j >= 1; j-- )
		{
			mvwaddch(the_window, j, xmin, ch);
			wrefresh(the_window);
			usleep(20000);
		}
		xmin++;
	}
	getch();
}



void curl(WINDOW *the_window)
{
	int i, j, xmax, ymax, xmin, ymin, ch;
	xmin = 1;
	ymin = 1;
	ch = getch();
	getmaxyx(the_window, ymax, xmax);
	ymax -= 2;
	xmax -= 2;
	while( ymax >= ymin && xmax >= xmin )
	{
		for( j = xmin; j <= xmax; j++ )
		{
			mvwaddch(the_window, ymin, j, ch);
			wrefresh(the_window);
			usleep(1500);
		}
		ymin += 1;
		for( i = ymin; i <= ymax; i++ )
		{
			mvwaddch(the_window, i, xmax, ch);
			wrefresh(the_window);
			usleep(1500);
		}
		xmax -= 1;
		for( j = xmax; j >= xmin; j-- )
		{
			mvwaddch(the_window, ymax, j, ch);
			wrefresh(the_window);
			usleep(1500);
		}
		ymax -= 1;
		for( i = ymax; i >= ymin; i-- )
		{
			mvwaddch(the_window, i, xmin, ch);
			wrefresh(the_window);
			usleep(1500);
		}
		xmin += 1;
	}
	getch();
}

void launch(MEVENT mouseevent)
{
	int i;
	int y = mouseevent.y;
	int x = mouseevent.x;
	for (i = 0; i <= x; i++)
	{
		int a = floor((y/pow(x, 2))*pow(i, 2))   ;
		move(a, i);
		printw(".");
		refresh();
		usleep(20000);
	}

}


void clearlaunch(MEVENT mouseevent)
{
	int i;
	int y = mouseevent.y;
	int x = mouseevent.x;
	for (i = 0; i <= x; i++)
	{
		int a = floor((y/pow(x, 2))*pow(i, 2))   ;
		move(a, i);
		printw(" ");
		refresh();
		usleep(10000);
	}

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
				attron(A_BOLD);
				mvwaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BOLD);
				wrefresh(the_window);
				usleep(900);

			}
			else if (a == y-1)
			{
				attron(A_BOLD);
				mvwaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BOLD);
				wrefresh(the_window);
				usleep(900);
			}
			else if (b == 0)
			{
				attron(A_BOLD);
				mvwaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BOLD);
				wrefresh(the_window);
				usleep(900);
			}
			else if (b == x-1)
			{
				attron(A_BOLD);
				mvwaddch(the_window,a,b,ch | COLOR_PAIR(rand() % 8));
				attroff(A_BOLD);
				wrefresh(the_window);
				usleep(900);
			}
		}
	}

}






void firework(MEVENT mouseevent)
{

	move(mouseevent.y + 1, mouseevent.x);
	printw(".");
	move(mouseevent.y - 1 , mouseevent.x);
	printw(".");
	move(mouseevent.y, mouseevent.x + 1);
	printw(".");
	move(mouseevent.y, mouseevent.x - 1);
	printw(".");
	move(mouseevent.y + 1, mouseevent.x + 1);
	printw(".");
	move(mouseevent.y + 1, mouseevent.x - 1);
	printw(".");
	move(mouseevent.y - 1, mouseevent.x + 1);
	printw(".");
	move(mouseevent.y - 1, mouseevent.x - 1);
	printw(".");
	refresh();
	usleep(250000);

	move(mouseevent.y + 2, mouseevent.x);
	printw(".");
	move(mouseevent.y - 2 , mouseevent.x);
	printw(".");
	move(mouseevent.y, mouseevent.x + 2);
	printw(".");
	move(mouseevent.y, mouseevent.x - 2);
	printw(".");
	move(mouseevent.y + 2, mouseevent.x + 2);
	printw(".");
	move(mouseevent.y + 2, mouseevent.x - 2);
	printw(".");
	move(mouseevent.y - 2, mouseevent.x + 2);
	printw(".");
	move(mouseevent.y - 2, mouseevent.x - 2);
	printw(".");
	refresh();
	usleep(250000);


	move(mouseevent.y + 3, mouseevent.x);
	printw("*");
	move(mouseevent.y - 3 , mouseevent.x);
	printw("*");
	move(mouseevent.y, mouseevent.x + 3);
	printw("*");
	move(mouseevent.y, mouseevent.x - 3);
	printw("*");
	move(mouseevent.y + 3, mouseevent.x + 3);
	printw("*");
	move(mouseevent.y + 3, mouseevent.x - 3);
	printw("*");
	move(mouseevent.y - 3, mouseevent.x + 3);
	printw("*");
	move(mouseevent.y - 3, mouseevent.x - 3);
	printw("*");
	refresh();
	usleep(250000);


	move(mouseevent.y + 1, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 1 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 1);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 1);
	printw(" ");
	move(mouseevent.y + 1, mouseevent.x + 1);
	printw(" ");
	move(mouseevent.y + 1, mouseevent.x - 1);
	printw(" ");
	move(mouseevent.y - 1, mouseevent.x + 1);
	printw(" ");
	move(mouseevent.y - 1, mouseevent.x - 1);
	printw(" ");
	refresh();
	usleep(100000);

	move(mouseevent.y + 2, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 2 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 2);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 2);
	printw(" ");
	move(mouseevent.y + 2, mouseevent.x + 2);
	printw(" ");
	move(mouseevent.y + 2, mouseevent.x - 2);
	printw(" ");
	move(mouseevent.y - 2, mouseevent.x + 2);
	printw(" ");
	move(mouseevent.y - 2, mouseevent.x - 2);
	printw(" ");
	refresh();
	usleep(100000);


	move(mouseevent.y + 3, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 3 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 3);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 3);
	printw(" ");
	move(mouseevent.y + 3, mouseevent.x + 3);
	printw(" ");
	move(mouseevent.y + 3, mouseevent.x - 3);
	printw(" ");
	move(mouseevent.y - 3, mouseevent.x + 3);
	printw(" ");
	move(mouseevent.y - 3, mouseevent.x - 3);
	printw(" ");
	refresh();
	usleep(100000);


}


void starburst(MEVENT mouseevent)
{
	move(mouseevent.y + 1, mouseevent.x);
	printw("*");
	move(mouseevent.y - 1 , mouseevent.x);
	printw("*");
	move(mouseevent.y, mouseevent.x + 1);
	printw("*");
	move(mouseevent.y, mouseevent.x - 1);
	printw("*");
	refresh();
	usleep(250000);

	move(mouseevent.y + 2, mouseevent.x);
	printw("@");
	move(mouseevent.y - 2 , mouseevent.x);
	printw("@");
	move(mouseevent.y, mouseevent.x + 2);
	printw("@");
	move(mouseevent.y, mouseevent.x - 2);
	printw("@");
	refresh();
	usleep(250000);

	move(mouseevent.y + 3, mouseevent.x);
	printw("v");
	move(mouseevent.y - 3 , mouseevent.x);
	printw("^");
	move(mouseevent.y, mouseevent.x + 3);
	printw(">");
	move(mouseevent.y, mouseevent.x - 3);
	printw("<");
	refresh();
	usleep(100000);


	move(mouseevent.y + 1, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 1 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 1);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 1);
	printw(" ");
	refresh();
	usleep(100000);

	move(mouseevent.y + 2, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 2 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 2);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 2);
	printw(" ");
	refresh();
	usleep(100000);

	move(mouseevent.y + 3, mouseevent.x);
	printw(" ");
	move(mouseevent.y - 3 , mouseevent.x);
	printw(" ");
	move(mouseevent.y, mouseevent.x + 3);
	printw(" ");
	move(mouseevent.y, mouseevent.x - 3);
	printw(" ");
	refresh();
	usleep(100000);
}
