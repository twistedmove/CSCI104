/*
 * listabstract.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef LISTABSTRACT_H_
#define LISTABSTRACT_H_

template <class T>
struct element {
	T item;
};

template <class T>
class List {
	public:
		List();
		~List();
		void insert (int pos, const T & item);
		/*  Inserts the item right before position pos, growing the list by 1.
		 *  pos must be between 0 and the current length of the list.
		 *  (The textbook returns a bool - feel free to do that.)
		 */
		void remove (int pos);
		/*  Removes the element at position pos, shrinking the list by 1.
		    pos must be between 0 and the current length of the list minus 1.
		 */
		void set (int pos, const T & item);
		/*  overwrites position pos in the list with item.
		 *  Does not change the length of the list.
		 *  pos must be between 0 and the current length of the list minus 1.
		 */
		T const & get (int pos) const;
		/*  returns the item at position pos, not changing the list.
		 *  pos must be between 0 and the current length of the list minus 1.
		 */
		void clear ();
		/*  deletes the list
		 */

	private:
		int _size;

};



#endif /* LISTABSTRACT_H_ */
