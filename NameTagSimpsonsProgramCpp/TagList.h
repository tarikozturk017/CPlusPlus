#ifndef SDDS_TAGLIST_H
#define SDDS_TAGLIST_H

namespace sdds {

	class TagList {
		private:
			int counter = 0;
		public:
			int longestName;
			NameTag *nt = new NameTag[100];
			void set();
			void set(int num);
			void add(const NameTag& nt);
			void print();
			void cleanup();
			int getCounter() {
				return counter;
			}
			void increaseCounter() {
				counter++;
			}
			void emptyCounter() {
				counter = 0;
			}
	};

}


#endif