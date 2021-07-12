#ifndef MYQUEUE_H
#define MYQUEUE_H

/* (ineffiziente) Warteschlange mit einer einfach verketteten Liste */
typedef struct queue {
	struct queue *next;
	char* value;
} queue;

extern queue *enter(queue *q, char *value); // Hinten einreihen
extern int is_empty(queue *q); // Test, ob leer
extern char *front(queue *q); // Vorderstes Element zurueckgeben
extern queue *leave(queue *q); // Vorderstes Element entfernen

#endif
