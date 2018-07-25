#include <curses.h>
#include <unistd.h>
#include <math.h>

void firework(MEVENT mouseevent);
void starburst(MEVENT mouseevent);
void launch(MEVENT mouseevent);

int main ()
{
	int ch, a, b;
	bool cont = true;
	initscr();
	clear();
	noecho();
	mousemask(BUTTON1_CLICKED, NULL);
	keypad(stdscr, TRUE);
	MEVENT mouseevent;
	// keypad(window, TRUE); Need this line with additional windows, per window
	printw("Click!\n");
	printw("Press F1 to leave.\n");
	refresh();
	curs_set(0);
	getmaxyx(stdscr, a, b);
	while (cont)
	{
		ch = getch();
		// If we detect F1,
		if ( ch == KEY_F(1) )
		{
			// Exit.
			cont = false;
		}
		// If we detect a mouse,
		else if ( ch == KEY_MOUSE )
		{
			// Check if we got the event okay.
			if ( getmouse(&mouseevent) == OK )
			{
				// getmouse returns the struct
				// {
				//   short id;        id of device
				//   int x, y, z;     coordinates
				//   mmask_t bstate;  button state bits
//				if( mouseevent.bstate & BUTTON1_CLICKED )
//				{
//					starburst(mouseevent);
//					refresh();
//					continue;
//				}
				if( mouseevent.bstate & BUTTON1_CLICKED )
				{
					launch(mouseevent);
					refresh();
					continue;
				}
			}
		}
	}
	endwin();
	return 0;
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
		usleep(50000);
	}

}


void clearlaunch(MEVENT mouseevent)
{


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
