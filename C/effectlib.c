// This library shows the different effects I've built so far.
// They will come with requirements as needed.
#include <curses.h>
// Starburst: Takes a mouse event and prints a cute starburst at the event
// location. 
// Requires mousemask(EVENT_NAME).
// Recommends curs_set(0) so that the cursor is invisible.
void starburst(MEVENT mouseevent);
void firework(MEVENT mouseevent);

// Firework: Takes a mouse event and prints a cute firework at the event location.
// Requires mousemast (EVENT_NAME).
// Recommends curs_set(0) so that the cursor is invisible.
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
