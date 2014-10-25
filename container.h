#ifndef EASY_CONTAINER_H
#define EASY_CONTAINER_H

/* 
 * The easiest container interface with only CRUD operation and
 * can only be used with int type
 */
class easy_container {
public:
	explicit easy_container() {}
	virtual ~easy_container() {}
	easy_container(const easy_container&) {}

	virtual void add(int value) = 0;
	virtual void remove(int pos) = 0;
	virtual void set(int pos, int value) = 0;
	virtual int pos(int value) = 0;
};

#endif // EASY_CONTAINER_H