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
